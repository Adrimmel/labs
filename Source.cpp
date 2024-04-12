#include<iostream>
#include<string>
#include<fstream>

#include"Header.h"


std::ostream& operator << (std::ostream& out, const Zootopia& r) {
	out << r.id << " " << r.name << " " << r.caught << " " << r.awards << " " << r.warns;
	return out;
}

void Zootopia::setId(int x) {
	id = x;
}

int Zootopia::getId() {
	return id;
}

std::string Zootopia::getName() {
	return name;
}

int Zootopia::getCaught() {
	return caught;
}

int Zootopia::getAwards() {
	return awards;
}

int Zootopia::getWarns() {
	return warns;
}

std::istream& operator >> (std::istream& in, Zootopia& z) {
	std::cout << "Enter name: ";
	std::string str;
	in >> str;
	int len = str.length();
	if (len <= 25) {
		for (int i = 0; i < len; i++) {
			z.name[i] = str[i];
		}
		for (int i = len; i < 40; i++) {
			z.name[i] = {};
		}
	}
	else
		for (int i = 0; i < 40; i++) {
			z.name[i] = str[i];
		}
	std::cout << "Prisoners were caught:";
	in >> z.caught;
	std::cout << "Amount of awards:";
	in >> z.awards;
	std::cout << "Amount of warns:";
	in >> z.warns;
	return in;
}



namespace database {
	void create(Zootopia* arr, int n) {
    std::ofstream out("data", std::ios_base::binary);
    if (!out.is_open()) {
        std::cout << "error" << std::endl;
        return;
    }
    
    out.write(reinterpret_cast<char*>(&n), sizeof(int));
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        arr[i].setId(i);
        out.write(reinterpret_cast<char*>(&arr[i]), sizeof(Zootopia));
    }
    
    out.close();
}

	void read(Zootopia** arr, int* n) {
		const int sizeOfInt = sizeof(int);
		const int sizeOfZootopia = sizeof(Zootopia);

		std::ifstream in("data", std::ios::binary);
		if (!in.is_open()) {
			std::cout << "error" << std::endl;
			return;
		}

		if (!in.read(reinterpret_cast<char*>(n), sizeOfInt)) {
			std::cout << "Failed to read the number of elements" << std::endl;
			return;
		}

		*arr = new Zootopia[*n];
		std::cout << *n << std::endl;

		for (int i = 0; i < *n; i++) {
			if (!in.read(reinterpret_cast<char*>(&(*arr)[i]), sizeOfZootopia)) {
				std::cout << "Fail " << i << std::endl;
				return;
			}
		}

		in.close();


}

	void search(Zootopia* arr, int n) {
		std::cout << "";
		int key = 1; 
		int x;
		std::cout << "ID (from 0): ";
		std::cin >> x;

		switch (key) {
		case 1:
			for (int i = 0; i < n; i++) {
				if (x == arr[i].getId())
					std::cout << arr[i] << std::endl;
			}
			break;
		}
	}

	void add(Zootopia* arr, int n) {
		if (n >= 2)
			arr[n - 1].setId(arr[n - 2].getId() + 1);
		else
			arr[n - 1].setId(0);
		std::cin >> arr[n - 1];
		std::ofstream out;
		out.open("data", std::ios_base::binary);
		if (!out.is_open()) {
			std::cout << "error" << std::endl;
			return;
		}
		out.write((char*)&n, sizeof(int));
		size_t size = sizeof(Zootopia);
		for (int i = 0; i < n; i++) {
			out.write((char*)&(arr[i]), size);
		}
		out.close();
		return;
	}

	void edit(Zootopia* arr, int n) {
		std::cout << "id=";
		int x;
		std::cin >> x;
		for (int i = 0; i < n; i++) {
			if (x == arr[i].getId()) {
				std::cin >> arr[i];
			}
		}
		std::ofstream out;
		out.open("data", std::ios_base::binary);
		if (!out.is_open()) {
			std::cout << "error" << std::endl;
			return;
		}
		out.write((char*)&n, sizeof(int));
		size_t size = sizeof(Zootopia);
		for (int i = 0; i < n; i++) {
			out.write((char*)&(arr[i]), size);
		}
		out.close();
		return;
	}

	void remove(Zootopia** arr, int* n) {
		std::cout << "Enter ID: ";
		int x = 0;
		int k = -1;
		std::cin >> x;
		for (int i = 0; i < *n; i++) {
			if ((*arr)[i].getId() == x) {
				k = i;
				break;
			}
		}
		if (k != -1) {
			*n -= 1;
			for (int i = k; i < *n; i++) {
				(*arr)[i] = (*arr)[i + 1];
			}

			std::ofstream out;
			out.open("data", std::ios_base::binary);
			if (!out.is_open()) {
				std::cout << "Error opening file." << std::endl;
				return;
			}

			out.write((char*)n, sizeof(int));
			size_t size = sizeof(Zootopia);
			out.write(reinterpret_cast<char*>(*arr), size * (*n));
			out.close();
		}
		else {
			std::cout << "Record with ID " << x << " not found." << std::endl;
		}
	}
}