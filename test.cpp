#include "test.h"
#include <thread>

    void test::fill_Args_array()
    {
        const int N = plik->size;
        const int P = nr_thr;
        int reszta = N % P;
        int rozmiar = N/P;
        ull * vec_begin = (plik->data).data();
        
        Args = new arg[P + 1];
        Args[0].left = vec_begin;
        Args[0].right = vec_begin;
        for(int k = 1; k <= P; k++)
        {
            Args[k].which_thr = k;
            Args[k].left = Args[k-1].right;
            Args[k].right = Args[k].left + rozmiar + (k <= reszta);
        }      
    }
    void thr_fun(arg argument, vector<vector<ull> > &found_primes, bool (*f)(ull n) ) 
    {
        cout << "HELLO!!!\n";
        int k = argument.which_thr;
        #if(thread_comments == 1)
            cout << "Watek nr " << k << 
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
                found_primes[k].push_back(*i);
            }
        }
    }
void test::run(int nr_thr, bool output_to_file)
{
    int N = plik->size; // ilość wczytanych liczb
    int P = nr_thr;     // ilość wątków

    cout << "Rozpoczynam test " << name << endl;
    cout << "Tworzenie tablicy argumentow dla watkow" << endl;
    
    this->fill_Args_array();

    auto start = steady_clock::now();
    //jeden watek
    if(P == 1)
    {
        for(const auto & i: plik->data)
        {
            if(f(i))
            {
                found_primes[1].push_back(i);
            }
        }
    }
    else
    {   //1 liczba = 1 watek (N watkow)
        if(N >= P)
        {
            vector<thread> threads;
            for(int k = 1; k <= N; k++)
            {
               threads.push_back(thread(thr_fun, Args[k], ref(found_primes), f));
            }
            for(int k = 0; k < N; k++)
            {
                threads[k].join();
            }

        }

        //rozdzielamy zbior liczb na watki
        else
        {
            
            
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
    for(int k = 0; k < nr_thr; k++) {
        cout << "Watek nr " << k + 1 << " znalazl " << found_primes[k+1].size() << " liczb pierwszych" << endl;
        cout <<  found_primes[k+1];
    }
   
    stars(10);
}
