#include <iostream>

using namespace std;

int a = 10;

void addTwo(int num)
{
    num += 2;
    a += 2;
}
int main()
{
    //this will change the value without returning from function.
    addTwo(a);

    cout << a << endl; 
    return 0;
}
