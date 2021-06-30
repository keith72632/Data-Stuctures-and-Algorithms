#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
}*first;

void create(int Arr[], int len)
{
	int i;
	struct Node *last, *temp;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = Arr[0];
	first->next = NULL;
	last = first;
	
	for(i = 1; i < len; i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = Arr[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void display(struct Node *p)
{
	if(p != NULL)
	{
		printf("%d ", p->data);
		display(p->next);
		//transpose these two line to display in reverse
	}
}

int count_nodes(struct Node *p)
{
	int cnt = 0;
	while(p != NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}

//recursive function time O(N)
int count_nodes_r(struct Node *p)
{
	if(p == NULL) return 0;
	
	else return count_nodes_r(p->next) + 1;
}

int main()
{
	int A[] = {1, 2, 3, 4};
	
	create(A, 4);
	
	display(first);

	int num_nodes = count_nodes_r(first);

	printf("Number of nodes using recursion %d\n", num_nodes);

	num_nodes = count_nodes(first);

	printf("Number of nodes without using Recursion %d\n", num_nodes);

	return 0;
}
