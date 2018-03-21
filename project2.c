#include"project2.h"
#include<stdio.h>
#include<string.h>


int getCommand()
{
	printf("\n1: Create an empty list \t 2: Insert a product\n"
	       "3: Delete a product	\t 4: Delete the entire list\n"
	       "5: Search a product 	\t 6: Display products in the list\n"
	       "7: Purchase a product	\t 8: Sell a product\n"
	       "9: Save to file		\t 0: Exit\n"	);
	
	return getInt();
}

char *getString(char* str)
{
	char *p;
	if (fgets(str, sizeof(str), stdin) != NULL)
	{
		if ((p = strchr(str, '\n')) != NULL)
			*p = '\0';
	}

	return str;
}

int getInt()
{
	int result, number;
	do
	{
		char input[1024];
		fgets(input, sizeof(input), stdin);
		result = sscanf(input, "%d", &number);
		if (result < 1)
			printf("Enter a valid integer\n");
	}
	while (result < 1);
		
	return number;
}

void main()
{
	int input;
	input = getCommand();
	struct product *head;
	struct product *current;
	struct product *temp;
	struct product *prev;
	while (input != 0)
	{
		if (input == 1)
		{
			head =	init();
			printf("Product list created\n");
		}
		else if (input == 2)
		{
			printf("Enter product name: ");
			char input[99];
			char* name = getString(input);
			char input1[99];
			printf("Enter product unit: ");
			char *unit = getString(input1);
			printf("Enter price: ");
			int price = getInt();
			printf("Enter quantity: ");
			int quantity = getInt();
			insert(head, name, unit, price, quantity);
			printf("Product entered\n");
		}
		else if (input == 3)
		{
			printf("Enter product name: ");
			char input[99];
			char* name = getString(input);
			current = search(head, name);
			if (current != NULL)
			{
				deleteProduct(head, current);
			//	printf("Product deleted.\n");
			}
			else printf("Could not find product\n");
		}
		else if (input == 4)
		{
			deleteAll(head);
			printf("Product list deleted\n");
		}
		else if (input == 5)
		{
			printf("Enter product name: ");
			char name[99];
			char *p;
			if (fgets(name, sizeof(name), stdin) != NULL)
			{
				if ((p = strchr(name, '\n')) != NULL)
					*p = '\0';
			}
			current = search(head, name);
			if (current != NULL)
				printf("Product found\n");
			else printf("Could not find product\n");
		}
		else if (input == 6)
		{
			printf("\nProducts:\n");
			display(head);
		}
		else if (input == 7)
		{
			printf("Enter product name: ");
			char input[99];
			char*name = getString(input);
			current = search(head, name);
			if (current != NULL)
			{
				current->quantity = current->quantity + 1;
				printf("One product purchased.\n");
			}
			else printf("Unable to find product.\n");
		}
		else if (input == 8)
		{
			printf("Enter product name: ");
			char input[99];
			char *name = getString(input);
			current = search(head, name);
			if (current != NULL)
			{
				current->quantity = current->quantity -1;
				printf("One product sold.\n");
				if (current->quantity == 0)
				{
					deleteProduct(head, current);
					printf("Product removed\n");
				}
			}
			else printf("Unable to find product.\n");
		}
		else if (input == 9)
		{
			saveToFile(head);
			printf("Saved\n");
		}
		input = getCommand();
	}
	exit(0);
}


