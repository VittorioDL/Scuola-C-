#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

void ripetizioni_lettere(string s, int lett[])
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] <= 90 && s[i] >= 65)
        {
            lett[s[i]-64]++;
        }
        else if(s[i] <= 122 && s[i] >= 97) lett[s[i]-96]++;
    }
}

int main()
{
    string stringa;
    int lett[27] = {0};

    cout<<"Inserire una stringa: ";
    getline(cin, stringa);

    ripetizioni_lettere(stringa, lett);
    char lettera_piu_ripetuta;

    int num_ripetizioni = *max_element(lett,lett+26);

    for(int i = 1; i <= 26; i++)
    {
        if(lett[i] == num_ripetizioni) lettera_piu_ripetuta = i + 96;
    }
    cout<<"Lettera piu' ripetuta: "<<lettera_piu_ripetuta<<endl;

    return 0;
}
