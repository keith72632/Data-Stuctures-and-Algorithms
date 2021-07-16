#include <stdio.h>

void is_zero_down(int n)
{
    if(n == 0)
    {
        printf("is zero\n");
    }
    else
    {
	is_zero_down(n - 1);
	printf("Number: %d\n", n);
    }
}

void is_zero_up(int n)
{
    if(n == 0) printf("is zero\n");

    else
    {
        printf("Number: %d\n", n);
	is_zero_up(n - 1);
    }
}

void loop_thru(char A[])
{
    if(*A)
    {
	printf("%c\n", *A);
	loop_thru(A + 1);
    }
}

void lupe(int *A)
{
    if(*A)
    {
	printf("%d\n", *A);
	lupe(A+1);
    }
}
int main()
{
    int x = 3;
    char A[] = "bitch\n";
    int B[] = {1, 2, 3, 4, 0};
    
    printf("count down\n");
    is_zero_down(x);

    printf("count up\n");
    is_zero_up(x);

    loop_thru(A);

    lupe(B);

    return 0;
}
