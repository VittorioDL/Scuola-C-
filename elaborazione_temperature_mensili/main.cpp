#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>

using namespace std;

int stagione(int giorno)
{
    /* 1. Inverno
       2. Primavera
       3. Estate
       4. Autunno */

    if((giorno >= 356) || (giorno < 80)) return 1;
    else if((giorno >= 80) || (giorno < 172)) return 2;
    else if((giorno >= 172) || (giorno < 266)) return 3;
    else /*((giorno >= 266) || (giorno < 356))*/ return 4;
}

int tempCasuale(int stagione, int giornoPrec)
{
    float temp;
    switch(stagione)
    {
        case 1: do{
                temp = (rand()%21) - 1;}
                while(fabs((giornoPrec-temp)) > 5);     //Inverno
                return temp; break;

        case 2: do{
                temp = (rand()%23) + 4;}
                while(fabs((giornoPrec-temp)) > 5);     //Primavera
                return temp; break;

        case 3: do{
                temp = (rand()%21) + 9;}
                while(fabs((giornoPrec-temp)) > 5);     //Estate
                return temp; break;

        case 4: do{
                temp = (rand()%21) + 4;}
                while(fabs((giornoPrec-temp)) > 5);     //Autunno
                return temp; break;
    }
}

void caricamentoAnno(int anno[])
{
    for(int i = 1; i <= 365; i++)
    {
        if(i > 1) anno[i] = tempCasuale(stagione(i), anno[i - 1]);
        else anno[1] = (rand()%21) - 1;
    }
}

void scambio(int &a, int &b)
{
    int ap = a;
    a = b;
    b = ap;
}

void ordinamento(int lista[])
{
    for(int i = 1; i <= 11; i++)
    {
        for(int j = i+1; j <= 12; j++)
        {
            if(lista[i] > lista[j]) scambio(lista[i], lista[j]);
        }
    }
}

void medieMesi(int listaMesi[], int anno[])
{
    int j = 1;
    int g = 1;
    for(int i = 1; i <= 12; i++)
    {
        if((i == 4) || (i == 6) || (i == 9) || (i == 11))
        {
            for(j = g; j <= (g + 29); j++) listaMesi[i] += anno[j];

            g = j;
            listaMesi[i] /= 30;
        }

        else if(i == 2)
        {
            for(j = g; j <= (g + 27); j++) listaMesi[i] += anno[j];

            g = j;
            listaMesi[i] /= 28;
        }

        else
        {
            for(j = g; j <= (g + 30); j++)  listaMesi[i] += anno[j];

            g = j;
            listaMesi[i] /= 31;
        }
    }
}

int cercaValore(int lista[], int valore)
{
    for(int i = 1; i <= 12; i++) if(lista[i] == valore) return i;
    return -1;
}

int main()
{
    srand((unsigned)time(NULL));

    int anno[366];
    int listaMedieMesi[13] = {0};

    caricamentoAnno(anno);
    medieMesi(listaMedieMesi, anno);

    cout<<"Medie:\n";
    for(int i = 1; i <= 12; i++) cout<<listaMedieMesi[i]<<endl;
    cout<<"\n";

    int listaOrdinata2[13];
    for(int i = 1; i <= 12; i++) listaOrdinata2[i] = listaMedieMesi[i];
    ordinamento(listaOrdinata2);

    int ind;
    for(int i = 1; i <= 12; i++)
    {
        ind = cercaValore(listaMedieMesi, listaOrdinata2[i]);
        if(ind != -1)
        {
            switch(ind)
            {
                case 1: cout<<"Gennaio: "; break;
                case 2: cout<<"Febbraio: "; break;
                case 3: cout<<"Marzo: "; break;
                case 4: cout<<"Aprile: "; break;
                case 5: cout<<"Maggio: "; break;
                case 6: cout<<"Giugno: "; break;
                case 7: cout<<"Luglio: "; break;
                case 8: cout<<"Agosto: "; break;
                case 9: cout<<"Settembre: "; break;
                case 10: cout<<"Ottobre: "; break;
                case 11: cout<<"Novembre: "; break;
                case 12: cout<<"Dicembre: "; break;
            }
            cout<<listaOrdinata2[i]<<endl;
            listaMedieMesi[ind] = 33;
        }
    }
    return 0;
}
