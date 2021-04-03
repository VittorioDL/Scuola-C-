#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void allagamento(int m[][100],char a[][100],int n,int rig,int col)
{
	for (int i=rig-1;i<=rig+1;i++)
	   for (int j=col-1;j<=col+1;j++)
	   {
		  if ((i!=rig) | (j!=col))  // & (i>=1 & i<=n) & (j>=1 & j<=n))

			  if ((m[i][j]<=m[rig][col])) // QUI
			  {
				 if (a[i][j]!='*') // QUI
				 {
					 a[i][j]='*';
					 allagamento(m,a,n,i,j);
				 }
			  }
	  }

}

void visualizza(int m[][100], int n)
{
	cout<<endl;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
           cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}
void visualizza(char m[][100], int n)
{
	cout<<endl;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
           cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,rig,col;
    srand ((unsigned) time(NULL));
    cout<<"Inserire lato quadrato: ";
    cin>>n;

    int m[100][100];
    char a[100][100];

    for(int i=0;i<100; i++)
	{
		for(int j=0; j<100; j++)
		{
		    a[i][j]='.';
		}
	}
	for(int i=0;i<100; i++)
	{
		for(int j=0; j<100; j++)
		{
		    m[i][j]=65535;
		}
	}

    for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
		   m[i][j]=rand()%10;
		}
	}
	visualizza(m,n);

	cout<<"\nInserire coordinate sorgente";
	cout<<"\nRiga:";
	cin>>rig;
	cout<<"Colonna: ";
	cin>>col;

	a[rig][col]='*';
	allagamento(m,a,n,rig,col);

    cout<<endl;
    visualizza(a,n);
    return 0;
}
