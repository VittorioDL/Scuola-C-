#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void caricamento(int v[], int vals)
{
    for(int i = 1; i<= vals; i++) v[i] = (rand()%100)+1;
}

bool cercaValore(int v[],int vals, int valore)
{
    int x = 0;
    for(int i = 1; i <= vals; i++)
    {
        if(v[i] == valore) x++;
    }
    if(x>1) return true;
    else return false;
}
int main()
{
    srand((unsigned)time(NULL));

    int lista[21], x = 0;
    caricamento(lista, 20);

    for(int i = 1; i <= 20; i++)
    {
        if(cercaValore(lista, 20, i))
        {
            cout<<"Il valore "<<i<<" e' presente piu' di una volta"<<endl;
            x++;
        }

    }
    if(x == 0) cout<<"Non ci sono duplicati";

    return 0;
}
