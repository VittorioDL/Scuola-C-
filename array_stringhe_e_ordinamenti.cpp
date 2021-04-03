#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void scambia_voti(float &a, float &b)
{
    float appo = a;
    a = b;
    b = appo;
}

void scambia_nomi(string &a, string &b)
{
    string appo = a;
    a = b;
    b = appo;
}


void ordinamento_alfabetico(string nomi[], float voti[], int n)
{
    for(int i = 1; i <= n-1; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(nomi[i] > nomi[j])
            {
                scambia_nomi(nomi[i], nomi[j]);
                scambia_voti(voti[i], voti[j]);
            }
        }
    }
}


void ordinamento_voti(string nomi[], float voti[], int n)
{
    for(int i = 1; i <= n-1; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(voti[i] > voti[j])
            {
                scambia_voti(voti[i], voti[j]);
                scambia_nomi(nomi[i], nomi[j]);
            }
        }
    }
}

void visualizzazione(string nomi[], float voti[], int n)
{
    for(int i = 1; i <= n; i++) cout<<"Voto medio di "<<nomi[i]<<": "<<voti[i]<<endl;
}

int main()
{
    int n = 5+1, mod;
    string nomi[n];
    float voti_medi[n];

    for(int i = 1; i <= n; i++)
    {
        cout<<"Inserire nome "<<i<<"^ alunno: ";
        if(i>1) cin.ignore();   // ho usato questo metodo perche' dopo il primo input mi ignorava il secondo getline()
        getline(cin, nomi[i]);
        cout<<"Inserire voto medio "<<i<<"^ alunno: ";
        cin>>voti_medi[i];
        cout<<endl;
    }

    cout<<"Selezionare modalita' di visualizzazione voti:\n1: Ordine alfabetico     2: Ordine di voto medio\n>>>";
    cin>>mod;

    if(mod == 1) ordinamento_alfabetico(nomi, voti_medi, n-1);
    else if(mod == 2) ordinamento_voti(nomi, voti_medi, n-1);

    cout<<endl;
    visualizzazione(nomi, voti_medi, n);

    return 0;
}
