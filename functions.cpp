#include <iostream>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include "functions.h"


//#include <stdio.h>
//#include <stdlib.h>
//#include <cstdlib>
//#include <string.h>
#define ull unsigned long long
using namespace std;

double drand(void) {
    double d = rand()/(double) RAND_MAX;
    return d;

}

ull random_range(ull pocz, ull kon)  {
     ull k = (kon - pocz + 1) * drand() + pocz;
     return k;
}

long long suma_elem(int tab[], int rozmiar) {
    long long suma = 0;
    int k;
    for(k = 0; k < rozmiar; k++) {
        suma += tab[k];
    }
    return suma;
}
/*
void *threadFunction(void * arg) {
    args * wsk = (args *) arg;

    ull n = wsk->liczba;
    ull max_d = wsk->max_d;
    int thread_nr = wsk->thread_nr;
    int start = wsk->start;
    int step = wsk->step;
    pthread_t *w = wsk->w;
    int result = 0;

    for(ull k = start; k < max_d; k += step) {
        sleep(1);
        //printf("Jestem wątkiem nr %d i sprawdzam dzielnik %llu\n", thread_nr, k);
        //mamy dzielnik - liczba jest złożona
        if(n % k == 0) {
            //printf("\nKomunikat od wątku %d: Liczba %llu dzieli się przez %llu\n", thread_nr,n, k);
            result = -7777;
            //zamykamy wątki
            for(int j = 0; j < M; j++) {
                if(j != k) pthread_cancel(w[j]);
            }
            pthread_exit( (void *) result);
        }
    }   //end for
    //liczba przeszła testy - jest pierwsza
    result = 1;
    pthread_exit( (void *) result);

}   //end threadFunction
*/
bool is_prime(ull n) {
    //cout << "hello from is_prime!" << endl;
    if(n <= 1) return false;
    if(n == 2 || n == 3 || n == 5) return true;
    if( n % 2 == 0) return false;
    if( n % 3 == 0) return false;
    if( n % 5 == 0) return false;

	ull k_max = (ull) sqrt(n) + 1;
	ull k1 = 11;
    ull k2 = 7;
	while( (k1 < k_max) || (k2 < k_max) ) {
		if((n % k1) == 0) {
            cout << "Liczba " << n <<" dzieli się przez " << k1 << endl;
			return 0;
		}
		k1 += 6;
		if((n % k2) == 0) {
            cout << "Liczba " << n <<" dzieli się przez " << k2 << endl;
			return 0;
		}
		k2 += 6;
	}
	return 1;
}
/*
bool is_prime_thr(ull n) {

    if(n <= 1) return false;
    if(n == 2 || n == 3 || n == 5) return true;
    if( n % 2 == 0) return false;
    if( n % 3 == 0) return false;
    if( n % 5 == 0) return false;

    pthread_t Threads[M]; //wątki
    int Results[M];       //wyniki zwracane przez wątki
    int Ret[M];
    memset(Results, 0, M * sizeof(* Results) );
    args Args_thr[M];  //argumenty dla wątków

    int ret;
    const int Start[M] = {13,17,7,11};
    //wypełnienie tablicy argumentów dla wątków
    for(int k = 0; k < M; k++) {
        args pom = {n, (ull) sqrt(n) + 1, k, Start[k], STEP, Threads};
        Args_thr[k] = pom;
    }
    //printf("Rezultaty zwrócone przez wątki: (przed join)");
    //wyswietl(Results, M);
    //tworzenie wątków
    for(int k = 0; k < M; k++) {
        Ret[M] = pthread_create(&Threads[k], NULL, &threadFunction, &Args_thr[k]);
        if(Ret[M] != 0) {
            printf("Błąd wątku %d", k);
            exit(-1);
        }
    }
    //czekamy na wątki
    for(int k = 0; k < M; k++) {
        pthread_join(Threads[k], (void *) &Results[k]);
    }

    //printf("Rezultaty zwrócone przez wątki: ");
    //wyswietl(Results, M);
    int suma_results = suma_elem(Results, M);
    if(suma_results ==  M) {
        return true;
    }
    else if(suma_results < 0) {
        return false;
    }
    else {
        perror("Błąd funkckcji is_prime");
    }
}
*/
ull next_prime(ull n) {
	if(n < 2) return 2;
	if(n == 2) return 3;

	ull k = n + 1 + n%2;

	while(is_prime(k) == 0) {
		k += 2;
	}
	return k;
}
