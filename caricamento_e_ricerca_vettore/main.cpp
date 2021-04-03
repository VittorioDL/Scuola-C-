#include <iostream>

using namespace std;
bool cercavalore(int lista[], int vals, int valoredacercare)
{
    for(int i = 1; i <= vals; i++)
    {
        if(lista[i] == valoredacercare) return true;
    }
    return false;
}
int main()
{
    int N, val;
    cout<<"Quanti valori vuoi inserire? " << endl;
    cin>> N;
    if(N > 30) N = 30;

    int lista[N+1];
    for(int i =1; i <= N; i++) cin>>lista[i];


    cout<<"\nInserire valore da cercare: " << endl;
    cin>> val;

    if(cercavalore(lista, N, val)) cout<<"Il valore "<<val<<" e' presente nel vettore";
    else cout<<"Il valore "<<val<<" non e' presente nel vettore";

    return 0;
}
