#include "vec.h"

int main()
{

    myVector v;

    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
        cout << v;
    }

    myVector cp{v};
    cout << endl;
    cout << cp << endl;

    myVector w{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << w << endl;

    return 0;
}