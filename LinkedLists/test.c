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

int count_rec(struct Node *p)
{
    if(p == NULL) return 0;

    else return count_rec(p->next) + 1;
}

void insert_index(struct Node **ptr, int index, int x)
{
    struct Node *temp, *p;
    p = *ptr;

    if(index < 0 || index > count(p))
        return;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;

    //first node
    if(index == 0)
    {
        temp->next = *ptr;
        *ptr = temp;
    }
    else
    {
        for(size_t i = 0; i < index -1; i++)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
}

void insert_sorted(struct Node **ptr, int data)
{
    struct Node *t, *p, *q = NULL;
    p = *ptr;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    if(*ptr == NULL)
        *ptr = t;
    else
    {
        //moves to next node while new node is less than data
        while(p && p->data < data)
        {
            q = p;
            p = p->next;
        }
        if(p == *ptr)
        {
            t->next = *ptr;
            *ptr = t;
        }
        else //temp == q, then move q to temp
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

//Delete by index
int delete(struct Node **ptr, int index)
{
    struct Node *q;
    int x = -1;

    if(index < 1 || index > count(*ptr)) return -1 ;

    //first node
    if(index == 1)
    {
        q = *ptr;
        *ptr = (*ptr)->next;
        x = (*ptr)->data;
        free(q);
        return x; 
    }
    else
    {
        for(size_t i = 0; i < index - 1; i++)
        {
            q = *ptr;
            *ptr = (*ptr)->next;
        }
        q->next = (*ptr)->next;
        x = (*ptr)->data;
        free(q);
        return x; 
    }
}

int deleteIndex(struct Node **head_ref, int index)
{
    struct Node *temp = *head_ref;
    struct Node *prev = NULL;

    if(index < 1 || index > count(temp)) return -1;

    if(index == 1)
    {
        *head_ref = temp->next;
        free(temp);
        return (*head_ref)->data;
    }
    else
    {
        for(size_t i = 0; i < index - 1; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;

        free(temp);
        return (*head_ref)->data;

    }
}

//Find node by key and delete
void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref;
    struct Node *prev = NULL;

    //if node itself holds key to be deleted
    if(temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // changed head
        free(temp);             // free old head
        return;
    }
    //else seach for key to be deleted, keep track of the previous node as need
    //to change prev->next;
    else
    {
        while(temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
            return;

        //Unlink node from list
        prev->next = temp->next;

        free(temp);

    }

}

int main()
{
    int A[] = {1, 2, 3, 4};
    create(A, 4);
    insert_sorted(&first, 10);
    insert_sorted(&first, 6);
    insert_sorted(&first, 11);
    insert_sorted(&first, 7);
    display(first); 

    int count_test = count_rec(first);
    printf("Count test %d\n", count_test);
    // insert_index(&first, 3, 7);
    // insert_index(&first, 6, 99);
    // insert_index(&first, 0, 69);
    insert_sorted(&first, 5);
    insert_sorted(&first, 5);
    display(first);

    // int del = delete(&first, 7);
    // printf("Delete Status = %d\n", del);
    // deleteNode(&first, 1);
    int del = deleteIndex(&first, 2);
    printf("Delete status = %d\n", del);
    display(first);
    return 0;
}
