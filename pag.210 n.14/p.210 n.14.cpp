#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void caricamento(int lista[], int vals)
{
    for(int i = 1; i <= vals; i++) lista[i] = (rand()%100)+1;
}

void scambio(int &n1, int &n2)
{
    int a = n1;
    n1 = n2;
    n2 = a;
}

void bubble_sort(int lista[], int vals, int &scambi, int &confronti)
{
    for(int i = 1; i <= vals-1; i++)
    {
         for(int j = 1; j <= vals-i; j++)
         {
            confronti++;
            if(lista[j] > lista[j+1])
            {
                scambi++;
                //scambio(lista[j], lista[j+1]);
            }
         }
    }
}

void exchange_sort(int lista[], int vals, int &scambi, int &confronti)
{
    for(int i = 1; i <= vals - 1; i++)
    {
        for(int j = i + 1; j <= vals; j++)
        {
            confronti++;
            if(lista[i] > lista[j])
            {
                scambi++;
                //scambio(lista[i], lista[j]);
            }
        }
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int vals;
    cout<<"Inserire il numero di elementi della lista: ";
    cin>>vals;
    int lista[vals];
    caricamento(lista, vals);

    int scambiE = 0, confrontiE = 0;
    int scambiB = 0, confrontiB = 0;

    //cout<<"\nLista non ordinata:\n";
    //for(int i = 1; i <= vals; i++) cout<<lista[i]<<" ";

    exchange_sort(lista, vals, scambiE, confrontiE);
    cout<<"\nConfronti exchange sort: "<<confrontiE<<endl;
    cout<<"Scambi exchange sort: "<<scambiE<<endl;

    bubble_sort(lista, vals, scambiB, confrontiB);
    cout<<"\nConfronti bubble sort: "<<confrontiB<<endl;
    cout<<"Scambi bubble sort: "<<scambiB<<endl;

    //cout<<"\nLista ordinata: \n";
    //for(int i = 1; i <= vals; i++) cout<<lista[i]<<" ";

    return 0;
}
