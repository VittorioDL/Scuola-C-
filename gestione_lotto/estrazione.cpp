#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    int estrazione[5];

    for(int i = 0; i <= 5; i++)
    {
        int n = (rand()%90)+1;
        for(int j = 0; j <= i; j++)
        {
            do
            {
                n = (rand()%90)+1;
            }while(n == estrazione[j]);
        }
        estrazione[i] = n;
    }

    ofstream file_lotto;
    file_lotto.open("lotto.txt");

    for(int i = 0; i <= 5; i++) file_lotto<<estrazione[i]<<endl;

    file_lotto.close();


    return 0;
}
