#include<iostream>
#include"Header.h"
#include<fstream>


using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	bool execute = true;
	Zootopia* arr = NULL;

	int n = 0;
    while (execute) {
        cout << " Welcome to the Zootopia Police Department!\n"
            << " (1) Create database \n"
            << " (2) Read data\n"
            << " (3) Search stuff\n"
            << " (4) Add ZTPD personnel\n"
            << " (5) Edit stuff\n"
            << " (6) Delete ZTPD personnel\n"
            << " (7) Exit the database.\n"
            << "Your choice: ";

        int k = 0;
        cin >> k;
        switch (k) {
            int choice;
            Zootopia* arr = nullptr;
            int n = 0;

            do {
                std::cout << "Enter your choice (1-6): ";
                std::cin >> choice;

                switch (choice) {
                case 1:
                    std::cout << "Enter number of records: ";
                    std::cin >> n;
                    arr = new Zootopia[n];
                    database::create(arr, n);
                    break;

                case 2:
                    database::read(&arr, &n);
                    for (int i = 0; i < n; i++) {
                        std::cout << arr[i] << std::endl;
                    }
                    break;

                case 3:
                    database::read(&arr, &n);
                    database::search(arr, n);
                    break;

                case 4:
                    Zootopia * arr1 = nullptr;
                    if (arr == nullptr) {
                        database::read(&arr, &n);
                    }
                    arr1 = arr;
                    n += 1;
                    arr = new Zootopia[n];
                    for (int i = 0; i < n - 1; i++) {
                        arr[i] = arr1[i];
                    }
                    database::add(arr, n);
                    delete[] arr1;
                    break;

                case 5:
                    if (arr == nullptr) {
                        database::read(&arr, &n);
                    }
                    database::edit(arr, n);
                    break;

                case 6:
                    if (arr == nullptr) {
                        database::read(&arr, &n);
                    }
                    database::remove(&arr, &n);
                    break;

                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
                }

            } while (choice >= 1 && choice <= 6);

            if (arr != nullptr) {
                delete[] arr;

        case 7:
            execute = false;
            }
        }
    }
	system("cls");
}