#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#include "player_structure.h"

struct players* create_list_players(struct players** lista_pointer, char name[]) {
	struct players* nowy = (struct players*)malloc(sizeof(struct players));
	for (int i = 0; i < 40; i++)
		nowy->Name[i] = name[i];
	nowy->pNext = nowy;
	nowy->points = 0;
	nowy->numberPlayer = 1;
	(*lista_pointer) = nowy;
	return (*lista_pointer);
}

void create_and_add_list_players(struct players** lista_pointer, char name[], struct players** head) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head) {
			create_and_add_list_players(&(*lista_pointer)->pNext, name, head);
		}
		else {
			struct players* nowy = (struct players*)malloc(sizeof(struct players));
			for (int i = 0; i < 40; i++)
				nowy->Name[i] = name[i];
			nowy->points = 0;
			nowy->numberPlayer = (*lista_pointer)->numberPlayer + 1;
			(*lista_pointer)->pNext = nowy;
			nowy->pNext = (*head);
		}
	}
	else
		*lista_pointer = create_list_players(lista_pointer, name);
}

void print_players(struct players* lista_pointer, struct players* head) {
	if (lista_pointer) {
		if (lista_pointer->pNext != head) {
			printf("%d. %s\n", lista_pointer->numberPlayer, lista_pointer->Name);
			print_players(lista_pointer->pNext, head);
		}
		else printf("%d. %s\n", lista_pointer->numberPlayer, lista_pointer->Name);
	}
}

void delete_pointer_cycle(struct players** lista_pointer, struct players* head) {
	if (*lista_pointer) {
		while ((*lista_pointer)->pNext != head)
			(*lista_pointer) = (*lista_pointer)->pNext;
		(*lista_pointer)->pNext = NULL;
	}
}

void delete_cycle_players(struct players** lista_pointer, struct players** head) {
	if ((*lista_pointer)->pNext != *head) {
		delete_cycle_players(&(*lista_pointer)->pNext, head);
	}
	else
		(*lista_pointer)->pNext = NULL;
}

void delete_list_of_players(struct players** lista_pointer, int data) {
	if (*lista_pointer) {
		if (data == 0) {
			delete_cycle_players(lista_pointer, lista_pointer);
			data++;
		}
		delete_list_of_players(&(*lista_pointer)->pNext, data);
		free(*lista_pointer);
		*lista_pointer = NULL;
	}
}