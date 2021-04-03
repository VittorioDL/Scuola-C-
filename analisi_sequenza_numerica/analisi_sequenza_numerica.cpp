#include <iostream>

using namespace std;

int CrescDecreCasuale(int lista[], int vals)
{
    bool checkCresc = true, checkDecr = true;
    for(int i = 1; i <= vals-1; i++)
    {
        if(lista[i] <= lista[i+1]) checkDecr = false;
        else checkCresc = false;
    }

    if(checkCresc) return 1;
    else if(checkDecr) return 2;
    else return 3;
}

int main()
{
    int N;

    cout<<"Quanti valori vuoi analizzare? ";
    cin>>N;

    int lista[N+1];
    for(int i = 1; i <= N; i++)
    {
        cout<<"\nInserire un valore: ";
        cin>>lista[i];
    }

    cout<<"Numero di valori positivi, nulli e negativi: "<<N<<endl;
    cout<<"Numero di valori pari e dispari: "<<N<<endl;

    if(CrescDecreCasuale(lista, N) == 1) cout<<"La lista e' in ordine crescente";
    else if(CrescDecreCasuale(lista, N) == 2) cout<<"La lista e' in ordine decrescente";
    else cout<<"La lista non ha un ordine";

    return 0;
}
