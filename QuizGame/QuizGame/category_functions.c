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
			printf("\t\t\t\t| [%d] %-15s |\n", lista_pointer->id, lista_pointer->NameCategory);
			print_categories(lista_pointer->pNext, head);
		}
		else
			printf("\t\t\t\t| [%10d] %-15s |\n", lista_pointer->id, lista_pointer->NameCategory);
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
//
//char* name_category(struct categories** lista_pointer, int id) {
//	if (*lista_pointer) {
//		if ((*lista_pointer)->id == id)
//			return (*lista_pointer)->NameCategory;
//		else
//			name_category(&(*lista_pointer)->pNext, id);
//	}
//}
//
//char* return_name_category(struct categories** lista_pointer, int id) {
//	return name_category(lista_pointer, id);
//}

//void delete_new_line_sign_categories(struct categories** lista_pointer, struct categories** head) {
//	if (*lista_pointer) {
//		if ((*lista_pointer)->pNext != *head) {
//			char* buffor = delete_new_line_sign((*lista_pointer)->NameCategory);
//			char tab[256];
//			for (int i = 0; i < 256; i++)
//				tab[i] = buffor[i];
//			for (int i = 0; i < 256; i++)
//				(*lista_pointer)->NameCategory[i] = tab[i];
//		}
//		else
//			return;
//		delete_new_line_sign_categories(&(*lista_pointer)->pNext, head);
//	}
//}

//void delete_new_line_categories(struct categories** lista_pointer) {
//	delete_new_line_sign_categories(lista_pointer, lista_pointer);
//}