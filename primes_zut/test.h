#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>
#include "class_file_read.h"

using namespace std;
#define ull unsigned long long
struct arg
{
    ull *left;
    ull *right;
};

//********************************************************
class test
{
    int nr_thr;
    string name;
    bool (*f)(ull n); //funkcja sprawdzająca pierwszość
    file_reader * plik;
    double time = 0;  //czas wykonania
    vector<ull> found_primes;
    arg *Args = nullptr; //tablica argumentów dla wątków

public:
    test(int nr_thr,string name, bool (*g)(ull n), file_reader * plik_wsk) : nr_thr(nr_thr),name(name)
    {
        f=g;
        plik = plik_wsk;
    };

    test(int nr_thr,const char name1[], bool (*g)(ull n), file_reader *plik_wsk) : nr_thr(nr_thr),name(name1)
    {
        f=g;
        plik = plik_wsk;
    };

    ~test()
    {
        delete [] Args;
    };

    void run(int nr_thr = 1, bool output_to_file = false);
    void resume();
};

#endif // TEST_H
