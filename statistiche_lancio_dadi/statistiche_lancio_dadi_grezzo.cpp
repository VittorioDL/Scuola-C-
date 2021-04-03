#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    int d1 = 0, d2 = 0, somma = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0, c10 = 0, c11 = 0, c12 = 0;
    double stats = 0;

    for (int i = 1; i <= 1000; i++)
    {
        d1 = (rand()%6) + 1;
        d2 = (rand()%6) + 1;
        somma = d1 + d2;

        switch(somma)
        {
            case 2: c2++; break;
            case 3: c3++; break;
            case 4: c4++; break;
            case 5: c5++; break;
            case 6: c6++; break;
            case 7: c7++; break;
            case 8: c8++; break;
            case 9: c9++; break;
            case 10: c10++; break;
            case 11: c11++; break;
            case 12: c12++; break;
        }
    }

    cout<<"Probabilita' di uscita del 2: ";
    stats = c2 / 10;
    cout<<stats;
    cout<<"%"<<endl;


    for (int n = 1; n <= c2; n++)
    {
        cout<<"*";
    }
    cout<<"\n"<<endl;

    cout<<"Probabilita' di uscita del 3: ";
    stats = c3 / 10;
    cout<<stats;
    cout<<"%"<<endl;

    for (int n = 1; n <= c3; n++)
    {
        cout<<"*";

    }
    cout<<"\n"<<endl;

    cout<<"Probabilita' di uscita del 4: ";
    stats = c4 / 10;
    cout<<stats;
    cout<<"%"<<endl;

    for (int n = 1; n <= c4; n++)
    {
        cout<<"*";

    }
    cout<<"\n"<<endl;

    cout<<"Probabilita' di uscita del 5: ";
    stats = c5 / 10;
    cout<<stats;
    cout<<"%"<<endl;

    for (int n = 1; n <= c5; n++)
    {
        cout<<"*";

    }
    cout<<"\n"<<endl;

    cout<<"Probabilita' di uscita del 6: ";
    stats = c6 / 10;
    cout<<stats;
    cout<<"%"<<endl;

    for (int n = 1; n <= c6; n++)
    {
        cout<<"*";

    }
    cout<<"\n"<<endl;

    cout<<"Probabilita' di uscita del 7: ";
    stats = c7 / 10;
    cout<<stats;
    cout<<"%"<<endl;

    for (int n = 1; n <= c7; n++)
    {
        cout<<"*";

    }
    cout<<"\n"<<endl;

    cout<<"Probabilita' di uscita del 8: ";
    stats = c8 / 10;
    cout<<stats;
    cout<<"%"<<endl;

    for (int n = 1; n <= c8; n++)
    {
        cout<<"*";

    }
    cout<<"\n"<<endl;

    cout<<"Probabilita' di uscita del 9: ";
    stats = c9 / 10;
    cout<<stats;
    cout<<"%"<<endl;

    for (int n = 1; n <= c9; n++)
    {
        cout<<"*";

    }
    cout<<"\n"<<endl;

    cout<<"Probabilita' di uscita del 10: ";
    stats = c10 / 10;
    cout<<stats;
    cout<<"%"<<endl;

    for (int n = 1; n <= c10; n++)
    {
        cout<<"*";

    }
    cout<<"\n"<<endl;

    cout<<"Probabilita' di uscita del 11: ";
    stats = c11 / 10;
    cout<<stats;
    cout<<"%"<<endl;

    for (int n = 1; n <= c11; n++)
    {
        cout<<"*";

    }
    cout<<"\n"<<endl;

    cout<<"Probabilita' di uscita del 12: ";
    stats = c12 / 10;
    cout<<stats;
    cout<<"%"<<endl;

    for (int n = 1; n <= c12; n++)
    {
        cout<<"*";

    }
    cout<<"\n"<<endl;
    return 0;
}
