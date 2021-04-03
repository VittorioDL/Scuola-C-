#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void scambio(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

bool vincitore(int a, int d)
{
    if(a > d) return false;
    if(a <= d) return true;
}

void ordinamento(int &v1, int &v2, int &v3)
{
    if(v1 > v2) scambio(v1, v2);
    if(v2 > v3) scambio(v2, v3);
    if(v1 > v2) scambio(v1, v2);
}

int main()
{
    srand((unsigned)time(NULL));

    int carri_persi_attacco = 0, val_a, val_d;
    int a1, a2 = 0, a3 = 0, d1, d2 = 0, d3 = 0;

    cout<< "Quante armate di attacco vuoi usare? (1 - 3): ";
    cin>> val_a;
    cout<< "Quante armate di difesa vuoi usare? (1 - 3): ";
    cin>> val_d;

    if(val_a == 3)
    {
        a1 = (rand()% 6 ) + 1;
        a2 = (rand()% 6 ) + 1;
        a3 = (rand()% 6 ) + 1;
        cout<<"\nPrimo dado attacco: " << a1 << endl;
        cout<<"Secondo dado attacco: " << a2 << endl;
        cout<<"Terzo dado attacco: " << a3 << endl <<endl;
    }

    else if(val_a == 2)
    {
        a1 = (rand()% 6 ) + 1;
        a2 = (rand()% 6 ) + 1;
        cout<<"\nPrimo dado attacco: " << a1 << endl;
        cout<<"Secondo dado attacco: " << a2 << endl << endl;
    }

    else
    {
        a1 = (rand()% 6 ) + 1;
        cout<<"\nPrimo dado attacco: " << a1 << endl << endl;
    }


    if(val_d == 3)
    {
        d1 = (rand()% 6 ) + 1;
        d2 = (rand()% 6 ) + 1;
        d3 = (rand()% 6 ) + 1;
        cout<<"Primo dado difesa: " << d1 << endl;
        cout<<"Secondo dado difesa: " << d2 << endl;
        cout<<"Terzo dado difesa: " << d3 << endl << endl;
    }

    else if(val_d == 2)
    {
        d1 = (rand()% 6 ) + 1;
        d2 = (rand()% 6 ) + 1;
        cout<<"Primo dado difesa: " << d1 << endl;
        cout<<"Secondo dado difesa: " << d2 << endl << endl;
    }

    else
    {
        d1 = (rand()% 6 ) + 1;
        cout<<"Primo dado difesa: " << d1 << endl << endl;
    }


    ordinamento(a1, a2, a3);
    ordinamento(d1, d2, d3);

    if(val_a > val_d)
    {
        int appoggio = val_a;
        val_a = val_d;
        val_d = appoggio;
    }

    if(val_a == 3)
    {
        if (vincitore(a1, d1)) carri_persi_attacco++;
        if (vincitore(a2, d2)) carri_persi_attacco++;
        if (vincitore(a3, d3)) carri_persi_attacco++;
    }

    else if(val_a == 2)
    {
        if (vincitore(a2, d2)) carri_persi_attacco++;
        if (vincitore(a3, d3)) carri_persi_attacco++;
    }

    else if (vincitore(a3, d3)) carri_persi_attacco++;

    cout<< "Carri persi attacco: " << carri_persi_attacco << endl;
    cout<< "Carri persi difesa: " << val_a - carri_persi_attacco << endl;

    return 0;
}
