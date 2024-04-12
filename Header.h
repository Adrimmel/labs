#pragma once

#include <iostream>
#include <string>

class Zootopia {
private:
    unsigned int id;
    char name[25] = {};
    unsigned int caught = { 0 };
    unsigned int awards = { 0 };
    unsigned int warns = { 0 };

public:
   
    void setId(int x);
    std::string getName();
    int getId();
    int getCaught();
    int getAwards();
    int getWarns();


    friend std::istream& operator>>(std::istream& in, Zootopia& z);
    friend std::ostream& operator<<(std::ostream& out, const Zootopia& z);
};

namespace database {

    void create(Zootopia* arr, int n);
    void read(Zootopia** arr, int* n);
    void add(Zootopia* arr, int n);
    void edit(Zootopia* arr, int n);
    void search(Zootopia* arr, int n);
    void remove(Zootopia** arr, int* n);
}