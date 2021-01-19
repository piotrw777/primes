#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <climits>

#include "functions.h"
#include "class_file_read.h"
#include "test.h"

using namespace std;

//Zadanie primes
//Piotr Wasilewski
void greet(int k, string &message) {
    cout << "I'm thread nr " << k << endl;
    cout << message << endl;
    
}
int main(int argc, char * argv[]) {
    const int P = 4; //liczba wątków
    const ull N = UINT_MAX;  //maksymalna liczba, która mo¿na podnieœc do kwadratu w zakresie zmiannej unsigned long long
    
    thread w = thread(greet, 1, "Hello");
      
    string liczby;
    cout << "Podaj nazwe pliku z liczbami: ";
    cin >> liczby;
    //lub
    //file_reader f(argv[1]);
    file_reader f(liczby);
    f.read();
    f.print();
    test t1(2,"TRIAL DIVISORS", is_prime, &f);
    //test t2(1, "Test Millera-Rabina", Miller_Rabin_test, &f);

    t1.run();
    //t2.run();
    t1.resume();
    //t2.resume();

}
