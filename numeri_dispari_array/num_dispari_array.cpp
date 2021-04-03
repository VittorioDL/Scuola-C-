#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    int num_dispari[31];

    for(int i = 1; i <= 30; i++)
    {
        num_dispari[i] = (rand()%100)+1;
    }

    for(int a = 1; a <= 30; a++)
    {
        if((num_dispari[a] % 2) != 0) cout<<"L'elemento " << a-1 <<" ("<<num_dispari[a]<<")"<<" e' dispari"<<endl;
    }


    return 0;
}
