//main.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <pthread.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <climits>

#include "functions.h"
#include "class_file_read.h"

using namespace std;

//Zadanie primes
//Piotr Wasilewski

int main(int argc, char * argv[]) {
    const int P = 4; //liczba wątków
    const ull N = UINT_MAX;  //maksymalna liczba, która można podnieśc do kwadratu w zakresie zmiannej unsigned long long

    file_reader f(argv[1]);
    f.read();
    f.print();

    //cout << f[3];
/*
    cout << ULONG_LONG_MAX - N * N << endl;
    cout << INT_MAX << endl;
    cout << UINT_MAX << endl;
    cout << LONG_LONG_MAX << endl;
    cout << ULONG_LONG_MAX << endl;
    cout << (ull) UINT_MAX * (ull)UINT_MAX;

*/
    test t1(1,"TRIAL DIVISORS", is_prime, &f);
    test t2(2, "TRIAL DIVISORS", is_prime, &f);

    t1.run();
    t1.resume();



}
