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

int intorno(int m[][10+2], int x, int y)
{
    int tot = 0;
    for(int i = 1; i >= -1; i--)
        for(int j = 1; j >= -1; j--)
            tot += m[x+j][y+i];
    tot -= m[x][y];
    return tot;
}

int main()
{
    srand((unsigned)time(NULL));

    int m[10+2][10+2] = {0};
    caricamento(m, 10);
    visualizzazione(m, 10);
    int x, y;
    cout<<"\nInserire l'ascissa: ";
    cin>>x;
    cout<<"\nInserire l'ordinata: ";
    cin>>y;
    cout<<"\nSomma intorno: "<<intorno(m, x, y);

    return 0;
}
