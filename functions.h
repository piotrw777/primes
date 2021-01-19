#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include <vector>

#define ull unsigned long long
using namespace std;

//k-ty bit liczby template
template <typename T>
bool bit(int k, T n)
{
    return ((1LL << k) & n) != 0;
}

template <typename T>
void print_bits(T t)
{
    for(int k = 0; k < sizeof(T)*8; ++k)
    {
        cout << bit(k, t);
    }
}

template <typename Typ>
void print(const vector<Typ>& V)
{
    for(const auto& i: V)
    {
        cout << i << " ";
    }
    cout << endl;
}

template <typename Typ>
ostream & operator<<(ostream & out,const vector<Typ>& V)
{
    for(const auto& i: V)
    {
        out << i << " ";
    }
    out << endl;
    return out;
}

template <typename T>
ull power(ull a, T k)
{
    int N = sizeof(T) * 8;
    ull wynik = 1;
    for(int i = N - 1; i >= 0; --i)
    {
        wynik *= wynik;
        if(bit(i, k) == 1) wynik *= a;
    }
    return wynik;
}
template <typename T>
ull powermod(ull a, T k, ull m)
{
    int N = sizeof(T) * 8;
    a %= m;
    ull wynik = 1;

    for(int i = N - 1; i >= 0; --i)
    {
        wynik = (wynik * wynik) % m;
        if(bit<ull>(i, k) == 1) wynik = (wynik * a) % m;
    }
    return wynik;
}

//funkcje testujące pierwszość
bool is_prime(ull n);
bool Miller_Rabin_test(ull n);
bool mpz_probab_prime(ull n);

//funkcje pomocnicze
ull ord(ull p, ull n);
ull powermod(ull a, ull k, ull n);

#endif // FUNCTIONS

