#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "class_file_read.h"

#define thread_comments 1
#define ull unsigned long long

using namespace std;

struct arg
{
    ull* left;
    ull* right;
    int which_thr;
};

//********************************************************
class test
{
    
    int nr_thr;
    string name;
    bool (*f)(ull n); //funkcja sprawdzająca pierwszość
    file_reader * plik;
    double time = 0;  //czas wykonania
    vector<vector<ull> > found_primes;
    arg *Args = nullptr; //tablica argumentów dla wątków
    
    void fill_Args_array();

public:
    test(int nr_thr,string name, bool (*g)(ull n), file_reader * plik_wsk) : nr_thr(nr_thr),name(name)
    {
        f=g;
        plik = plik_wsk;
        vector<ull> empty(-777,1) = ;
        for(int k = 0; k <= nr_thr; k++) {
            found_primes.push_back(empty);
        }
    };

    test(int nr_thr,const char name1[], bool (*g)(ull n), file_reader *plik_wsk) : nr_thr(nr_thr),name(name1)
    {
        f=g;
        plik = plik_wsk;
        vector<ull> empty;
        for(int k = 0; k <= nr_thr; k++) {
            found_primes.push_back(empty);
        }
    };

    ~test()
    {
        delete [] Args;
    };

    void run(int nr_thr = 1, bool output_to_file = false);
    void resume();
};

#endif // TEST_H
