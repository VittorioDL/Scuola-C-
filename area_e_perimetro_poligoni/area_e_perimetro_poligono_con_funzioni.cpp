#include <iostream>
#include <cmath>
#define PI_GRECO 3.14159265

using namespace std;

double calcolo_area(int n_lati, int lunghezza)
{
    double numero_fisso, apotema, numero_fisso_2;
    int perimetro;
    perimetro = n_lati * lunghezza;
    numero_fisso = tan(PI_GRECO / n_lati);
    numero_fisso_2 = 1/(2 * numero_fisso);
    apotema = numero_fisso_2 * lunghezza;
    return (perimetro * apotema)/2; // Formula dell area
}

int calcolo_perimetro(int n_lati, int lunghezza)
{
    return n_lati * lunghezza;
}

int main()
{
    int n_lati, lunghezza;
    cout<<"Numero dei lati: ";
    cin>>n_lati;
    cout<<"Lunghezza del lato: ";
    cin>>lunghezza;
    cout<<"Il perimetro e': ";
    cout<<calcolo_perimetro(n_lati, lunghezza)<<endl;
    cout<<"L'area e': ";
    cout<<calcolo_area(n_lati, lunghezza);
    return 0;
}
