#ifndef __file_read
#define __file_read

#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <chrono>

#define ull unsigned long long
using namespace std;
using namespace chrono;

//klasa do obsługi odczytu danych z pliku
//dane(liczby) powinny być oddzielone białymi znakami

//********************************************************
class file_reader
{
    friend class test;

    string file_name;
    ifstream file;
    vector<ull> data;
    int size = 0;
public:
    file_reader() { file_name = "UNKNOWN"; };
    file_reader(const char * name);
    file_reader(string str);
    ~file_reader() { file.close(); };

    void read();
    void print();
    ull operator[](int k) { return data[k]; }
};
//**********************************************************

#endif// __file_read


