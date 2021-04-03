#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    //Non ho usato le funzioni perchè non sapevo come passare un file tramite parametro

    double totChar = 2766902;
    double ripLett[26] = {0};

    ifstream file;
    ofstream percent;

    file.open("par.txt");
    string esame;
    while(!file.eof())
    {
        file>>esame;
        for(int i = 0; i < esame.length(); i++)
        {
            ripLett[esame[i]-'a']++;
        }
    }
    file.close();

    percent.open("percentuali.txt");
    double pValue;
    char lett;
    for(int i = 0; i < 26; i++)
    {
        char lett = 'a'+i;
        pValue = ripLett[i]*100/2766902;
        percent<<lett<<": "<<pValue<<"%"<<endl;
    }


    percent.close();


    return 0;
}
