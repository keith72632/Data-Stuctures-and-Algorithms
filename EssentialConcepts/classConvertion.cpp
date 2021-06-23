#include <iostream>

using namespace std;

/* C style structs
struct Rectangle {
    int length;
    int width;
};

void initialize(struct Rectangle *r, int length, int width)
{
    r->length = length;
    r->width = width;
}

int area(struct Rectangle *r)
{
    return r->length * r->width;
}

void changeLength(struct Rectangle *r, int length, int width)
{
    r->length = length;
    r->width = width;
}

*/

class Rectangle
{
    private:
        int length;
        int width;
    public:
        Rectangle(int a, int b)
        {
            length = a;
            width = b;   
        };
        void changeSize(int length, int width);
        int getLength();
        int getWidth();
};

void Rectangle::changeSize(int a, int b)
{
    length = a;
    width = b;
}

int Rectangle::getLength()
{
    return length;
}

int Rectangle::getWidth()
{
    return width;
}
int main()
{
    /* C style
    struct Rectangle r;
    initialize(&r, 10, 20);

    cout << r.length << endl << r.width << endl;

    changeLength(&r, 20, 30);

    cout << "New Length " << r.length << endl;
    */
    Rectangle r(40, 50);


    cout << r.getLength() << endl;
    cout << r.getWidth() << endl;

    r.changeSize(10, 20);

    cout << r.getLength() << endl;
    cout << r.getWidth() << endl;

    return 0;
}
