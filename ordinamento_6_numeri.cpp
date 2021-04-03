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

void ordinamento(int &v1, int &v2, int &v3, int &v4, int &v5, int &v6)
{
    if(v1 > v2) scambio(v1, v2);
    if(v2 > v3) scambio(v2, v3);
    if(v3 > v4) scambio(v3, v4);
    if(v4 > v5) scambio(v4, v5);
    if(v5 > v6) scambio(v5, v6);
    if(v1 > v2) scambio(v1, v2);
    if(v2 > v3) scambio(v2, v3);
    if(v3 > v4) scambio(v3, v4);
    if(v4 > v5) scambio(v4, v5);
    if(v1 > v2) scambio(v1, v2);
    if(v2 > v3) scambio(v2, v3);
    if(v3 > v4) scambio(v3, v4);
    if(v1 > v2) scambio(v1, v2);
    if(v2 > v3) scambio(v2, v3);
    if(v1 > v2) scambio(v1, v2);


}

int main()
{
    srand((unsigned)time(NULL));

    int v1 = (rand()% 20 ) + 1;
    int v2 = (rand()% 20 ) + 1;
    int v3 = (rand()% 20 ) + 1;
    int v4 = (rand()% 20 ) + 1;
    int v5 = (rand()% 20 ) + 1;
    int v6 = (rand()% 20 ) + 1;

    cout<<"Primo numero casuale: " << v1 << endl;
    cout<<"Secondo numero casuale: " << v2 << endl;
    cout<<"Terzo numero casuale: " << v3 << endl;
    cout<<"Quarto numero casuale: " << v4 << endl;
    cout<<"Quinto numero casuale: " << v5 << endl;
    cout<<"Sesto numero casuale: " << v6 << endl << endl;

    ordinamento(v1, v2, v3, v4, v5, v6);

    cout<<"Primo numero ordinato: " << v1 << endl;
    cout<<"Secondo numero ordinato: " << v2 << endl;
    cout<<"Terzo numero ordinato: " << v3 << endl;
    cout<<"Quarto numero ordinato: " << v4 << endl;
    cout<<"Quinto numero ordinato: " << v5 << endl;
    cout<<"Sesto numero ordinato: " << v6 << endl;

    return 0;
}
