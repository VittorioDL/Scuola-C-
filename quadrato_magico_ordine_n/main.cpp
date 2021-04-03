#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void caricamento_quadrato_magico(int m[][101], int n)
{
    int centro = ((n - 1)/2)+1;
    int r = 1, c = centro;
    m[r][c] = 1;
    for(int i = 2; i <= n*n; i++)
    {
        int precR = r, precC = c;
        r--;
        c++;
        if(r == 0) r = n;
        if(c > n)  c = 1;

        if(m[r][c] != 0)
        {

            precR++;

            r++;
            c--;
            if(r == 0) r = n;
            if(r > n) r = 1;
            r++;


            if(c > n)  c = 1;
            m[precR][precC] = i;
        }

        else m[r][c] = i;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int m[101][101] = {0};
    int n;
    cout<<"Inserire un valore dispari tra 3 e 99: ";
    cin>>n;

    caricamento_quadrato_magico(m, n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(m[i][j] < 10) cout<<" ";
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
