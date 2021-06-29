/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*head;

void listInit(int A[], int len)
{
    struct Node *temp = NULL, *tail = NULL;
    //init head
    head = (struct Node*)malloc(sizeof(struct Node));
    tail = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = A[0];
    head->next = NULL;
    tail = head;
    
    for(int i = 1; i < len; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
        
    }
}


void listDisplay(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    
    listInit(A, 5);
    
    listDisplay(head);

    return 0;
}
