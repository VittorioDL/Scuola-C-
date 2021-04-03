#include <iostream>
#include <ctime>     //Librerie per numeri random
#include <stdlib.h>

using namespace std;

void allagamento(int m[][100], char a[][100] , int n, int rig, int col)
{
	int contatore, appo = m[rig][col], contPrec = 0, loop = 0;
	a[rig][col] = '*';
	do
	{
	    // QUI
	    contPrec = contatore;
        contatore = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i][j] == '*')
				{
					appo = m[i][j];
					for(int x=i-1;x<=i+1;x++)
					{
						for(int z=j-1;z<=j+1;z++)
						{
							if(m[x][z] <= appo)
							{
								a[x][z] = '*';
								contatore++;
							}
						}
					}
				}
			}
		}
        // QUI
		if(loop == 0) contPrec = -1;
        loop++;
	}
	while(contatore != contPrec);  // QUI
}

void visualizzaM(int m[][100], int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++) cout<<m[i][j]<<" ";
        cout<<endl;
    }
}

void visualizzaA(char m[][100], int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++) cout<<m[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int n,rig,col;
    srand ((unsigned) time(NULL));
    cout<<"Inserire lato quadrato: ";
    cin>>n;

    int m[100][100] = {65535};
    char a[100][100];
    for(int i = 1; i <= 100; i++) //QUI
    {
         for(int j = 1; j <= 100; j++) a[i][j] = '.';
    }


    for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
		   m[i][j]=rand()%10;
		}
	}

	cout<<"Inserire coordinate sorgente (riga, colonna)\n";
	cout<<"Riga: ";
	cin>>rig;
	cout<<"Colonna: ";
	cin>>col;

	a[rig][col]='*';

	cout<<endl;
	visualizzaM(m,n);
	cout<<endl;

	allagamento(m,a,n,rig,col);
    cout<<endl;

    visualizzaA(a,n);

    return 0;
}
