#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "player_structure.h"
#include "player_functions.h"
#define Base 10

int is_numbers(char string[]) {
	char* endptr;
	int number = strtol(string, &endptr, Base);
	if (*endptr != '\0' || endptr == number) return 0;
	else return -1;
}


int string_to_int(int(*number)(char string[]),char thisString[]) {
	char* endptr;
	int number1 = strtol(thisString, &endptr, Base);
	if (number(thisString)) return number1;
	else return -18000;
}

struct player* new_players(struct players** lista_pointer) {
	char number_of_players[80];
	int flag = 0;
numberofplayerslevel:
	printf("Podaj ilu chcesz mieæ graczy: ");
	scanf("%9s", &number_of_players);
	int players = string_to_int(is_numbers, number_of_players);
	if (players != -18000) {
		if (players > 0) {
			for (int i = 0;i < players;i++) {
				char name[40];
				printf("Wprowadz nazwê gracza %d: ",i+1);
				scanf("%s", &name);
				create_and_add_list_players(lista_pointer, name, lista_pointer);
				printf("Lista graczy:\n");
				print_players(*lista_pointer, *lista_pointer);
			}
		}
		else if (players == 0) {
			printf("Nie mo¿e byæ %d graczy\n", players);
			goto numberofplayerslevel;
		}
		else {
			printf("Nie mo¿e byæ ujemna liczba graczy\n");
			goto  numberofplayerslevel;
		}
	}
	else {
		printf("Wprowadzi³eœ z³e dane\n");
		goto numberofplayerslevel;
	}
	return *lista_pointer;
}

int* array_points_players(struct players** players_list, struct players** head_players, int index, int array[],int size) {
	if (*players_list) {
		if ((*players_list)->pNext != *head_players) {
			array[index] = (*players_list)->points;
			index++;
			array_points_players(&(*players_list)->pNext, head_players, index, array, size);
		}
		else {
			array[index] = (*players_list)->points;
			return array;
		}
	}
}

void print_label_players(struct players** players_list,struct players** head_players,int index) {
	int amount_of_elements = count_players(players_list);
	int* array = calloc(amount_of_elements, sizeof(int));
	array = array_points_players(players_list, players_list, index, array, amount_of_elements);
	for(int i=0;i<amount_of_elements-1;i++)
		for (int j = 0; j < amount_of_elements; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	for (int i = amount_of_elements; i > 0; i--) {
		printf("%d %s\n", (*players_list)->points, (*players_list)->Name);
	}
	free(*array);
}

void players_stats(struct players**players_list) {
	print_label_players(players_list, players_list,0);
}