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
    vector<ull> found_primes;
    arg *Args = nullptr; //tablica argumentów dla wątków
    
    void fill_Args_array()
    {
        const int N = plik->size;
        const int P = nr_thr;
        int reszta = N % P;
        int rozmiar = N/P;
        ull * vec_begin = (plik->data).data();
        
        Args = new arg[P];
        for(int k = 0; k < P; k++)
        {
            Args[k].which_thr = k + 1;
            Args[k].left = vec_begin 
            Args[k].right = vec_begin
        }
     
        
        
        
    }
    void thr_fun(arg argument, vector<ull> &found_primes_thr) 
    {
        #if(thread_comments == 1)
            cout << "Watek nr " << argument.which_thr << 
            "sprawdza liczby od " << *argument.left << " do "
            << *argument.right << endl;
        #endif
        for(ull *i = argument.left; i != argument.right; i++)
        {
            if(f(*i))
            {
                #if(thread_comments == 1)
                    cout << "Watek nr " << argument.which_thr << 
                    "znalazl liczbe pierwsza " << *i << endl;
                #endif
                found_primes_thr.push_back(*i);
            }
        }
    }

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
