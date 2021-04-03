#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void caricamento(int m[][100], int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) m[i][j] = (rand()%3)+1;
    }
}

bool m_simmetrica_ricorsiva(int m[][100], int n, int r, int c)
{
    if(c > n)
    {
        c = 1;
        r++;
    }

    if(r <= n)
    {
        if(m[r][c] != m[c][r]) return false;
        m_simmetrica_ricorsiva(m, n, r, c+1);
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));
    int m[100][100];
    int n = 3;

    caricamento(m, n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)  cout<<m[i][j]<<" ";
        cout<<endl;
    }
    if(m_simmetrica_ricorsiva(m, n, 1, 1)) cout<<"\nLa matrice e' simmetrica\n";
    else cout<<"\nLa matrice non e' simmetrica\n";

    return 0;
}
