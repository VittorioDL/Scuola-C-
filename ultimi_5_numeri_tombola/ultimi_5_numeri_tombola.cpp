#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int cercaValore(int v[], int numvalori, int valoreDaCercare)
{
	for(int i=1; i<=numvalori; i++)
	{
		if(v[i]==valoreDaCercare)
		{
		    return i;
		}
	}
	return -1;
}

void visualizzaTabellone(int v[], int numerovalori)
{
	for (int i=1;i<=90;i++)
	{
		if(cercaValore(v, numerovalori, i)!=-1)
		{
			if(i<10) cout<<" ";
			cout<<i<<" ";
		}
		else
			cout<<" _ ";
		if(i%10==0) cout<<endl;
	}
}

void visualizzaUltimi(int v[], int numerovalori, int ultimo_numero )
{
    int un = ultimo_numero;
    for (int i=1;i<=90;i++)
	{
	    if((ultimo_numero > 0) & (ultimo_numero > un - 5))
        {
            if(cercaValore(v, numerovalori, v[ultimo_numero])!= -1) cout<<v[ultimo_numero]<<" ";
            ultimo_numero--;
        }
	}
}

int main()
{
    srand((unsigned)time(NULL));

    const int numerovalori=100;
    int valore[numerovalori+1]={0};
    char risposta;

    for(int i=1; i<=90;i++)
    {
		 if ((risposta!='t') & (risposta!='u'))
		 {
			 int a;

			 do
				a=((rand()%90)+1);
			 while(cercaValore(valore,90,a)!=-1);

			 valore[i]=a;
			 cout<<"Il "<<i<<"^ numero estratto e': "<<a<<endl;
	     }
         cout<<"\nVuoi estrarre un nuovo numero?(n per fermare, t per tabellone, u per ultimi numeri): ";
         cin>>risposta;
         if (risposta=='n') break;
         if (risposta=='t')
         {
             visualizzaTabellone(valore,90);
             i--;
         }

         if (risposta=='u')
         {
             visualizzaUltimi(valore,90,i);
             i--;
         }
    }
    return 0;
}


