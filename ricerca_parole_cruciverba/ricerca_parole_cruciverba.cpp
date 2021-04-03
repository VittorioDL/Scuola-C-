#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    ifstream file;
    ofstream out;
    string str;
    int risp;

    do
    {
        cout<<"Inserire una stringa nel formato --X-X (scrivere solo le lettere al posto delle X): ";
        getline(cin, str);
    }
    while(str.length() != 2);

    cout<<"1: Visualizza parole con lo stesso formato\n2: Metti le parole con lo stesso formato in un file\n>>> ";
    cin>>risp;

    if(risp == 1)
    {
        file.open("par.txt");
        string esame;
        while(!file.eof())
        {
            file>>esame;
            if((esame[2] == str[0]) && (esame[4] == str[1]) && (esame.length() == 5)) cout<<esame<<endl;
        }
        file.close();
    }

    if(risp == 2)
    {
        file.open("par.txt");
        out.open("out.txt");
        string esame;
        while(!file.eof())
        {
            file>>esame;
            if((esame[2] == str[0]) && (esame[4] == str[1]) && (esame.length() == 5)) out<<esame<<endl;
        }
        file.close();
        out.close();
    }
    return 0;
}
