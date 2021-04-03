#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void quarato_magico(int m[][3+2], int valsM, int nPari[], int valsP)
{
    int ind = (rand()%valsP)+1;
    m[1][1] = nPari[ind];
    nPari[ind] = 0;
    m[valsM][valsM] = 10 - m[1][1];
    for(int i = 1; i <= valsP; i++)
    {
        if(m[valsM][valsM] == nPari[i]) nPari[i] = 0;
    }

    do ind = (rand()%valsP)+1;
    while(nPari[ind] == 0);

    m[1][valsM] = nPari[ind];
    m[valsM][1] = 10 - nPari[ind];

    m[1][2] = 15 - (m[1][1] + m[1][3]);
    m[2][1] = 15 - (m[1][1] + m[3][1]);
    m[2][3] = 15 - (m[1][3] + m[3][3]);
    m[3][2] = 15 - (m[3][1] + m[3][3]);

    m[2][2] = 5;
}

int main()
{
    srand((unsigned)time(NULL));

    int m[3+2][3+2] = {0}, vals = 3;
    int nPari[vals*vals], nDispari[vals*vals];

    int valsP = 0;
    for(int i = 1; i<= vals*vals; i++)
    {
        if((i%2) == 0)
        {
            valsP++;
            nPari[valsP] = i;
        }
    }

    quarato_magico(m, vals, nPari, valsP);

    for(int i = 1; i<= vals; i++)
    {
        for(int j = 1; j<= vals; j++) cout<<m[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}
