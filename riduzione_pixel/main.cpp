#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void ridimensionamento(int m[][300+2], int mr[][150+2], int nr, int nc)
{
    int i = 0, j = 0;
    for(int r = 1; r <= nr; r += 2)
    {
        i++;
        for(int c = 1; c <= nc; c += 2)
        {
            j++;
            mr[i][j] = (m[r][c] + m[r][c+1] + m[r+1][c] + m[r+1][c+1])/4;
        }
        j = 1;
    }
}

void caricamento(int m[][300+2], int r, int c)
{
     for(int i = 1; i <= r; i++)
     {
        for(int j = 1; j <= c; j++) m[i][j] = rand()%256;
     }
}

void visualizzazione(int m[][300+2], int r, int c)
{
     for(int i = 1; i <= r; i++)
     {
         for(int j = 1; j <= c; j++) cout<<m[i][j]<<" ";
         cout<<endl;
     }
}

void visualizzazione(int m[][150+2], int r, int c)
{
     for(int i = 1; i <= r; i++)
     {
         for(int j = 1; j <= c; j++) cout<<m[i][j]<<" ";
         cout<<endl;
     }
}

int main()
{
    srand((unsigned)time(NULL));
    int r = 200, c = 300;
    int m1[200+2][300+2] = {0};
    int m2[100+2][150+2] = {0};

    caricamento(m1, r, c);
    ridimensionamento(m1, m2, r, c);
    //visualizzazione(m1, r, c);
    cout<<endl;
    //visualizzazione(m2, r/2, c/2);

    return 0;
}
