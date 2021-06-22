#include <stdio.h>

int main()
{
    int a = 10;
    int *p = &a;

    printf("Address in pointer: %p\n", p);
   printf("Value in pointer: %d\n", *p); 
    return 0;
}
