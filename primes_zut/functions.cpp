#include <iostream>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <climits>
#include "functions.h"
#include "time.h"

#define ull unsigned long long
using namespace std;

ull nwd(ull a, ull b)
{
    ull c;
    while(b)
    {
        c = a;
        a = b;
        b = c % b;
    }
    return a;
}

ull ord(ull p, ull n)
{
    ull wynik = 0;
    while(n % p == 0)
    {
        ++wynik;
        n /= p;
    }
    return wynik;
}

double drand(void)
{
    double d = rand()/(double) RAND_MAX;
    return d;
}

ull random_range(ull pocz, ull kon)
{
    ull k = (kon - pocz + 1) * drand() + pocz;
    return k;
}

bool Miller_Rabin_test(ull n)
{
    srand(time(0));

    if(n == 2 || n == 3 || n == 5) return true;
    if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 ) return false;
    if(n <= 6) return false;

    ull s = ord(2, n - 1);
    ull d = (n - 1) / power(2,s);
    ull a, b;
    bool probably_prime;
    const ull test_nr = 4;
    cout << "Testowana liczba: " << n << endl;
    for(size_t i = 0; i < test_nr; ++i)
    {
        do
        {
            a = random_range(2, min((unsigned int)n - 1, UINT_MAX));
            if(nwd(n,a) != 1) return false;
            cout << "Wybrano do testu liczbe " << a << endl;
            b = powermod<ull>(a, d, n);
        }
        while(b == 1);

        probably_prime = false;
        for(size_t j = 0; j < s; j++)
        {
            if(b == n - 1)
            {
                probably_prime=true;
                break;
            }
            b = (b * b) % n;
        }
        if(probably_prime == false) return false;
    }
    return true;
}

bool is_prime(ull n)
{
    //cout << "hello from is_prime!" << endl;
    if(n <= 1) return false;
    if(n == 2 || n == 3 || n == 5) return true;
    if( n % 2 == 0) return false;
    if( n % 3 == 0) return false;
    if( n % 5 == 0) return false;

    ull k_max = (ull) sqrt(n) + 1;
    ull k1 = 11;
    ull k2 = 7;
    while( (k1 < k_max) || (k2 < k_max) )
    {
        if((n % k1) == 0)
        {
            cout << "Liczba " << n <<" dzieli sie przez " << k1 << endl;
            return 0;
        }
        k1 += 6;
        if((n % k2) == 0)
        {
            cout << "Liczba " << n <<" dzieli sie przez " << k2 << endl;
            return 0;
        }
        k2 += 6;
    }
    return 1;
}

ull next_prime(ull n)
{
    if(n < 2) return 2;
    if(n == 2) return 3;

    ull k = n + 1 + n%2;

    while(is_prime(k) == 0)
    {
        k += 2;
    }
    return k;
}
