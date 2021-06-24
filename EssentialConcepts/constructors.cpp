#include <iostream>

using namespace std;

class Rectangle
{
    private:
        int length;
        int width;
    public:
        Rectangle(int len, int wid);
        int getRectangle();
        ~Rectangle();
};

Rectangle::Rectangle(int len, int wid)
{
    length = len;
    width = wid;
}

int Rectangle::getRectangle()
{
    return length * width;
}

Rectangle::~Rectangle(){};

int main()
{
    Rectangle r(20, 40);

    cout << r.getRectangle() << endl;
    r.~Rectangle();
    return 0;
}


