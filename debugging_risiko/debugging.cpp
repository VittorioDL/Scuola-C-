#include <iostream>
#include <ctime>
#include<stdlib.h>

using namespace std;


void lanciaDadi(int &a,int &b,int &c,int numerodadi)
{
    switch(numerodadi)
    {
        case 1:a=(rand()%6)+1;
               b=0;
               c=0;break;
        case 2:a=(rand()%6)+1;
               b=(rand()%6)+1;
               c=0;break;

        //Ho rimosso il case 3 che era superfluo

        default:a=(rand()%6)+1;
                b=(rand()%6)+1;
                c=(rand()%6)+1;break;
    }
}

void scambia(int&v1,int&v2)
{
    int temp=v1;
    v1=v2;
    v2=temp;
}

void ordinamento(int&v1,int&v2,int&v3)
{
    if(v1>v2)scambia(v1,v2);
    if(v1>v3)scambia(v1,v3);
    if(v2>v3)scambia(v2,v3);
}

int battaglia(int v1,int v2,int v3,int v4,int v5,int v6)
{
    int d=0;
    if ((v4!=0) & (v1!=0))
    if(v4<=v1)
    {
      d++;
    }
    if ((v5!=0) & (v2!=0))
    if(v5<=v2)
    {
      d++;
    }
    if ((v6!=0) & (v3!=0))
    if(v6<=v3)
    {
      d++;
    }
    return d;
}

int main()
{                                                                                 //Nuove variabili per il numero dadi
    int d1,d2,d3,d4,d5,d6,numeroDifesa,numeroAttacco,numero,nada,vittorie,nA, nD, dadiA = 3, dadiD = 3;
    double percentualeVittorie;
    srand((unsigned)time(NULL));
    cout<<"inserire il numero di armate per la difesa ";
    cin>>numeroDifesa;
    cout<<"inserire il numero di armate per l'attacco ";
    cin>>numeroAttacco;
    vittorie=0;
    for (int x=1; x<=1000; x++) //Ho cambiato la x da 0 a 1 e ho aggiunto = a <1000
    {
     nA=numeroAttacco; // Ho rinominato le variabili per evitare confusioni
     nD=numeroDifesa;
     do
     {
        if (nA<4)
        {
            lanciaDadi(d1,d2,d3,nD);
            lanciaDadi(d4,d5,d6,nA); // Ho rimosso -1 da (nA - 1)

            ordinamento(d1,d2,d3);
            ordinamento(d4,d5,d6);
        }
        else
        {
            lanciaDadi(d1,d2,d3,dadiD); // Si poteva mettere anche 3 ma ho messo dadiD e A per chiarezza
            lanciaDadi(d4,d5,d6,dadiA);

            ordinamento(d1,d2,d3);
            ordinamento(d4,d5,d6);
        }

        if(dadiD<=dadiA) //  Ho sostituito a nD e nA le due nuove variabili dadiD e dadiA
        {
            numero=dadiD;
        }
        else
        {
            numero=dadiA;
        }

        nada=battaglia(d1,d2,d3,d4,d5,d6); // nada = Numero Armate Distrutte Attacco
        nA=nA-nada;
        nD=nD-(numero-nada);

      } while ((nD>0) & (nA>1));

        if (nA > nD)
        {
            vittorie++;
        }
    }
    percentualeVittorie= vittorie/10;
    cout<<percentualeVittorie<<"% di vittoria";

    return 0;
}
