#include "test.h"

void test::run(int nr_thr, bool output_to_file)
{
    int N = plik->size; // ilość wczytanych liczb
    int P = nr_thr;     // ilość wątków

    cout << "Rozpoczynam test " << name << endl;

    auto start = steady_clock::now();
    for(const auto & i: plik->data)
    {
        if(f(i))
        {
            found_primes.push_back(i);
        }
    }
    auto end = steady_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void test::resume()
{   auto stars = [](int ile){for(int k = 0; k < ile; k++){cout << '*';}cout << "\n\n";};
    stars(10);
    cout << "PODSUMOWANIE ALGORYTMU " << name << endl;
    cout << "Ilosc watkow: " << nr_thr << endl;
    cout << "Czas dzialania: " << time << " msek. " << time/1e3 << " sek." << endl;
    cout << "Znaleziono " << found_primes.size()<< " liczb pierwszych" << endl;
    cout <<  found_primes;
    stars(10);
}
