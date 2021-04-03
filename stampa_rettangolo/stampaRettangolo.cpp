#include <iostream>

using namespace std;

char scelta()
{
    char scelta;
    cout << "Per stampare un rettangolo pieno scrivere: P\nPer stampare un rettangolo vuoto scrivere: V"<<endl;
    cin >> scelta;
    return scelta;
}

void stampaRettangolo(int l,int h)
{
    switch(scelta())
    {
        case 'P': for (int i = 1; i <= h; i++)
                  {
                     for (int i = 1; i <= l; i++)
                     {
                        cout<<"*";
                     }
                     cout<<"\n";
                  };break;

        case 'V': for (int i = 1; i <= l; i++)
                  {
                      cout<<"*";
                  }
                  cout<<"\n";

                  for (int i = 1; i <= h-2; i++)
                  {
                      cout<<"*";
                      for (int i = 1; i <= l-2; i++)
                      {
                         cout<<" ";
                      }
                      cout<<"*";
                      cout<<"\n";
                  }
                  for (int i = 1; i <= l; i++)
                  {
                      cout<<"*";
                  };break;
    }
}

int main()
{
    int l, h;
    cout << "Inserire la lunghezza del rettangolo: " << endl;
    cin >> l;
    cout << "Inserire l'altezza del rettangolo: " << endl;
    cin >> h;
    stampaRettangolo(l, h);
    return 0;
}
