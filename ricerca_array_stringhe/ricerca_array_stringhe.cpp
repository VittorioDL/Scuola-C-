#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string.h>

using namespace std;

void caricamento_casuale(string lista[], int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= 49; j++)
        {
            lista[i] += char(rand()%25)+97;
        }
    }
}

void visualizzazione_substringhe_uguali(string lista[], string str_utente, int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= 48; j++)
        {
            if(lista[i].substr(j,2) == str_utente)
            {
                lista[i][j] -= 32;     //mette in maiuscolo i due caratteri uguali alla sottostringa
                lista[i][j+1] -= 32;
                cout<<endl<<lista[i]<<endl<<endl;
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    string str_casuali[101], stringa_utente;
    int n = 100;

    do
    {
        cout<<"Inserire una stringa di 2 caratteri minuscoli: ";
        getline(cin, stringa_utente);
    }while(stringa_utente.length() > 2 || stringa_utente.length() < 2
             || stringa_utente[0] < 97 || stringa_utente[1] < 97
            || stringa_utente[0] > 122 || stringa_utente[1] > 122);

    caricamento_casuale(str_casuali, n);

    visualizzazione_substringhe_uguali(str_casuali, stringa_utente, n);

    return 0;
}
