#include <stdio.h>
#include <stdlib.h>

#define PRINT_NL()(printf("\n"))

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first;
struct Node *second;
struct Node *third;
struct Node *head;
struct Node *head2;
struct Node *head3;

void create(struct Node **head_ref, int arr[], int len)
{
    struct Node *temp, *last;
    *head_ref = (struct Node*)malloc(sizeof(struct Node));
    (*head_ref)->data = arr[0];
    (*head_ref)->next = NULL;
    last = *head_ref;
    
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
void deleteKey(struct Node **head_ref, int key)
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

void remove_list_entry(struct Node **head_ref, int key)
{
    struct Node *prev, *walk;
    walk = *head_ref;

    if(walk != NULL && walk->data == key)
    {
        *head_ref = walk->next;
        return;
    }

    while(walk != NULL && walk->data != key)
    {
        prev = walk;
        walk = walk->next;
    }

    prev->next = walk->next;
}

void remove_list_index(struct Node **head_ref, int index)
{
    struct Node *prev, *walk;
    walk = *head_ref;

    if(index == 0 && index < count(walk))
    {
        *head_ref = walk->next;
        return;
    }
    //if using 1 based indexing, then decrement index once before while loop
    index--;
    while(index--)
    {
        prev = walk;
        walk = walk->next;
    }

    prev->next = walk->next;

}

int is_sorted(struct Node *p)
{
    int x = INT_MIN;
    while(p != NULL)
    {
        if(p->data < x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

void remove_duplicated(struct Node **head_ref)
{
    struct Node *prev, *first;
    prev = *head_ref;
    first = (*head_ref)->next;

    while(first != NULL)
    {
        if(prev->data != first->data)
        {
            prev = first;
            first = first->next;
        }
        else
        {
            prev->next = first->next;
            first = prev->next;
        }
    }
}

//Time O(N) and needs space for array
void reverse_list(struct Node **head_ref)
{
    struct Node *p;
    p = *head_ref;
    int n = count_rec(p);
    int *data = (int *)malloc(sizeof(int) * count(p));
    size_t i = 0;

    while(p != NULL)
    {
        data[i] = p->data;
        p = p->next;
        i++;
    }
    //reset temp pointer at beginning of head
    p = *head_ref;
    while(i--)
    {
        p->data = data[i];
        p = p->next;
    }
}

//Sliding Pointers
void reverse_sliding(struct Node **head_ref)
{
    struct Node *p, *q, *r;
    p = *head_ref;
    q = NULL;
    r = NULL;

    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    //set head to q, because this algorithm runs backwards until p is NULL, which makes q the first node.
    *head_ref = q;
}

void reverse_recursion(struct Node **head_ref, struct Node *q)
{
    struct Node *p;
    p = *head_ref;

    if(p)
    {
        reverse_recursion(head_ref, p->next);
    }
    else 
        *head_ref = q;
}

void append(struct Node **head_ref, int data)
{
    struct Node *p, *temp;
    p = *head_ref;

    temp = (struct Node*)malloc(sizeof(struct Node));
    
    if(p != NULL)
    {
        temp->data = data;
        temp->next = NULL;
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}

struct Node *top(struct Node **head_ref)
{
    struct Node *p, *temp;
    p = *head_ref;
    temp = (struct Node*)malloc(sizeof(struct Node));

    if(p != NULL)
    {
        //find last node
        while(p->next != NULL)
        {
            temp = p;
            p = p->next;
        }
        //delete popped node
        temp->next = p->next;
        //return popped node
        return p;
    }
}

void push(struct Node **head_ref, struct Node *p)
{

    p->next = *head_ref;
    *head_ref = p;
}

struct Node *pop(struct Node **head_ref)
{
    struct Node *node, *walk;
    node = *head_ref;
    walk = *head_ref;
    *head_ref = (*head_ref)->next;
    walk->next = (*head_ref)->next;
    return node;
}

//leetCode
struct Node *mergeTwoLists(struct Node *l1, struct Node *l2)
{
    struct Node head;
    struct Node *p = &head;
    
    if (l1 == NULL && l2 == NULL)
        return NULL;
    
    //walk through both lists until onen is null
    while (l1 && l2) {
        if (l1->data < l2->data) {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        } else {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }
    }
    
    //see if there are any remaining nodes for l1 or l2. add to list
    if (l1) {
        p->next = l1;
    }

    if (l2) {
        p->next = l2;
    }
  
    return head.next;
}

void mergeLists(struct Node **head1, struct Node **head2, struct Node **head3)
{
    struct Node *h1, *h2, *h3, *last;
    h1 = *head1;
    h2 = *head2;
    last = *head3;

    if(h1->data < h2->data)
    {
        third = last = h1;
        h1 = h1->next;
        third->next = NULL;
    }
    else
    {
        third = last = h2;
        h2 = h2->next;
        third->next = NULL;
    }

    while(h1 && h2)
    {
        if(h1->data < h2->data)
        {
            last->next = h1;
            last = h1;
            h1 = h1->next;
            last->next = NULL;
        }
        else
        {
            last->next = h2;
            last = h2;
            h2 = h2->next;
            last->next = NULL;           
        }
    }
    if(h1)last->next = h1;
    if(h2)last->next = h2;
}

void *cat(struct Node **l1, struct Node **l2)
{
    struct Node *q, *p;
    p = *l1; 
    q = *l2;
    
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void main()
{
    int A[] = {1, 2, 3, 4};
    int B[] = {7, 4, 9, 3};
    int sort;
    head = first;
    head2 = second;
    head3 = third;
    create(&head, A, 4);
    create(&head2, B, 4);
    insert_sorted(&head, 10);
    insert_sorted(&head, 4);
    printf("Created first List and Inserted 10:\n");
    display(head);
    PRINT_NL();
    printf("Created Second List:\n");
    display(head2);
    PRINT_NL();

    cat(&head, &head2);
    printf("Concatonated two lists:\n");
    display(head);
    PRINT_NL();

    mergeLists(&head, &head2, &head3);
    printf("Two lists merged:\n");
    display(head3);

    // printf("Removed duplicates\n");
    // remove_duplicated(&head);
    // display(head);
    // PRINT_NL();

    // printf("Reversed List\n");
    // reverse_sliding(&head);
    // display(head);
    // PRINT_NL();

    // printf("Append to end of list\n");
    // append(&head, 12);
    // display(head);
    // PRINT_NL();

    // printf("Trim function\n");
    struct Node *temp; 
    // temp = trim(&head);
    // printf("First Trimmed data: %d\n", temp->data);
    // PRINT_NL();

    // temp = trim(&head);
    // printf("Second Trimmed Data: %d\n", temp->data);
    // PRINT_NL();

    // temp = trim(&head);
    // printf("Third Trimmed Data: %d\n", temp->data);
    // PRINT_NL();

    // printf("Remaining Nodes\n");
    // display(head);
    // PRINT_NL();

    // printf("Popping Node\n");

    // struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    // new->data = 69;
    // new->next = head;

    // temp = pop(&head);
    // printf("Temp Popped data: %d\n", temp->data);
    // display(head);
    // PRINT_NL();

    // printf("Pushing Node With data: %d\n", temp->data);
    // push(&head, temp);
    // display(head);
    // PRINT_NL();

    // sort = is_sorted(head);
    // printf("\nIs sorted? : %d\n", sort);

  
}
