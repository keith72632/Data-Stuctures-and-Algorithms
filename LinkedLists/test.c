#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first;

void create(int arr[], int len)
{
    struct Node *temp, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;
    
    for(int i = 1; i < len; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = last->next;
    }
}

void display(struct Node *p)
{
    if(p != NULL)
    {
        printf("%d\n", p->data);
        display(p->next);
    }
}

void insert(struct Node *p, struct Node **ptr, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(*ptr == NULL)
        *ptr = t;
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4};
    create(A, 4);
    insert(first, &first, 10);
    insert(first, &first, 6);
    insert(first, &first, 11);
    insert(first, &first,  7);
    display(first); 
    return 0;
}
