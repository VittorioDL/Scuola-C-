#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    int d1 = 0, d2 = 0, somma = 0, stats = 0, contatore = 0;

    for (int n = 2; n <= 12; n++)
    {
        for (int i = 1; i <= 1000; i++)
        {
            d1 = (rand()%6) + 1;
            d2 = (rand()%6) + 1;
            somma = d1 + d2;

            if (somma == n)
            {
                contatore++;
            }
        }
        cout<<"Probabilita' di uscita del ";
        cout<<n;
        cout<<": ";
        stats = contatore / 10;
        cout<<stats;
        cout<<"%"<<endl;

        for (int f = 1; f <= stats; f++)
        {
            cout<<"*";
        }

        cout<<""<<endl;

        contatore = 0;
    }
    return 0;
}
