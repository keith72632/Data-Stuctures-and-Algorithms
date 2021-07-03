#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// linked list consists of at least two parts, the data stored in the node and a pointer pointing to the next
struct Node 
{
	int data;
	struct Node *next;
};

struct Node *first;
struct Node *second;
struct Node *third;

void create(struct Node *ptr, int Arr[], int len)
{
	int i;
	struct Node *last, *temp;
	//ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->data = Arr[0];
	ptr->next = NULL;
	last = ptr;
	
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

int sum_nodes(struct Node *p)
{
	if(p == NULL) return 0;

	else return sum_nodes(p->next) + p->data;
}

int max_data(struct Node *p)
{
	int m;
	while(p)
	{
		if(p->data > m)
			m = p->data;
		p = p->next;
	}
	return m;
}

//recursive
int max(struct Node *p)
{
	int x = 0;
	if(p == NULL)
		return INT_MIN;
	else
	{
		x = max(p->next);
		//if next data is greater than current
		if(p->data > x)
			x = p->data;
	}
    return x;

}

void find(struct Node *p, int n)
{
	while(p != NULL)
	{
		int x = 1;
		if(p->data == n)
		{
			printf("Value found at node: %d\n", x);
			break;
		}
		else
		{
			p = p->next;
			x++;
		}
	}
}

int main()
{
	int A[] = {1, 2, 3, 4};
	int B[] = {5, 5, 6, 6};
	int C[] = {11, 5, 3, 1};
	
	//must be allocated inside function, or will throw error
	first = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));


	create(first, A, 4);
	create(second, B, 4);
	create(third, C, 4);
	
	display(first);
	display(second);
	display(third);

	// int num_nodes_first = count_nodes_r(first);
	// int num_nodes_second = count_nodes_r(second);
	// int num_nodes_third = count_nodes_r(third);

	// printf("Number of nodes in first using recursion %d\n", num_nodes_first);
	// printf("Number of nodes in second using recursion %d\n", num_nodes_second);
	// printf("Number of nodes in third using recursion %d\n", num_nodes_third);

	// num_nodes_first = count_nodes(first);
	// num_nodes_second = count_nodes(second);
	// num_nodes_third = count_nodes(third);

	// printf("Number of nodes in first without using Recursion %d\n", num_nodes_first);
	// printf("Number of nodes in second without using Recursion %d\n", num_nodes_second);
	// printf("Number of nodes in third without using Recursion %d\n", num_nodes_third);

	// int sum_first = sum_nodes(first);
	// int sum_second = sum_nodes(second);
	// int sum_third = sum_nodes(third);

	// printf("Sum of nodes: %d\n", sum_first);
	// printf("Sum of nodes: %d\n", sum_second);
	// printf("Sum of nodes: %d\n", sum_third);

	int max_first = max(first);
	int max_second = max(second);
	int max_third = max(third);
	printf("Max element in first: %d\n", max_first);
	printf("Max element in second: %d\n", max_second);
	printf("Max element in third: %d\n", max_third);

	find(third, 1);
    find(first, 2);
    find(second, 6);
	return 0;
}
