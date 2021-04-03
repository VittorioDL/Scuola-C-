#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int cont = 0;

    double temp;

    double medio;
    double somma;
    double minimo;

    ifstream file_numeri;
    file_numeri.open("numeri.txt");

    ofstream file_risultati;
    file_risultati.open("risultati.txt");

    while(!file_numeri.eof())
    {
        file_numeri>>temp;
        if(cont == 0) minimo = temp + 1;

        cont++;

        somma += temp;
        if(temp < minimo) minimo = temp;
    }

    file_risultati<<somma/cont;
    file_risultati<<endl;
    file_risultati<<somma;
    file_risultati<<endl;
    file_risultati<<minimo;

    file_numeri.close();
    file_risultati.close();

    return 0;
}
