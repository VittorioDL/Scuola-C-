#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct recPoint
{
    double x;
    double y;
};

struct recCircle
{
    recPoint centro;
    double raggio;
};

struct recLine
{
    double coefficienteAngolare;
    double intercetta;
};

recPoint puntoMedio2Punti(recPoint a, recPoint b)
{
    recPoint pMedio;

    pMedio.x = (a.x + b.x)/2;
    pMedio.y = (a.y + b.y)/2;
    return pMedio;
}

double distanza2Punti(recPoint a, recPoint b)
{
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

recLine rettaPassante2Punti(recPoint a, recPoint b)
{
    recLine retta;

    retta.coefficienteAngolare = (-b.y + a.y)/(a.x - b.x);
    retta.intercetta = (-retta.coefficienteAngolare * a.x) + a.y;
    return retta;
}

recCircle circonferenzaPassante3Punti(recPoint a, recPoint b, recPoint c)
{
    // Non so come implementare il sistema a 3 incognite
}

double distanzaRettaPunto(recPoint p, recLine retta)
{
    double distanza = abs(p.y - ((retta.coefficienteAngolare * p.x) + retta.intercetta)) / sqrt(1+pow(retta.coefficienteAngolare,2));
    return distanza;
}

int main()
{
    int risp;

    do
    {
        cout<<"1 ---> Punto medio tra due punti             "<<endl;
        cout<<"2 ---> Distanza tra due punti                "<<endl;
        cout<<"3 ---> Retta passante per due punti          "<<endl;
        cout<<"4 ---> Circonferenza passante per tre punti  "<<endl;
        cout<<"5 ---> Distanza tra una retta e un punto     "<<endl;
        cout<<"0 ---> Esci dal programma                    "<<endl;

        cout<<"\nSeleziona la funzione... ";
        cin>>risp;

        if(risp == 1)
        {
            recPoint p1, p2;

            cout<<"\nX del primo punto: ";
            cin>>p1.x;
            cout<<"Y del primo punto: ";
            cin>>p1.y;

            cout<<"\nX del secondo punto: ";
            cin>>p2.x;
            cout<<"Y del secondo punto: ";
            cin>>p2.y;

            recPoint pMedio = puntoMedio2Punti(p1, p2);
            cout<<"\nPunto medio --> X:"<<pMedio.x<<", Y:"<<pMedio.y<<endl<<endl;
        }

        if(risp == 2)
        {
            recPoint p1, p2;

            cout<<"\nX del primo punto: ";
            cin>>p1.x;
            cout<<"Y del primo punto: ";
            cin>>p1.y;

            cout<<"\nX del secondo punto: ";
            cin>>p2.x;
            cout<<"Y del secondo punto: ";
            cin>>p2.y;

            double distanza = distanza2Punti(p1, p2);
            cout<<"\nDistanza tra i due punti --> "<<distanza<<endl<<endl;
        }

        if(risp == 3)
        {
            recPoint p1, p2;

            cout<<"\nX del primo punto: ";
            cin>>p1.x;
            cout<<"Y del primo punto: ";
            cin>>p1.y;

            cout<<"\nX del secondo punto: ";
            cin>>p2.x;
            cout<<"Y del secondo punto: ";
            cin>>p2.y;

            recLine retta = rettaPassante2Punti(p1, p2);
            cout<<"\nCoefficiente angolare --> "<<retta.coefficienteAngolare<<endl;
            cout<<"Intercetta --> "<<retta.intercetta<<endl<<endl;
        }

        if(risp == 4) cout<<"\nError 404\n\n";

        if(risp == 5)
        {
            recPoint p1;
            recLine retta;

            cout<<"\nX del punto: ";
            cin>>p1.x;
            cout<<"Y del punto: ";
            cin>>p1.y;

            cout<<"\nCoefficiente angolare della retta: ";
            cin>>retta.coefficienteAngolare;
            cout<<"Intercetta della retta: ";
            cin>>retta.intercetta;

            double distanza = distanzaRettaPunto(p1, retta);
            cout<<"Distanza --> "<<distanza<<endl<<endl;

        }
    }
    while(risp != 0);

    return 0;
}
