#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void caricamento(int v[], int vals)
{
    for(int i = 1; i <= vals; i++) v[i] = (rand()%500)+1;
}

void scambio(int &a, int &b)
{
    int appo = b;
    b = a;
    a = appo;
}

void ordinamento(int v[], int vals)
{
    for(int i = 1; i <= vals - 1; i++)
    {
        for(int j = i+1; j <= vals; j++)
        {
            if(v[i] > v[j]) scambio(v[i], v[j]);
        }
    }
}

void visualizzazione(int v[], int vals)
{
    for(int i = 1; i <= vals; i++) cout<<"  Valore "<<i<<": "<<v[i]<<endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int lista1[101], lista2[0], x = 1;

    caricamento(lista1, 101);


    for(int i = 1; i <= 100; i++)
    {
        if((lista1[i]%2) == 0)
        {
            lista1[x] = lista2[i];
            x++;
        }
    }

    cout<<"Lista non ordinata:\n";
    visualizzazione(lista2, x);
    ordinamento(lista2, x);
    cout<<"\nLista ordinata:\n";
    visualizzazione(lista2, x);

    return 0;
}
