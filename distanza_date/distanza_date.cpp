#include <iostream>

using namespace std;

bool bisestile(int a)
{
    if((a % 400) == 0)
    {
        return true;
    }
    else if(((a % 100) != 0) & ((a % 4) == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int giorniAFineAnno(int g, int m, int a)
{
    int tot = 0;
    if(bisestile(a))
    {
        for(int i = 1; i <= m - 1; i++)
        {
            switch(i)
            {
                case 1: tot = tot + 31; break;
                case 2: tot = tot + 29; break;
                case 3: tot = tot + 31; break;
                case 4: tot = tot + 30; break;
                case 5: tot = tot + 31; break;
                case 6: tot = tot + 30; break;
                case 7: tot = tot + 31; break;
                case 8: tot = tot + 31; break;
                case 9: tot = tot + 30; break;
                case 10: tot = tot + 31; break;
                case 11: tot = tot + 30; break;
                case 12: tot = tot + 31; break;

            }
        }
        return 366 - (tot + g);
    }

    else
    {
        for(int i = 1; i <= m - 1; i++)
        {
            switch(i)
            {
                case 1: tot = tot + 31; break;
                case 2: tot = tot + 28; break;
                case 3: tot = tot + 31; break;
                case 4: tot = tot + 30; break;
                case 5: tot = tot + 31; break;
                case 6: tot = tot + 30; break;
                case 7: tot = tot + 31; break;
                case 8: tot = tot + 31; break;
                case 9: tot = tot + 30; break;
                case 10: tot = tot + 31; break;
                case 11: tot = tot + 30; break;
                case 12: tot = tot + 31; break;

            }
        }
        return 365 - (tot + g);
    }
}

int giorniDaInizioAnno(int g, int m, int a)
{
    int tot = 0;
    if(bisestile(a))
    {
        for(int i = 1; i <= m - 1; i++)
        {
            switch(i)
            {
                case 1: tot = tot + 31; break;
                case 2: tot = tot + 29; break;
                case 3: tot = tot + 31; break;
                case 4: tot = tot + 30; break;
                case 5: tot = tot + 31; break;
                case 6: tot = tot + 30; break;
                case 7: tot = tot + 31; break;
                case 8: tot = tot + 31; break;
                case 9: tot = tot + 30; break;
                case 10: tot = tot + 31; break;
                case 11: tot = tot + 30; break;
                case 12: tot = tot + 31; break;

            }
        }
        return tot + g;
    }

    else
    {
        for(int i = 1; i <= m - 1; i++)
        {
            switch(i)
            {
                case 1: tot = tot + 31; break;
                case 2: tot = tot + 28; break;
                case 3: tot = tot + 31; break;
                case 4: tot = tot + 30; break;
                case 5: tot = tot + 31; break;
                case 6: tot = tot + 30; break;
                case 7: tot = tot + 31; break;
                case 8: tot = tot + 31; break;
                case 9: tot = tot + 30; break;
                case 10: tot = tot + 31; break;
                case 11: tot = tot + 30; break;
                case 12: tot = tot + 31; break;

            }
        }
        return tot + g;
    }
}


int main()
{
    int g, m, a;
    cout<< "Inserire la data in formato GG MM AAAA" <<endl;
    cin>> g;
    cin>> m;
    cin>> a;
    cout<< "Giorni a fine anno: " << giorniAFineAnno(g, m, a) <<endl;
    cout<< "Giorni da inizio anno: " << giorniDaInizioAnno(g, m, a) <<endl;
    return 0;
}
