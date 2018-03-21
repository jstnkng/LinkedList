#include "project2.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct product *init()
{
	struct product *head = (struct product*)malloc(sizeof(struct product));
	head -> next = NULL;
	return head;

}

void insert(struct product *head, char* name, char* unit, int price, int quantity)
{
	struct product *current = (struct product*)malloc(sizeof(struct product));

	strcpy(current->name, name);
	strcpy(current->unit, unit);
	current->price = price;
	current->quantity = quantity;

	if (head->next == NULL)
	{
		head->next = current;
	}	
	else
	{	
		struct product *newProduct = head;
		while (newProduct->next!=NULL)
		{
			newProduct = newProduct->next;
		}
		newProduct->next = current;
	}
}

void display(struct product *head)
{
	head = head->next;
	while (head != NULL)
	{	
		printf("Name: %s\n", head->name);
		printf("Unit: %s\n", head->unit);
		printf("Price: %d\n", head->price);
		printf("Quantity: %d\n", head->quantity);
		head = head->next;
	}
}

struct product *search (struct product *head, char* name)
{
	while (head != NULL)
	{
		if (strcmp(head->name, name) == 0)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}

int sell (struct product *head, char*name)
{
	while (head != NULL)
	{
		if (strcmp(head->name, name) == 0)
		{
			head -> quantity = head->quantity - 1;
			return 1;
		}
		head = head->next;
	}
	return 0;
}

int buy (struct product *head, char*name)
{
	while (head != NULL)
	{
		if (strcmp(head->name,name) == 0)
		{
			head -> quantity = head->quantity + 1;
			return 1;
		}
		head = head->next;
	}
	return 0;
}

void deleteProduct (struct product *head, struct product* n)
{
	//if (head == n)
	//{
	//	if (head->next == NULL)
	//	{
	//		printf("Unable to delete single node\n");
	//		return;
	//	}
		
	//	head->name = head->next->name;
	//	head->unit = head->next->unit;
	//	head->price = head->next->price;
	//	head->quantity = head->next->quantity;
	//
	//	n = head->next;

	//	head->next = head->next->next;
	//}

	struct product* prev;
	prev = head;
	while (prev->next != NULL && prev->next != n)
	{
		prev = prev->next;
	}
	prev->next = prev->next->next;
	free(n);
	printf("Product deleted.\n");
	return;
}

void deleteAll(struct product *head)
{
	struct product *temp;
	while (head -> next != NULL)
	{
		temp = head;
		head = head-> next;
		free(temp);
	}
}

void saveToFile(struct product *head)
{
	FILE *out = fopen("output.txt", "w");
	if (out != NULL)
	{
		head = head->next;
		while (head != NULL)
		{
			fprintf(out, "%s\n%s\n%d\n%d\n", head->name, head->unit, head->price, head->quantity);
			head = head->next;
		}
	}
	fclose(out);
}
