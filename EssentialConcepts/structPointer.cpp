#include <iostream>
#include <stdlib.h>

struct Rectangle
{
    int length;
    int width;
};

using namespace std;
int main()
{
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    p5 = (struct Rectangle*)malloc(sizeof(struct Rectangle));
    p5 = new Rectangle{10, 4};

    //every pointer will be 8 bytes(32 bits) in size
    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;

    cout << p5->length << endl;
    cout << p5->width << endl;

    free(p5);
    return 0;
}
