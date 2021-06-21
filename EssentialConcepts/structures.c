#include <stdio.h>

struct Rectangle 
{
    int height;
    int width;
};

int main()
{
    struct Rectangle r1 = {10, 4};

    printf("Size of Rectangle:  %ld\n", sizeof(r1));
    printf("R1 height :%d\n", r1.height);


    return 0;
}
