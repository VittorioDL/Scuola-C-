#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct libro
{
    string autore;
    string titolo;
    string editore;
    int pagine;
    float prezzo;
};

void inserimentoLibro(libro &libroDaInserire)
{
    cout<<"\nInserire autore: ";
    cin.ignore();
    getline(cin, libroDaInserire.autore);

    cout<<"Inserire titolo: ";
    getline(cin, libroDaInserire.titolo);

    cout<<"Inserire editore: ";
    getline(cin, libroDaInserire.editore);

    cout<<"Inserire lunghezza in pagine: ";
    cin>>libroDaInserire.pagine;

    cout<<"Inserire prezzo: ";
    cin>>libroDaInserire.prezzo;
    cout<<endl;
}

void scambioS(string &a, string &b)
{
    string appo = a;
    a = b;
    b = appo;
}

void ordinamentoAutore(libro libriDaOrdinare[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
       for (int j = i+1; j < n; j++)
       {
          if(libriDaOrdinare[i].autore > libriDaOrdinare[j].autore) scambioS(libriDaOrdinare[i].autore, libriDaOrdinare[j].autore);
       }
    }
}

void scambioF(float &a, float &b)
{
    float appo = a;
    a = b;
    b = appo;
}

void ordinamentoPrezzo(libro libriDaOrdinare[], int n)
{
   for(int i = 0; i < n-1; i++)
   {
      for(int j = i+1; j < n; j++)
      {
         if(libriDaOrdinare[i].prezzo < libriDaOrdinare[j].prezzo) scambioF(libriDaOrdinare[i].prezzo, libriDaOrdinare[j].prezzo);
      }
   }
}

void visualizzazioneLibri(libro libreria[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"\nTitolo: "<<libreria[i].titolo<<endl;
        cout<<"Autore: "<<libreria[i].autore<<endl;
        cout<<"Editore: "<<libreria[i].editore<<endl;
        cout<<"Prezzo: "<<libreria[i].prezzo<<endl;
        cout<<"Lunghezza: "<<libreria[i].pagine<<endl;
    }
    cout<<endl;
}

int main()
{
    int nMax = 99, risp, nLibri = 0;
    libro libreria[nMax];

    do
    {

        cout<<"1) INSERISCI UN LIBRO"<<endl;
        cout<<"2) VISUALIZZA LIBRI IN ORDINE DI AUTORE"<<endl;
        cout<<"3) VISUALIZZA LIBRI IN ORDINE DI PREZZO"<<endl;
        cout<<"4) ESCI DAL PROGRAMMA"<<endl;

        cout<<">>> ";
        cin>>risp;

        if(risp == 1)
        {
            inserimentoLibro(libreria[nLibri]);
            nLibri++;
        }


        if(risp == 2)
        {
            ordinamentoAutore(libreria, nLibri);
            visualizzazioneLibri(libreria, nLibri);
        }

        if(risp == 3)
        {
            ordinamentoPrezzo(libreria, nLibri);
            visualizzazioneLibri(libreria, nLibri);
        }
    }
    while(risp != 4);

    return 0;
}
