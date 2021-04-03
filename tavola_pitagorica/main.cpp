#include <iostream>

using namespace std;

int main()
{
    int a, b, i;

    for (a = 1; a <= 12; a++)
    {
        for (b = 1; b <= 12; b++)
        {
            i = b * a;

            if (i < 10)
            {
                cout<<"   ";
            }

            if (i >= 10 & i < 100)
            {
                cout<<"  ";
            }

            if (i >= 100)
            {
                cout<<" ";
            }


            cout<<i;


            if (b == 12)
            {
                cout<<""<<endl;
            }



        }

    }
    return 0;
}
