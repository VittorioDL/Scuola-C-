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
        case 3:a=(rand()%6)+1;
               b=(rand()%6)+1;
               c=(rand()%6)+1;
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
    if (v4!=0 & v1!=0)
    if(v4<=v1)
    {
      d++;
    }
    if (v5!=0 & v2!=0)
    if(v5<=v2)
    {
      d++;
    }
    if (v6!=0 & v3!=0)
    if(v6<=v3)
    {
      d++;
    }
    return d;
}

int main()
{
    int d1,d2,d3,d4,d5,d6 ,numeroDifesa,numeroAttacco,numero,numeroAAT, numeroADT,numeroAA, numeroAD;
    float vincite = 0;
    srand((unsigned)time(NULL));

    cout<<"Inserire il numero di armate in attacco: ";
    cin>>numeroAAT;
    cout<<"Inserire il numero di armate in difesa: ";
    cin>>numeroADT;

    for(int x = 1; x <= 1000; x++)
    {
        numeroAA = numeroAAT ;
        numeroAD = numeroADT;

        do
        {
            if(numeroAA < 4) numeroAttacco = numeroAA ;
            else numeroAttacco = 3;

            if(numeroAD < 4) numeroDifesa = numeroAD;
            else numeroDifesa = 3;

            lanciaDadi(d1,d2,d3,numeroDifesa);
            lanciaDadi(d4,d5,d6,numeroAttacco);

            ordinamento(d1,d2,d3);
            ordinamento(d4,d5,d6);

            if(numeroDifesa<=numeroAttacco) numero=numeroDifesa;

            else numero=numeroAttacco;

            numeroAA = numeroAA - battaglia(d1,d2,d3,d4,d5,d6);
            numeroAD = numeroAD - (numero - battaglia(d1,d2,d3,d4,d5,d6));

        } while((numeroAA > 0) & (numeroAD > 0));
        if(numeroAA > numeroAD) vincite++;
    }
    cout<<"\nProbabilita' di conquista attacco: "<<vincite/10<<"%"<<endl;
    return 0;
}
