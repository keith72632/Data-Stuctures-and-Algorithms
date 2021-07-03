#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *a;
struct Node *b;
struct Node *c;
struct Node *d;
struct Node *e;
struct Node *t;

void create(struct Node *p, int array[], int len)
{
    struct Node *last, *temp;
    p->data = array[0];
    p->next = NULL;
    last = p;

    for(int i = 1; i < len; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = array[i];
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

int fact(struct Node *p)
{
    int f = 1;
    if( p == 0) return 0;
    while(p != NULL)
    {
        f *= p->data;
        p = p->next;
    }
    return f;
}

int sum(struct Node *p)
{
    int x = 0;
    while(p != NULL)
    {
        x += p->data;
        p = p->next;
    }
    return x;
}

int rSum(struct Node *p)
{
    int sum = 0;
    if(p != NULL)
    {
        sum = rSum(p->next) + p->data;
    }
    return sum;
}

int rfact(struct Node *p)
{
    int f = 1;
    if(p != NULL)
    {
        f = rfact(p->next) * p->data;
    }
    return f;
}

int max(struct Node *p)
{
    int max = 0;
    while(p)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int rMax(struct Node *p)
{
    int max = 0;
    if(p == NULL) return 0;
    else
    {
       max = rMax(p->next);
       if(p->data > max)
           max = p->data;
    }
    return max;
}

struct Node *search(struct Node *p, int key)
{
    struct Node *first = p;
    while(p != NULL)
    {
        if(key == p->data)
        {
            first = p;
            return first;
        }
        p = p->next;
    }
    return NULL;
}

struct Node *searchRec(struct Node *p, int key)
{
    if(p == NULL) return 0;
    if(key == p->data)
    {
        return p;
    }
    return searchRec(p->next, key);
}

int count(struct Node *p)
{
    int c = 0;
    while(p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void insert(struct Node *p, int data, int pos)
{
    struct Node *temp;
    if(pos < 1 || pos > count(p))
    {
        printf("incorrect postion");
        return;
    }
    
    temp = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;

    if(pos == 0)
    {
        temp->next = p;
        p = temp;
    }
    else 
    {
        for(int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4};
    int B[] = {5, 6, 7, 8};
    int C[] = {6, 6, 6};
    int lenA, lenB, lenC;
    lenA = sizeof(A) / 4;
    lenB = sizeof(B) / 4;
    lenC = sizeof(C) / 4;
    a = (struct Node *)malloc(sizeof(struct Node));
    b = (struct Node *)malloc(sizeof(struct Node));
    c = (struct Node *)malloc(sizeof(struct Node));
    d = (struct Node *)malloc(sizeof(struct Node));
    e = (struct Node *)malloc(sizeof(struct Node));
    create(a, A, lenA);
    create(b, B, lenB);
    create(c, C, lenC);
    display(a);
    display(b);
    display(c);
    /*
    int fac = rfact(a);
    int sumN = rSum(a);
    printf("Sum of data in nodes %d\n", sum(a));
    printf("Factorial of data in nodes %d\n", fact(a));
    printf("Factorial using recursion %d\n", fac);
    printf("Sum of Nodes using recursion %d\n", sumN);

    int maxNum = max(a);
    printf("Max without recursion %d\n", maxNum);
    int maxRe = rMax(a);
    printf("Max with recursion %d\n", maxRe);

    d = search(a, 1);
    e = searchRec(a, 2);
    printf("Search without recursion. Data: %d Address %p\n", d->data, d->next);
    printf("Search with recursion. Data: %d Address: %p\n", e->data, e->next);
    
    int numNodes = count(a);
    printf("Number of nodes: %d\n",numNodes);
    */

    insert(a, 66, 2);
    display(a);
}
