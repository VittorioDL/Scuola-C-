#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void bombe(int m[][101],int n,int numbombe)
{
	int a,b;
	for (int i=1;i<=numbombe;i++)
	{
		do
		{
			a=(rand()%n)+1;
			b=(rand()%n)+1;
		}
		while (m[a][b]==9);
		m[a][b]=9;
	}
}

void visualizza(int m[][101], int n)
{
	cout<<endl;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++) cout<<m[i][j]<<" ";
        cout<<endl;
    }
}

void visualizza(char a[][100], int n)
{
	cout<<endl;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void numerobombe(int m[][101],int n)
{
    int c=0,a,b;
    for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if (m[i][j]!=9)
			{
				for(a=i-1;a<=i+1;a++)
				{
					for(b=j-1;b<=j+1;b++)
					{
					    if(m[a][b]==9) c++;
					}
				}
				m[i][j]=c;
				c=0;
			}
		}
	}
}

void scopri_celle(int m[][101], char a[][100], int r, int c, bool &v)
{
	 int i, j;
	 if(m[r][c] == 9)  v = false;
	 if(m[r][c] == 0)
	 {
		a[r][c] = '-';
		for(i=r-1; i<=r+1; i++)
		{
			for(j=c-1; j<=c+1; j++)
			{
				if((i != r) || (j != c))
				{
					if((m[i][j] == 0) && (a[i][j] != '-'))
                        scopri_celle(m, a, i, j, v);

					if((m[i][j] != 0) && (m[i][j] < 9))
                        a[i][j] = m[i][j] + 48;
				}
			}
		}
	}
	if((m[r][c] != 0) && (m[r][c] != 9)) a[r][c] = m[r][c] + 48;
}

void bombe_sconfitta(char a[][100], int m[][101], int n)
{
    for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
        {
            if(m[i][j] == 9) a[i][j] = '#';
        }
	}
}

bool vittoria(char a[][100], int n, bool &v, int n_bombe)
{
    int cont = 0;
    for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
        {
            if(a[i][j] == '.') cont++;
        }
	}

	if(cont == n_bombe)
	{
	    v = false;
	    return true;
	}
	return false;
}

int calcolo_3BV(int m[][101], char a[][100], int n)
{
     int bv = 0;
     bool v = true;
     for(int i=1; i<=n; i++)
	 {
		for(int j=1; j<=n; j++)
		{
		    if((m[i][j] == 0) && (a[i][j] == '.'))
            {
                scopri_celle(m, a, i, j, v);
                bv++;
            }
		}
	}

	 for(int i=1; i<=n; i++)
	 {
		for(int j=1; j<=n; j++)
		{
		    if((m[i][j] != 9) && (m[i][j] != 0) && (a[i][j] == '.'))
            {
                scopri_celle(m, a, i, j, v);
                bv++;
            }
		}
	 }
	 return bv;
}

int main()
{
    srand((unsigned)time(NULL));
    int n, diff, numbombe, r, c;
    int m[101][101];
    char a[100][100];
    int mc[101][101];
    char ac[100][100];
    bool v = true;

    for(int i=1; i<=100; i++)
	{
		for(int j=1; j<=100; j++)
		{
		    a[i][j]='.';
		    ac[i][j]='.';
		}

	}

	for(int i=0; i<=100; i++)
	{
		for(int j=0; j<=100; j++)
        {
             m[i][j]= 10;
             mc[i][j]= 10;
        }
	}

    cout<<"Inserire lato quadrato (5 - 40): ";
    cin>>n;
    cout<<"Inserire livello difficolta' (1 - 2 - 3): ";
    cin>>diff;
    if (diff==1)
       numbombe=n*n/8;
    if (diff==2)
       numbombe=n*n/6;
    if (diff==3)
       numbombe=n*n/4;

    bombe(m,n,numbombe);
    numerobombe(m, n);
    visualizza(a,n);
    visualizza(m,n);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) mc[i][j] = m[i][j];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) ac[i][j] = a[i][j];
    }

    cout<<"\nIl numero minimo di click neccessari per vincere la partita e': "<<calcolo_3BV(mc, ac, n)<<endl;;

    do
    {
        cout<<"\nInserire numero riga: ";
        cin>>r;
        cout<<"Inserire numero colonna: ";
        cin>>c;
        scopri_celle(m, a, r, c, v);
        if(!v) bombe_sconfitta(a, m, n);
        vittoria(a, n, v, numbombe);
        visualizza(a, n);
    }while(v);

    if(vittoria(a, n, v, numbombe)) cout<<"\n--------------Hai vinto!---------------\n";
    else cout<<"\n--------------Ritenta e sarai piu' fortunato...---------------\n";

    return 0;
}
