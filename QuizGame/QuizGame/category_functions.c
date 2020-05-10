#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#include "category_structure.h"

struct categories* create_category_list(struct categories** list_pointer, char* data) {
	struct categories* nowy = (struct categories*)malloc(sizeof(struct categories));
	for (int i = 0; i < 128; i++)
		nowy->NameCategory[i] = data[i];
	nowy->id = 1;
	nowy->pNext = nowy;
	*list_pointer = nowy;
	return *list_pointer;
}

void create_and_add_category(struct categories** lista_pointer, char* data, struct categories** head) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head)
			create_and_add_category(&(*lista_pointer)->pNext, data, head);
		else {
			struct categories* nowy = (struct categories*)malloc(sizeof(struct categories));
			for (int i = 0; i < 128; i++)
				nowy->NameCategory[i] = data[i];
			nowy->id = (*lista_pointer)->id + 1;
			(*lista_pointer)->pNext = nowy;
			nowy->pNext = *head;
		}
	}
	else
		create_category_list(lista_pointer, data);
}

void print_categories(struct categories* lista_pointer, struct categories* head) {
	if (lista_pointer) {
		if (lista_pointer->pNext != head) {
			printf("\t\t\t\t| [%d] %-15s                         |\n", lista_pointer->id, lista_pointer->NameCategory);
			print_categories(lista_pointer->pNext, head);
		}
		else
			printf("\t\t\t\t| [%d] %-15s                         |\n", lista_pointer->id, lista_pointer->NameCategory);
	}
}

bool find_category(struct categories** lista_pointer, int number, struct categories** head) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head) {
			if ((*lista_pointer)->id == number)
				return true;
			else
				find_category(&(*lista_pointer)->pNext, number, head);
		}
		else if ((*lista_pointer)->id == number)
			return true;
		else
			return false;
	}
	return false;
}

char* name_category(struct categories** lista_pointer, int id) {
	if (*lista_pointer) {
		if ((*lista_pointer)->id == id)
			return (*lista_pointer)->NameCategory;
		else
			name_category(&(*lista_pointer)->pNext, id);
	}
}

char* return_name_category(struct categories** lista_pointer, int id) {
	return name_category(lista_pointer, id);
}

int number_of_categories(struct categories** lista_pointer, struct categories** head, int counter) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head) {
			return counter + 1 + number_of_categories(&(*lista_pointer)->pNext, head, counter);
		}
		else {
			return counter + 1;
		}
	}
	return counter;
}

int count_categories(struct categories** lista_pointer) {
	int counter = 0;
	return number_of_categories(lista_pointer, lista_pointer, counter);
}

void delete_cycle_category(struct categories** lista_pointer, struct categories** head) {
	if ((*lista_pointer)->pNext != *head) {
		delete_cycle_category(&(*lista_pointer)->pNext, head);
	}
	else
		(*lista_pointer)->pNext = NULL;
}

void delete_list_of_category(struct categories** lista_pointer, int data) {
	if (*lista_pointer) {
		if (data == 0) {
			delete_cycle_category(lista_pointer, lista_pointer);
			data++;
		}
		delete_list_of_category(&(*lista_pointer)->pNext, data);
		free(*lista_pointer);
		*lista_pointer = NULL;
	}
}