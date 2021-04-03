#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>

using namespace std;

void caricamento(int lista[], int vals)
{
    for(int i = 1; i<= vals; i++) lista[i] = (rand()%1000)+1;
}

void scambia(int &n1, int &n2)
{
    int a = n1;
    n1 = n2;
    n2 = a;
}

void ordinamento(int lista[], int vals)
{
    for(int i = 1; i<= vals-1; i++)
    {
        for(int j = i + 1; j<= vals; j++)
        {
            if(lista[i] > lista[j]) scambia(lista[i], lista[j]);
        }
    }
}

bool ricercaBinaria(int lista[], int vals, int valDaCercare, int iter)
{
    int Max = vals;
    int Min = 1;
    int ind;

    for(int i = 1; i <= iter+1; i++)
    {
        ind = ceil(((Max + Min)/2)+0.1);

        if(lista[ind] == valDaCercare) return true;

        if(lista[ind] > valDaCercare) Max = ind;

        if(lista[ind] < valDaCercare) Min = ind;
    }
    return false;
}

int main()
{
    srand((unsigned)time(NULL));
    int vals = 500;
    int lista[vals];
    int valTrov = 0;
    int valDaCercare;
    int iter = floor(log2(vals)) + 1;

    caricamento(lista, vals);
    ordinamento(lista, vals);

    while(valTrov != 3)
    {
        cout<<"\n\nInserire un valore da cercare: ";
        cin>>valDaCercare;
        if(ricercaBinaria(lista, vals, valDaCercare, iter))
        {
            cout<<"\nIl valore e' presente!";
            valTrov++;
        }
        else cout<<"\nIl valore non e' presente...";
    }
    return 0;
}
