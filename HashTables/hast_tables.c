#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct Item
{
	int data;
	int key;
};

struct Item *hashArray[SIZE];
struct Item *dummyItem;
struct Item *item;

int hashCode(int key)
{
	return key % SIZE;
}

struct Item *search(int key)
{
	//get the hash
	int hashIndex = hashCode(key);

	//move through array until empty
	while(hashArray[hashIndex] != NULL)
	{
		if(hashArray[hashIndex]->key == key)
		{
			return hashArray[hashIndex];
		}

		//next cell
		++hashIndex;

		//wrap around the table
		hashIndex %= SIZE;
	}

	return NULL;
}

void insert(int key, int data)
{
	struct Item *item = (struct Item*)malloc(sizeof(struct Item));
	item->data = data;
	item->key = key;

	//get the hash
	int hashIndex = hashCode(key);

	//move through array until empty cell
	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
	{
		++hashIndex;

		//wrap around the table
		hashIndex %= SIZE;
	}

	hashArray[hashIndex] = item;

}

struct Item *delete(struct Item *item)
{
	int key = item->key;

	//get the hash
	int hashIndex = hashCode(key);

	//move through until an empty
	while(hashArray[hashIndex] != NULL)
	{
		if(hashArray[hashIndex]->key == key)
		{
			struct Item *temp = hashArray[hashIndex];

			//assign a dummy item at deleted position
			hashArray[hashIndex] = dummyItem;
			return temp;
		}

		//go to next cell
		++hashIndex;

		//wrap around the table
		hashIndex %= SIZE;
	}

	return NULL;
}

void display()
{
	for(int i = 0; i < SIZE; i++)
	{
		if(hashArray[i] != NULL)
		{
			printf(" (key: %d, data: %d)\n", hashArray[i]->key, hashArray[i]->data);
		}
		else
		{
			printf("~~\n");
		}
	}
}
int main()
{
	dummyItem = (struct Item*)malloc(sizeof(struct Item));
	dummyItem->data = -1;
	dummyItem->key  = -1;

	insert(1, 30);
	insert(2, 55);
	insert(3, 66);
	insert(4, 88);

	display();

	item = search(3);

	if(item != NULL)
	{
		printf("Key: %d, Data: %d\n", item->key, item->data);
	}

	else
		printf("No element at this key\n");

	delete(item);

	printf("Item deleted\n");
	display();

	return 0;
}