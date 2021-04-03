#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, div;

    cout<<"Inserire il valore di partenza: "<<endl;
    cin>> a;

    cout<<"Inserire il valore finale: "<<endl;
    cin>>b;

    if (a > b)
    {
        c = a;
        a = b;
        b = c;
    }


    for (d = a + 1; d <= b; d++)
    {


        for (int i = 2; i < d; i++)
        {
            if (d % i == 0)
            {
                div++;
            }
        }

        if (div == 0)
        {
            cout<< d <<endl;
        }

        div = 0;

    }

   return 0;
}
