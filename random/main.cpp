#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    int a[16];
    for(int i = 1; i <= 15; i++) a[i] = i;
    int ind;
    for(int j = 1; j <= 15; j++)
    {
        do
        {
            ind = (rand()%15)+1;
            if(a[ind] != 0)
            {
                cout<<a[ind]<<" ";
                a[ind] = 0;
            }
        }while(a[ind] == 0);
    }
    return 0;
}
