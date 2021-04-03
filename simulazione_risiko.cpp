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

    int carri_persi_attacco = 0;

    int a1 = (rand()% 6 ) + 1;
    int a2 = (rand()% 6 ) + 1;
    int a3 = (rand()% 6 ) + 1;

    int d1 = (rand()% 6 ) + 1;
    int d2 = (rand()% 6 ) + 1;
    int d3 = (rand()% 6 ) + 1;

    cout<<"Primo dado attacco: " << a1 << endl;
    cout<<"Secondo dado attacco: " << a2 << endl;
    cout<<"Terzo dado attacco: " << a3 << endl <<endl;

    cout<<"Primo dado difesa: " << d1 << endl;
    cout<<"Secondo dado difesa: " << d2 << endl;
    cout<<"Terzo dado difesa: " << d3 << endl << endl;

    ordinamento(a1, a2, a3);
    ordinamento(d1, d2, d3);

    if (vincitore(a1, d1)) carri_persi_attacco++;
    if (vincitore(a2, d2)) carri_persi_attacco++;
    if (vincitore(a3, d3)) carri_persi_attacco++;

    cout<< "Carri persi attacco: " << carri_persi_attacco << endl;
    cout<< "Carri persi difesa: " << 3 - carri_persi_attacco << endl;

    return 0;
}
