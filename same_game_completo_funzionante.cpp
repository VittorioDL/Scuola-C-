
// DANIELE NATALE E VITTORIO DE LUCIA

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void caricamento(char m[][16+2], int r, int c, char car[])
{
    int ind;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
             ind = (rand()%5);
             m[i][j] = car[ind];
        }
    }
}

void visualizzazione(char m[][16+2], int r, int c)
{
    int corR = 1;

    for(int corC = 0; corC <= c; corC++)
    {
        if(corC < 10) cout<<" ";
        cout<<corC<<" ";
    }
    cout<<endl;

    for(int i = 1; i <= r; i++)
    {
        if(corR < 10) cout<<" ";
        cout<<corR<<" ";
        corR++;
        for(int j = 1; j <= c; j++)
        {
            if(m[i][j] == 'a') cout<<"   ";
            else cout<<" "<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

void scopri_celle(char m[][16+2], int r, int c, char sample, int &celle_scoperte)
{
    bool croce = false;
    if((sample == m[r-1][c]) || (sample == m[r][c+1]) || (sample == m[r+1][c]) || (sample == m[r][c-1])) croce = true;

    if(croce)
    {
        if(m[r-1][c] == sample)
        {
            m[r-1][c] = ' ';
            celle_scoperte++;
            scopri_celle(m, r-1, c, sample, celle_scoperte);
        }

        if(m[r][c+1] == sample)
        {
            m[r][c+1] = ' ';
            celle_scoperte++;
            scopri_celle(m, r, c+1, sample, celle_scoperte);
        }

        if(m[r+1][c] == sample)
        {
            m[r+1][c] = ' ';
            celle_scoperte++;
            scopri_celle(m, r+1, c, sample, celle_scoperte);
        }

        if(m[r][c-1] == sample)
        {
            m[r][c-1] = ' ';
            celle_scoperte++;
            scopri_celle(m, r, c-1, sample, celle_scoperte);
        }
    }
}

bool vittoria(char m[][16+2], int r, int c)
{
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if((m[i][j] != ' ') && (m[i][j] != 'a'))
            {
                if((m[i][j] == m[i-1][j]) || (m[i][j] == m[i][j+1]) || (m[i][j] == m[i+1][j]) || (m[i][j] == m[i][j-1])) return true;
            }
        }
    }
    return false;
}

void sposta_basso(char m[][16+2], int r, int c)
{
    int k = 0;
    for(int i = 2; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(m[i][j] == ' ')
            {
                for(int riga = i-1; riga >= 0; riga--)
                {
                    m[i-k][j] = m[riga][j];
                    k++;
                }
            }
            k = 0;
        }
    }
}

void sposta_sinistra(char m[][16+2], int r, int c)
{
    int col = 0;
    for(int a = 1; a <= c; a++)
    {
        for(int i = 1; i <= c; i++)
        {
            for(int j = 1; j <= r; j++)
            {
                if((m[j][i] == ' ') || (m[j][i] == 'a')) col++;
            }
            if(col == r)
            {
                for(int k = i; k <= c; k++)
                {
                    for(int l = 1; l <= r; l++) m[l][k] = m[l][k+1];
                }
            }
            col = 0;
        }
    }
}

int punteggio(int celle_scoperte)
{
    if(celle_scoperte > 2) return ((celle_scoperte - 2) * (celle_scoperte - 2));
    else return 0;
}

int main()
{
    srand((unsigned)time(NULL));

    int in_r, in_c;
    int r = 6, c = 8;
    int punteggio_tot = 0;
    char m[12+2][16+2];
    for(int i = 0; i <= r; i++)
    {
        for(int j = 0; j <= c+(c*c); j++) m[i][j] = 'a';
    }

    char car[5] = {'#', '*', '@', '+', '-'};

    caricamento(m, r, c, car);
    visualizzazione(m, r, c);

    int celle_scoperte = 0;

    do
    {
        cout<<"\nInserire riga: ";
        cin>>in_r;
        cout<<"Inserire colonna: ";
        cin>>in_c;

        if((m[in_r][in_c] != 'a') && (m[in_r][in_c] != ' '))
        {
            scopri_celle(m, in_r, in_c, m[in_r][in_c], celle_scoperte);
            sposta_basso(m, r, c);
            sposta_sinistra(m, r, c);
            punteggio_tot += punteggio(celle_scoperte);
            cout<<endl;
            visualizzazione(m, r, c);
            celle_scoperte = 0;
            cout<<"\nIl tuo punteggio e': "<<punteggio_tot<<endl;
        }
        else
        {
            cout<<endl;
            visualizzazione(m, r, c);
        }
    }
    while(vittoria(m, r, c));

    int cont = 0;
    for(int i = 1; i <= c; i++)
    {
        for(int j = 1; j <= r; j++)
        {
            if(m[i][j] == ' ') cont++;
        }
    }
    if(cont == (12*16)) cout<<"\nComplimenti hai vinto!";

    cout<<"\nIl tuo punteggio finale e': "<<punteggio_tot<<endl;

    return 0;
}
