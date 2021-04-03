#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void caricamento(int m[][10+2], int n)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            m[i][j] = (rand()%6)+1;
}

void visualizzazione(int m[][10+2], int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(m[i][j] < 10)
                cout<<" ";
            cout<<m[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void slittaRighe(int m[][10+2], int r, int rmax, int cmax)
{
     for(int i = r; i <= rmax; i++)
     {
         for(int j = 1; j <= cmax; j++) m[i][j] = m[i+1][j];
     }

      for(int z = 1; z <= cmax; z++) m[rmax][z] = 0;
}

int main()
{
    srand((unsigned)time(NULL));

    int m[10+2][10+2] = {0};
    caricamento(m, 10);
    visualizzazione(m, 10);

    int r = -2;

    while(r != -1)
    {
        cout<<"\nInserire il numero di riga: ";
        cin>>r;

        slittaRighe(m, r, 10, 10);
        cout<<endl;
        visualizzazione(m, 10);
    }

    return 0;
}
