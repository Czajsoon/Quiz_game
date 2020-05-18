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

void print_players(struct players* lista_pointer, struct players* head, int index) {
	if (lista_pointer) {
		if (lista_pointer->pNext != head) {
			if (index == 0) printf("\t\t\t\t _____________________________________________\n");
			index++;
			printf("\t\t\t\t|NUMER GRACZA %3d. |NAME %19s |\n", lista_pointer->numberPlayer, lista_pointer->Name);
			print_players(lista_pointer->pNext, head,index);
		}
		else {
			if (index == 0) printf("\t\t\t\t _____________________________________________\n");
			index++;
			printf("\t\t\t\t|NUMER GRACZA %3d. |NAME %19s |\n", lista_pointer->numberPlayer, lista_pointer->Name);
			printf("\t\t\t\t --------------------------------------------\n");
		}
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

int number_of_players(struct players** lista_pointer, struct players** head,int counter) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head) {
			return counter + 1 + number_of_players(&(*lista_pointer)->pNext, head, counter);
		}
		else {
			return counter + 1;
		}
	}
	return counter;
}

int count_players(struct players** lista_pointer) {
	int counter = 0;
	return number_of_players(lista_pointer, lista_pointer, counter);
}

struct players* pointer_player_with_points(struct players** lista_pointer, struct players** head,int points) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head) {
			if ((*lista_pointer)->points == points) return *lista_pointer;
			else *lista_pointer = pointer_player_with_points(&(*lista_pointer)->pNext, head, points);
		}
		else { 
			if ((*lista_pointer)->points == points)
				return *lista_pointer;
		}
	}
}

struct players* player_with_points(struct players** lista_pointer, int points) {
	return pointer_player_with_points(lista_pointer, lista_pointer, points);
}

struct players* find_player_by_number(struct players** lista_pointer, struct players** head,int number) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head) {
			if ((*lista_pointer)->numberPlayer == number)
				return *lista_pointer;
			else (*lista_pointer) = find_player_by_number(&(*lista_pointer)->pNext, head, number);
		}
		else {
			if ((*lista_pointer)->numberPlayer == number)
				return *lista_pointer;
		}
	}
}

struct players* return_player(struct players** lista_pointer, int number) {
	return find_player_by_number(lista_pointer, lista_pointer, number);
}

struct players* change_nickname(struct players* player,char newNick[]) {
	for (int i=0;i < 40;i++) {
		player->Name[i] = newNick[i];
	}
	return player;
}

void deleteOnePlayerNode(struct players** lista_pointer, int number) {
	if (*lista_pointer) {
		if ((*lista_pointer)->numberPlayer == number) {
			struct players* next = (*lista_pointer)->pNext;
			free(*lista_pointer);
			(*lista_pointer) = next;
		}
		else {
			deleteOnePlayerNode(&(*lista_pointer)->pNext, number);
		}
	}
}

void cycleRegenPlayer(struct players** lista_pointer, struct players** head) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext)
			cycleRegenPlayer(&(*lista_pointer)->pNext, head);
		else
			(*lista_pointer)->pNext = *head;
	}
}

void resetIdPlayers(struct players** lista_pointer, struct players** head, int startingNumber) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head) {
			(*lista_pointer)->numberPlayer = startingNumber;
			startingNumber++;
			resetIdPlayers(&(*lista_pointer)->pNext, head, startingNumber);
		}
		else {
			(*lista_pointer)->numberPlayer = startingNumber;
		}
	}
}

void resetPoints(struct players** lista_pointer,struct players** head) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head) {
			(*lista_pointer)->points = 0;
			resetPoints(&(*lista_pointer)->pNext, head);
		}
		else (*lista_pointer)->points = 0;
	}
}

void resetPointsPlayer(struct players* lista_pointer, int number) {
	struct players* start = lista_pointer;
	do{
		if (lista_pointer->numberPlayer == number)
			lista_pointer->points = 0;
		lista_pointer = lista_pointer->pNext;
	} while (lista_pointer != start);
	if (lista_pointer->numberPlayer == number)
		lista_pointer->points = 0;
}

bool same_players_name(struct players* lista_pointer, char* Name) {
	struct players* start = lista_pointer;
	do {
		if ((strcmp(lista_pointer->Name, Name)) == 0) return true;
		lista_pointer = lista_pointer->pNext;
	} while (lista_pointer != start);
	if ((strcmp(lista_pointer->Name, Name)) == 0) return true;
	else return false;
}