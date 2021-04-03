#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void bombe(int m[][100], int n, int numbombe)
{
	int a, b;
	for(int i = 1; i <= numbombe; i++)
	{
		do
		{
			a = (rand()%n)+1;
			b = (rand()%n)+1;
		}
		while(m[a][b] == 9);
		m[a][b] = 9;
	}
}

void intorno_bombe(int m[][100], int n)
{
    int n_bombe = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(m[i][j] != 9)
            {
                for(int r = i-1; r <= i+1; r++)
                {
                    for(int c = j-1; c <= j+1; c++)
                    {
                        if(m[r][c] == 9) n_bombe++;
                    }
                }
                m[i][j] = n_bombe;
                n_bombe = 0;
            }
        }
    }
}

void visualizza(int m[][100], int n)
{
	cout<<endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++) cout<<m[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    srand((unsigned) time(NULL));

    int n, diff, numbombe;
    int m[100][100];

    cout<<"Inserire lato quadrato (5 - 40): ";
    cin>>n;
    cout<<"Inserire livello difficolta' (1 - 2 - 3): ";
    cin>>diff;

    if (diff == 1)
       numbombe = n*n/8;
    if (diff == 2)
       numbombe = n*n/6;
    if (diff == 3)
       numbombe = n*n/4;

    bombe(m, n, numbombe);
    visualizza(m, n);
    intorno_bombe(m, n);
    visualizza(m, n);
    return 0;
}
