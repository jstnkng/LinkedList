#include <stdio.h>
#include<stdlib.h>

#ifndef PROJECT2_H
#define PROJECT2_H

struct product
{
	char name[99];
	char unit[99];
	int price;
	int quantity;
	struct product *next;

};

struct product *init();

void insert(struct product *head, char* name, char *unit, int price, int quantity);

void display(struct product *head);

void deleteAll(struct product* head);

struct product* search(struct product *head, char *name);

int sell (struct product *head, char*name);

int buy (struct product *head, char*name);

void deleteProduct(struct product *head, struct product* n);

void saveToFile(struct product*head);
#endif
