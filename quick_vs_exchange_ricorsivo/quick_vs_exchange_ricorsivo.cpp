#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <chrono>

using namespace std;

void insertion_sort(int a[], int n)
{
     int valore = 0;
     int j = 0;
     if(n > 1)
     {
        insertion_sort(a, n-1);
        valore = a[n-1];
        j = n-2;
        while((j >= 0) && (a[j] > valore))
        {
            a[j + 1] = a[j];
            j = j-1;
        }

        a[j+1] = valore;
     }
}


void quick_sort(int v[], int inf, int sup)
{
    int s, i, p, t;

    if(inf < sup)
    {
        i = inf;
        s = sup;
        p = v[sup];
        do
        {
            while((i < s) && (v[i] <= p))
                i++;
            while((s > i) && (v[s] >= p))
                s--;

            if(i < s)
            {
                t = v[i];
                v[i] = v[s];
                v[s] = t;
            }
        }while(i < s);
        t = v[i];
        v[i] = v[sup];
        v[sup] = t;
        quick_sort(v, inf, i-1);
        quick_sort(v, i+1, sup);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int n = 10000;
    int a1[n], a2[n];

    for(int i = 0; i < n; i++) a1[i] = (rand()%100000)+1;
    for(int i = 0; i <= n; i++) a2[i] = a1[i];

    //QUICKSORT
    // Inizio misurazione
    auto inizio = std::chrono::steady_clock::now();

    quick_sort(a1, 0, n-1);
    // Fine misurazione
    auto fine = std::chrono::steady_clock::now();

    double diff = double (std::chrono::duration_cast <std::chrono::nanoseconds> (fine - inizio).count());

    cout<<"\nTempo impiegato quick sort (ms): "<<diff/1000000<<endl;
    //system("pause;");


    //INSERTION SORT
    // Inizio misurazione
    auto inizio1 = std::chrono::steady_clock::now();

    insertion_sort(a2, n);
    // Fine misurazione
    auto fine1 = std::chrono::steady_clock::now();

    double diff1 = double (std::chrono::duration_cast <std::chrono::nanoseconds> (fine1 - inizio1).count());

    cout<<"\nTempo impiegato insertion sort (ms): "<<diff1/1000000<<endl;

    return 0;
}
