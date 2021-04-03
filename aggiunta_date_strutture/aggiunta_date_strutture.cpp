#include <iostream>
#include <string>

using namespace std;

struct data
{
	int anno;
	int mese;
	int giorno;
};

struct alunno
{
	string nome;
	data datanascita;
	int voto;
};

void scambia(alunno &a, alunno &b)
{
    alunno appo=a;
    a=b;
    b=appo;
}

void caricamento(alunno classe[], int n)
{
   for(int i = 0 ;i < n; i++)
   {
      cout<<"NOME DELL'ALUNNO: ";
      cin>>classe[i].nome;
      cout<<"RISPETTIVO VOTO MEDIO: ";
      cin>>classe[i].voto;
      cout<<"ANNO DI NASCITA: ";
      cin>>classe[i].datanascita.anno;
      cout<<"MESE DI NASCITA: ";
      cin>>classe[i].datanascita.mese;
      cout<<"GIORNO DI NASCITA: ";
      cin>>classe[i].datanascita.giorno;
      cout<<endl;
   }
}

void ordinealfabetico(alunno classe[],int n)
{
   for(int i = 0; i < n-1; i++)
   {
      for (int j = i+1; j < n; j++)
      {
         if (classe[i].nome > classe[j].nome) scambia(classe[i],classe[j]);
      }
   }
}

void ordinenumerico(alunno classe[],int n)
{
   for(int i = 0; i < n-1; i++)
   {
      for (int j = i+1; j < n; j++)
      {
         if (classe[i].voto < classe[j].voto) scambia(classe[i],classe[j]);
      }
   }
}

int main()
{
    int n=5;
    int a;

    alunno classe[5];

    cout<<"INSERISCI 5 NOMI DI ALUNNI CON I RISPETTIVI VOTI MEDI E DATA DI NASCITA"<<endl<<endl;

    caricamento(classe,n);

    /*
    // Impostiamo la data di nascita del secondo alunno al 25/04/2001
    data dn;
    dn.anno=2000;
    dn.mese=4;
    dn.giorno=25;
    classe[1].datanascita=dn;

    // Impostiamo la data di nascita del primo alunno al 25/12/2000
    classe[0].datanascita.anno=2000;
    classe[0].datanascita.mese=12;
    classe[0].datanascita.giorno=25;
    */

    do
    {
		cout<<"VISUALIZZAZIONE:"<<endl;
		cout<<"1)ORDINE ALFABETICO"<<endl;
		cout<<"2)ORDINE DECRESCENTE DI VOTO MEDIO"<<endl;
		cout<<"0)ESCI"<<endl;
		cin>>a;

		if(a==1)
		{
		  ordinealfabetico(classe,n);
		  for(int i=0;i<n;i++)
		  {
			cout<<"NOME:"<<classe[i].nome<<endl;
			cout<<"VOTO MEDIO:"<<classe[i].voto<<endl;
			cout<<"DATA DI NASCITA:"<<classe[i].datanascita.giorno<<"-"<<classe[i].datanascita.mese<<"-"<<classe[i].datanascita.anno<<endl;
			cout<<endl;
		  }
		}

		if(a==2)
		{
			ordinenumerico(classe,n);
			for(int i=0;i<n;i++)
			{
				cout<<"NOME:"<<classe[i].nome<<endl;
                cout<<"VOTO MEDIO:"<<classe[i].voto<<endl;
                cout<<"DATA DI NASCITA:"<<classe[i].datanascita.giorno<<"-"<<classe[i].datanascita.mese<<"-"<<classe[i].datanascita.anno<<endl;
                cout<<endl;
			}
		}
	}
    while(a!=0);

    return 0;
}
