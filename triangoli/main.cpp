#include <iostream>
#include <math.h>

using namespace std;

double areaRettangolo(double a, double b)
{
    return a*b;
}

double radiceQuadrata(double radice)
{
    return sqrt(radice);
}

int main()
{
    float a, b, c;
    cout<<radiceQuadrata(9);
    cout<<"Inserire il primo lato del triangolo:"<<endl;
    cin>> a;

    cout<<"Inserire il secondo lato del triangolo:"<<endl;
    cin>> b;

    cout<<"Inserire il terzo lato del triangolo:"<<endl;
    cin>> c;

    if ((a < b + c) & (b < a + c) & (c < a + b))
    {
        if ((a == b) & (b == c))
        {
            cout<<"Il triangolo è equilatero"<<endl;
        }

        else if ((a == b) | (a == c) | (b == c))
        {
            cout<<"Il triangolo è isoscele"<<endl;
        }

        else if ((a*a + b*b == c*c) | (b*b + c*c == a*a) | (a*a + c*c == b*b))
        {
            cout<<"Il triangolo è rettangolo"<<endl;
        }

        else
        {
            cout<<"Il triangolo è scaleno"<<endl;
        }
    }

    else
    {
        cout<<"I valori sono impossibili"<<endl;
    }




    return 0;
}
