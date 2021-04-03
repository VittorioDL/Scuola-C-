#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int conta_parole(string s, int lun)
{
    int parole = 0;
    for(int i = 0; i < lun; i++)
    {
        if(s[i] != ' ' && s[i] != '.' && s[i] != ',' && s[i] != ':' && s[i] != '?' && s[i] != '!' &&.. s[i] != '€')
        {
            do
            {
                i++;
            }
            while(s[i] != ' '&& i < lun);
            parole++;
        }
    }
    return parole;
}

void conta_vocali_consonanti(string s, int lun, int &voc, int &cons)
{
    for(int i = 0; i < lun; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') voc++;
        //non è il modo più efficiente di riconoscere le consonanti... ma funziona!
        else if(s[i] == 'b' || s[i] == 'c' || s[i] == 'd' || s[i] == 'f' || s[i] == 'g' || s[i] == 'h' || s[i] == 'l' ||
                s[i] == 'm' || s[i] == 'n' || s[i] == 'p' || s[i] == 'q' || s[i] == 'r' || s[i] == 's' || s[i] == 't' ||
                s[i] == 'v' || s[i] == 'z' || s[i] == 'w' || s[i] == 'k' || s[i] == 'j' || s[i] == 'x') cons++;
    }
}

int main()
{
    string str;
    int lunghezza, parole, vocali = 0, consonanti = 0;

    cout<<"Inserire una stringa: ";
    getline(cin, str);

    lunghezza = str.size();
    parole = conta_parole(str, lunghezza);

    conta_vocali_consonanti(str, lunghezza, vocali, consonanti);

    cout<<"\nLa stringa: '"<<str<<"' contiene: "<<lunghezza<<" caratteri"<<endl;
    cout<<"\nLa stringa: '"<<str<<"' contiene: "<<vocali<<" vocali"<<endl;
    cout<<"\nLa stringa: '"<<str<<"' contiene: "<<consonanti<<" consonanti"<<endl;
    cout<<"\nLa stringa: '"<<str<<"' contiene: "<<parole<<" parole"<<endl;

    return 0;
}
