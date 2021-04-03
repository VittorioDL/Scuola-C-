#include <iostream>

using namespace std;

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

void caricamento(int lista[], int num)
{
    for(int i = 1; i <= num; i++)
    {
        cout<<"Inserire un valore: ";
        cin>>lista[i];
    }
}

void unione(int lista1[], int vals1, int lista2[], int vals2, int lista3[])
{
    for(int i = 1; i <= vals1; i++) lista3[i] = lista1[i];

    for(int i = 1; i <= vals2; i++) lista3[i + vals1] = lista2[i];
}


int main()
{
    int num1;
    cout<<"Inserire la lunghezza del primo array: ";
    cin>>num1;
    int lista1[num1];
    caricamento(lista1, num1);


    int num2;
    cout<<"\nInserire la lunghezza del secondo array: ";
    cin>>num2;
    int lista2[num2];
    caricamento(lista2, num2);

    int lista3[num1+num2+1];

    unione(lista1, num1, lista2, num2, lista3);
    ordinamento(lista3, num1+num2);

    cout<<"\nLista unita e ordinata: \n";
    for(int i = 1; i <= num1+num2; i++) cout<<lista3[i]<<" ";

    return 0;
}
