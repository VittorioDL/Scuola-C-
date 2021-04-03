#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>

using namespace std;

void caricamentoCodStud(int codiciStud[], int nStud, int nVoti)
{
    for(int i = 1; i <= nVoti; i++) codiciStud[i] = (rand()%nStud)+1;
}

void caricamentoVotiStud(int votiStud[], int nVoti)
{
    for(int i = 1; i <= nVoti; i++) votiStud[i] = (rand()%10)+1;
}

int contaVotiStud(int lista[], int vals, int stud)
{
    int tot = 0;
    for(int i = 1; i <= vals; i++)
    {
        if(lista[i] == stud) tot++;
    }
    return tot;
}

int cercaVal(int lista[], int vals, int valDaCercare)
{
    for(int i = 1; i <= vals; i++)
    {
        if(lista[i] == valDaCercare)
        {
            lista[i] = 0;
            return i;
        }
    }
    return -1;
}


int main()
{
    srand((unsigned)time(NULL));

    int nStud = 16;
    int nVoti = 10;

    int codiciStud[nVoti+1];
    int votiStud[nVoti+1];

    caricamentoCodStud(codiciStud, nStud, nVoti);
    caricamentoVotiStud(votiStud, nVoti);

    cout<<"Codici studenti random: \n";
    for(int i = 1; i <= nVoti; i++) cout<<codiciStud[i]<<"\n";

    cout<<"\nVoti random: \n";
    for(int i = 1; i <= nVoti; i++) cout<<votiStud[i]<<"\n";

    int stud;

    cout<<"\nInserire il codice dello studente di cui vuoi sapere la media: ";
    cin>>stud;

    float sommaVoti = 0;
    int ind = 0;

    float nVotiStud = contaVotiStud(codiciStud, nVoti, stud);

    for(int i = 1; i <= nVotiStud; i++)
    {
        ind = cercaVal(codiciStud, nVoti, stud);
        sommaVoti += votiStud[ind];
    }

    float media = sommaVoti/nVotiStud;
    cout<<"Media alunno "<<stud<<" : "<<media;

    return 0;
}
