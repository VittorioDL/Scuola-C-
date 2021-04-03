#include <iostream>

using namespace std;

int main()
{
    cout<<"Inserire un valore: "<<endl;
    int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        cout<<"X";
    }

    for (int a = 1; a < n; a++)
    {
        if (n % a == 0)
        {   cout<<"Divisore: "<<endl;

            for (int b = 1; b <= a; b++)
            {
                cout<<"X";
            }

            cout<<""<<endl;
            cout<<""<<endl;
        }
    }
    return 0;
}
