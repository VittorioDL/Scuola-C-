#include <iostream>
#include <ctime>
#include<stdlib.h>

using namespace std;

int Pari(int lista[], int vals, int listaPar[])
{
    int cont = 1;
    for(int i = 1; i <= vals; i++)
    {
        if((lista[i]%2) == 0)
        {
            listaPar[cont] = lista[i];
            cont++;
        }
    }
    return cont;
}

bool primi(int n)
{
    for(int i = 2; i < n; i++) if((n%i) == 0) return false;
    return true;
}

int Primi(int lista[], int vals, int listaPrimi[])
{
    int cont = 1;
    for(int i = 1; i <= vals; i++)
    {
        if(primi(lista[i]))
        {
            listaPrimi[cont] = lista[i];
            cont++;
        }
    }
    return cont;
}

int Dispari(int lista[], int vals, int listaDis[])
{
    int cont = 1;
    for(int i = 1; i <= vals; i++)
    {
        if(((lista[i]%2) != 0 )& (!primi(lista[i])))
        {
            listaDis[cont] = lista[i];
            cont++;
        }
    }
    return cont;
}

int main()
{
    srand((unsigned)time(NULL));
    int val, lista[101], listaPar[101], listaDis[101], listaPrimi[101] = {0};

    for(int i =1; i <= 100; i++) lista[i] = (rand()%1000)+1;

    cout<<"Lista completa: \n";
    for(int i =1; i <= 100; i++) cout<<i<<"^ valore: "<<lista[i]<<endl;


    cout<<"\nLista pari: \n";
    for(int i =1; i <= Pari(lista, 100, listaPar)-1; i++) cout<<i<<"^ valore: "<<listaPar[i]<<endl;

    cout<<"\nLista primi: \n";
    for(int i =1; i <= Primi(lista, 100, listaPrimi)-1; i++) cout<<i<<"^ valore: "<<listaPrimi[i]<<endl;

    cout<<"\nLista dispari: \n";
    for(int i =1; i <= Dispari(lista, 100, listaDis)-1; i++) cout<<i<<"^ valore: "<<listaDis[i]<<endl;

    return 0;
}
