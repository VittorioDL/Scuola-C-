#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file_lotto;
    int estrazione[5];

    file_lotto.open("lotto.txt");
    for(int i = 0; i <= 5; i++)
    {
        file_lotto>>estrazione[i];
        if(file_lotto.eof()) break;
    }

    file_lotto.close();

    char risp;
    int ind = 0;
    do
    {
        cout<<"Visualizzare numero estratto? (s, n): ";
        cin>>risp;
        if(risp == 's') cout<<estrazione[ind]<<endl;
        ind++;
    }
    while(risp == 's' && ind < 6);

    return 0;
}
