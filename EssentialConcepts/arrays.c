#include <stdio.h>

int main()
{
    int A[] = {6, 7, 8, 9, 2, 3, 4};
    printf("Size of array :%ld\n", sizeof(A)); 
    for(int i = 0; i < 7; i++)
    {
        printf("Element %d = %d\n", i, A[i]);
    }
    return 0;
}
