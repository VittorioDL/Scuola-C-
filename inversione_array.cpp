#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void caricamento(int v[], int vals)
{
    for(int i = 1; i<= vals; i++) v[i] = (rand()%100)+1;
}

void visualizzazione(int v[], int vals)
{
    for(int i = 1; i <= vals; i++) cout<<"  "<<i<<"^ valore: "<<v[i]<<endl;
}

void scambio(int &a, int &b)
{
    int appo = a;
    a = b;
    b = appo;
}

void inversione(int v[], int vals)
{
    int x = vals;
    for(int i = 1; i <= vals/2; i++)
    {
        scambio(v[i], v[x]);
        x--;
    }

}

int main()
{
    srand((unsigned)time(NULL));

    int lista[21];

    caricamento(lista, 20);

    cout<<"Lista originale:"<<endl;
    visualizzazione(lista, 20);

    inversione(lista, 20);
    cout<<"\nLista invertita:"<<endl;
    visualizzazione(lista, 20);

    return 0;
}
