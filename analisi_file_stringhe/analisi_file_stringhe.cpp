#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int ripetizioniLettera(char l)
{
    ifstream file;

    file.open("par.txt");

    int cont = 0;
    string esame;
    while(!file.eof())
    {
        file>>esame;
        for(int i = 0; i <= esame.length(); i++)
            if(esame[i] == l) cont++;
    }
    file.close();
    return cont;
}

long long int totCaratteri()
{
    ifstream file;
    file.open("par.txt");

    long long int cont = 0;
    string esame;
    while(!file.eof())
    {
        file>>esame;
        cont += esame.length();
    }

    file.close();
    return cont;
}

char scambia(char &a, char &b)
{
    char appo = b;
    b = a;
    a = appo;
}

void anagrammi(string anag)
{
    ifstream file;
    file.open("par.txt");

    string esame;
    string appoE, appoA;
    bool check = false;
    while(!file.eof())
    {
        check = false;
        file>>esame;
        if(esame.length() == anag.length())
        {
            appoE = esame;
            appoA = anag;
            for(int i = 0; i < esame.length()-1; i++)
                for(int j = i+1; j < esame.length(); j++)
                {
                    if(esame[i] > esame[j]) scambia(esame[i], esame[j]);
                    if(anag[i] > anag[j]) scambia(anag[i], anag[j]);
                }

            if(esame == anag) cout<<appoE<<endl;
        }
    }
    file.close();
}

int main()
{
    int risp;
    ifstream file;

    do
    {
        cout<<"1) Ripetizioni lettera nel file"<<endl;
        cout<<"2) Numero complessivo caratteri del file"<<endl;
        cout<<"3) Output di un file con parole piu' lunghe di 14 caratteri"<<endl;
        cout<<"4) Anagrammi di una parola"<<endl;
        cout<<"0) Esci dal programma"<<endl;
        cout<<"\n>>> ";
        cin>>risp;

        if(risp == 1)
        {
            char l;
            cout<<"\nInserire un carattere: ";
            cin>>l;
            cout<<"\nRipetizioni: "<<ripetizioniLettera(l)<<endl;
        }

        if(risp == 2) cout<<"\nNumero di caratteri totali: "<<totCaratteri()<<endl;

        if(risp == 3)
        {
            ofstream out;

            out.open("lunghe.txt");
            file.open("par.txt");

            string esame;
            while(!file.eof())
            {
                file>>esame;
                if(esame.length() >= 14) out<<esame<<endl;

            }
            out.close();
            file.close();
            cout<<"\nOutput del file lunghe.txt avvenuto con successo!"<<endl;
        }

        if(risp == 4)
        {
            string anag;
            cout<<"\nInserire una stringa: ";
            cin.ignore();
            getline(cin, anag);
            anagrammi(anag);
        }
        cout<<"\n";
    }while(risp != 0);





    return 0;
}
