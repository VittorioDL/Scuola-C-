#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int minimo(int &a, int &b, int &c, int &mn)
{
    int k = 6;
    if(a == mn)
        a = k + 1;
    else if(b == mn)
        b = k + 1;
    else if(c == mn)
        c = k + 1;

    mn = a;

    if(b < mn)
        mn = b;
    if(c < mn)
        mn = c;

    return mn;
}

int main()
{
    srand((unsigned)time(NULL));

    int k = 6, mn = k +1, val = 3;
    int a = (rand()%k) + 1;
    int b = (rand()%k) + 1;
    int c = (rand()%k) + 1;


    cout<<"Primo valore casuale: " << a <<endl;
    cout<<"Secondo valore casuale: " << b <<endl;
    cout<<"Terzo valore casuale: " << c <<endl<<endl;

    for(int i = 1; i <= val; i++)
    {
        cout<<i <<"^ valore: " <<minimo(a,b,c,mn)<<endl;
    }

    return 0;
}
