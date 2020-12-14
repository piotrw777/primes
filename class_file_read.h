#ifndef __file_read
#define __file_read

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <chrono>

#define ull unsigned long long
using namespace std;
using namespace chrono;

//klasa do obsługi odczytu danych z pliku
//dane(liczby) powinny być oddzielone białymi znakami
class file_reader {

    friend class test;
    //składniki
    string file_name;
    ifstream file;
    vector<ull> data;
    int size = 0;
public:
    file_reader() {cout << "Domyślny konstruktor file_reader\n"; file_name = "UNKNOWN";};
    //konstruktor
    file_reader(const char * name) : file_name(name) {
        cout << "Otwieranie pliku z danymi...\n";
        file.open(name);
        if(file.is_open() == false) {
            cout << "Error opening the file\n";
            exit(1);
        }
        cout << "Zakonczono otwieranie pliku\n";
    }
    //konstruktor kopiujący
    /*
    file_reader(const file_reader &f) {
        cout << "Kto włączył konstruktor kopiujacy?";

    }
    */
    //destruktor
    ~file_reader() {file.close();};
    void read() {
        ull k;
        data.clear();
        cout << "Wczytywanie danych z pliku "<<file_name<<endl;
        while(file >> k) {
            data.push_back(k);
        }
        size = data.size();
        cout << "Zakonczono wczytywanie danych\n";
        cout << "Ilosc wczytanych liczb: " << size << endl;
    }
    ull operator[](int k) {
        return data[k];
    }
    void print() {
        for(auto & i : data) {cout << i <<" ";}
        cout << endl;
    }

};
struct arg{
    ull *left;
    ull *right;
};
class test {
    int nr_thr;
    string name;
    bool (*f)(ull n); //funkcja sprawdzająca pierwszość
    file_reader * plik;
    double time = 0;  //czas wykonania
    vector<ull> found_primes;
    arg *Args = nullptr; //tablica argumentów dla wątków

public:
    test(int nr_thr,string name, bool (*g)(ull n) , file_reader * plik_wsk) : nr_thr(nr_thr),name(name){
        f=g;plik = plik_wsk;
    };

    test(int nr_thr,const char name1[], bool (*g)(ull n) , file_reader *plik_wsk) : nr_thr(nr_thr),name(name1){
        f=g; plik = plik_wsk;
    };

    ~test() {delete [] Args;};

    void run(int nr_thr = 1, bool output_to_file = false) {
        int N = plik->size; // ilość wczytanych liczb
        int P = nr_thr;     // ilośc wątków

        cout << "Rozpoczynam test " << name << endl;

        auto start = steady_clock::now();
        for(const auto & i: plik->data) {
            if(f(i)) {
                found_primes.push_back(i);
            }
        }
        auto end = steady_clock::now();

        time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    }
    void resume() {
        cout << "Czas dzialania algorytmu " << name <<"(" << nr_thr <<"thr)"<< " wynosi: " << time << " msek. = " << time/1e3 <<" sek."<< endl;
        cout << "Znaleziono " << found_primes.size()<< " liczb pierwszych: " << found_primes;
    }
};
#endif// __file_read

//ull *pnts = v.data();
/*    auto start = chrono::steady_clock::now();

    // do some stuff here
    sleep(3);

    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in nanoseconds : "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;

    cout << "Elapsed time in microseconds : "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " µs" << endl;

    cout << "Elapsed time in milliseconds : "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;

    cout << "Elapsed time in seconds : "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec";
 */
