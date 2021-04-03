#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void caricamentoNum(int v[], int vals)
{
    for(int i = 1; i <= vals; i++)
    {
        v[i] = i;
    }
}

int cercaValore(int v[], int vals, int valoreDaCercare)
{
	for(int i=1; i<=vals; i++)
	{
		if(v[i]==valoreDaCercare)
		{
		    return i;
		}
	}
	return -1;
}

void caricamento5num(int v[], int vals, int listaTot[])
{
    int range = 1, num;
    for(int i = 1; i <= vals; i++)
    {
        do
        {
            num = (rand()%9)+range;
        }
        while(cercaValore(listaTot,90,num) != -1);
        v[i] = num;
        listaTot[num+1] = num;
        range += 10;
    }
}

void caricamento5pos(int v[], int vals)
{
    int num;
    for(int i = 1; i <= vals; i++)
    {
        num = (rand()%9)+1;
        if(i != 1)
        {
            do
            {
                num = (rand()%9)+1;

            }
            while(cercaValore(v,9,num) != -1);

        }
        v[i] = num;
    }
}

void visualizzazione(int v[], int vals)
{
    for(int l = 1; l <= vals; l++)
    {
        if(v[l] < 10) cout<<" ";
        cout<<" "<<v[l]<<" ";
    }
}

void azzeratore(int v[], int vals)
{
    for(int i = 1; i<= vals; i++) v[i] = 0;
}


int main()
{
    srand((unsigned)time(NULL));
                                                                                 //-10 e' un valore qualunque negativo
    int lista[10] = {0}, listaPos[6], listaRand[10], numCartelle, listaTot[91] = {-10};

    /*
        LEGENDA VARIABILI:
        -lista: Contiene i 9 valori di una riga della cartella
        -listaRand: Contiene i 5 valori casuali di una riga della cartella
        -listaPos: Contiene i le 5 posizioni in cui mettere i valori casuali di listaRand
        -listaTot: Contiene tutti i valori casuali inseriti, per evitare ripetizioni
    */

    cout<<"Inserire il numero di cartelle: ";
    cin>>numCartelle;

    for(int i = 1; i <= numCartelle; i++)
    {
        cout<<"\n"<<i<<"^ cartella:\n";
        for(int j = 1; j <= 3; j++)
        {
            caricamento5num(listaRand, 9, listaTot);
            caricamento5pos(listaPos, 5);
            for(int i = 1; i <= 5; i++)
            {
                int ind;
                ind = listaPos[i];
                lista[ind] = listaRand[ind];
            }
            visualizzazione(lista, 9);
            cout<<"\n";
            azzeratore(lista, 10);
            azzeratore(listaPos, 10);
            azzeratore(listaRand, 10);

        }
        azzeratore(listaTot, 90);
    }
    return 0;
}
