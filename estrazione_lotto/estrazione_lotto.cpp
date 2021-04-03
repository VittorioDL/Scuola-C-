#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void caricamento(int estrazioni[], int vals)
{
    int indice = 10;
    int num, lista[indice + 1];

    for (int i=1;i<=indice ;i++)
    {
        lista[i] = i;
    }

	for (int i=1;i<=vals ;i++)
    {
        num = (rand()%indice)+1;
        estrazioni[i] = lista[num];

        for (i = num; i < indice ; i++)
        {
            lista[i] = lista[i + 1];
        }
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int estrazioni[7];
    int vals, lista[11];

    cout<<"Inserire numero di valori casuali: "<<endl;
    cin>>vals;

    caricamento(estrazioni, 6);

    for (int i=1;i<=vals ;i++)
    {
        cout<<estrazioni[i]<<" ";
    }
    return 0;
}
