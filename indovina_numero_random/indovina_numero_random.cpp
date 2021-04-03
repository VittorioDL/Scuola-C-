#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;



int main()
{
    int num, guess, tent = 0;
    srand((unsigned)time(NULL));
    num = rand()%101;

    do
    {
        cout<<"Indovina a che numero sto pensando... e' tra 0 e 100"<<endl;
        cin>>guess;

        if (guess == num)
        {
            cout<<"Hai indovinato!"<<endl;
        }

        else if (guess > num)
        {
            cout<<"Scegli un numero piu' basso..."<<endl;
        }

        else
        {
            cout<<"Scegli un numero piu' alto..."<<endl;
        }

        tent++;

    } while (guess != num);

    cout<<"Tentativi: ";
    cout<<tent<<endl;
    return 0;
}
