//functions.h

#include <iostream>
#include <vector>

#define ull unsigned long long
using namespace std;

template <typename Typ>
void print(const vector<Typ>& V) {
    for(const auto& i: V) {cout << i << " ";}
    cout << endl;
}

template <typename Typ>
ostream & operator<<(ostream & out,const vector<Typ>& V) {
    for(const auto& i: V) {out << i << " ";}
    out << endl;
    return out;
}

//funkcje testujące pierwszość
bool is_prime(ull n);
bool Miller_Rabin_test(ull n);
bool mpz_probab_prime(ull n);

//funkcje pomocnicze
ull ord(ull p, ull n);
ull powermod(ull a, ull k, ull n);
