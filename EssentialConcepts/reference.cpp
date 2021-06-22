#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int &r = a;    

    cout << a << endl << r << endl;

    r++;

    cout << a << endl << r << endl;

    int b = 30;
    r = b;

    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    cout << "R = " << r << endl;

    r++;

    cout << "Values Incremented " << endl << a << endl << b << endl << r << endl;
    return 0;
}
