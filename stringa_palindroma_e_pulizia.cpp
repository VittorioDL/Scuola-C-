#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

string pulisciStringa(string frase)
{
    string frase_pulita;
    for(int i = 0; i < frase.size(); i++)
    {
        if(frase[i] <= 'z' && frase[i] >= 'a') frase_pulita += frase[i];

        else if(frase[i] <= 'Z' && frase[i] >= 'A' ) frase_pulita += frase[i] + 32;
    }
    return frase_pulita;
}

bool palindroma(string frase)
{
    // Ho creato questa variabile perche quando mettevo frase.size() al posto
    // di lung l'ultimo carattere non me lo prendeva (provi facendo un output
    // con substr(0, stringa.size()-1) )

    int lung = frase.size();

    if(lung > 0)
    {
        if(frase[0] == frase[lung-1] && palindroma(frase.substr(1, lung-2))) return true;
    }

    else return false;
}

int main()
{
    string frase;

    cout<<"Inserire una frase: ";
    getline(cin, frase);

    cout<<"\nFrase pulita: '"<<pulisciStringa(frase)<<"'"<<endl;

    if(palindroma(frase)) cout<<"\nLa frase e' palindroma\n";
    else cout<<"\nLa frase non e' palindroma\n";

    return 0;
}
