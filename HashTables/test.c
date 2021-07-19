#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

#define ITEM(n) struct Item *item##n
struct Item
{
	int key;
	int data;
};

struct Item *hash_array[SIZE];
struct Item *item;
struct Item *dummy_item;

void insert(int key, int data)
{
	item = (struct Item*)malloc(sizeof(struct Item));
	item->data = data;
	item->key = key;

	int index = key % SIZE;

	while(hash_array[index] != NULL && hash_array[index]->data != -1)
	{
		++index;

		//wrap around table
		index %= SIZE;
	}

	hash_array[index] = item;
}

void display()
{
	for(int i = 0; i < SIZE; i++)
	{
		if(hash_array[i] != NULL)
			printf("key: %d. data: %d\n", hash_array[i]->key, hash_array[i]->data);
		else
			printf("~~\n");
	}
}


int main()
{
	ITEM(1);

	item1->data = 100;
	item1->key = 1;

	insert(item1->key, item1->data);

	insert(2, 300);
	insert(3, 400);
	insert(5, 600);
	insert(7, 700);

	display();

}