﻿#define _CRT_SECURE_NO_WARNINGS
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
#include "category_structure.h"
#include "category_functions.h"
#include "question_structure.h"
#include "question_functions.h"
#include "reading_files.h"
#define Base 10


int is_numbers(char string[]) {
	char* endptr;
	int number = strtol(string, &endptr, Base);
	if (*endptr != '\0' || endptr == number) return 0;
	else return -1;
}


int string_to_int(int(*number)(char string[]), char thisString[]) {
	char* endptr;
	int number1 = strtol(thisString, &endptr, Base);
	if (number(thisString)) return number1;
	else return -18000;
}

struct players* new_players(struct players** lista_pointer) {
	char number_of_players[80];
	int flag = 0;
numberofplayerslevel:
	printf("\t\t\t\t__________________________________\n");
	printf("\t\t\t\t -> Podaj ilu chcesz mieć graczy: ");
	scanf("%9s", &number_of_players);
	system("cls");
	int amountOfPlayers = count_players(lista_pointer);
	int players = string_to_int(is_numbers, number_of_players);
	if (players != -18000) {
		if (players > 0) {
			if (*lista_pointer == NULL) {
				for (int i = 0;i < players;i++) {
					char name[40];
					printf("\t\t\t\tWprowadz nazwę gracza %d: ", 1 + i);
					scanf("%s", &name);
					system("cls");
					create_and_add_list_players(lista_pointer, name, lista_pointer);
					print_players(*lista_pointer, *lista_pointer, 0);
				}
			}
			else {
				for (int i = 0;i < players;i++) {
					char name[40];
					print_players(*lista_pointer, *lista_pointer, 0);
					printf("\t\t\t\tWprowadz nazwę gracza %d: ", amountOfPlayers + 1 + i);
					scanf("%s", &name);
					system("cls");
					create_and_add_list_players(lista_pointer, name, lista_pointer);
				}
			}
		}
		else if (players == 0) {
			printf("Nie może być %d graczy\n", players);
			goto numberofplayerslevel;
		}
		else {
			printf("Nie może być ujemna liczba graczy\n");
			goto  numberofplayerslevel;
		}
	}
	else {
		printf("Wprowadziłeś niepoprawne dane\n");
		goto numberofplayerslevel;
	}
	return *lista_pointer;
}

void players_stats(struct players** players_list) {
	int amount_of_elements = count_players(players_list);
	struct players* players = (*players_list);
	struct players* playersArray = calloc(amount_of_elements, sizeof(struct players));
	for (int i = 0;i < amount_of_elements;i++) {
		playersArray[i] = *players;
		players = players->pNext;
	}
	for (int i = 0;i < amount_of_elements - 1;i++) {
		for (int j = 0;j < amount_of_elements - i - 1;j++) {
			if (playersArray[j].points < playersArray[j + 1].points) {
				struct players temp = playersArray[j];
				playersArray[j] = playersArray[j + 1];
				playersArray[j + 1] = temp;
			}
		}
	}
	printf("\t\t\t __________________________________________________________\n");
	for (int i = 0;i < amount_of_elements;i++) {
		if (i == 0)printf("\t\t\t|Miejsce: %3d st|NAME: %20s| Points: %6d|\n", i + 1, playersArray[i].Name, playersArray[i].points);
		else if (i == 1) printf("\t\t\t|Miejsce: %3d nd|NAME: %20s| Points: %6d|\n", i + 1, playersArray[i].Name, playersArray[i].points);
		else if (i == 2) printf("\t\t\t|Miejsce: %3d rd|NAME: %20s| Points: %6d|\n", i + 1, playersArray[i].Name, playersArray[i].points);
		else printf("\t\t\t|Miejsce: %5d.|NAME: %20s| Points: %6d|\n", i + 1, playersArray[i].Name, playersArray[i].points);
	}
	printf("\t\t\t ----------------------------------------------------------\n");
	free(playersArray);
}

void changeNickname(struct players** players_list) {
	char optionChangeNickname[128];
nicknamechange:
	print_players(*players_list, *players_list, 0);
	printf("\t\t\t\t -> Wpisz 0 aby nie zmieniać nicku\n");
	printf("\t\t\t\t    Wpisz numer gracza do zmiany nazwy: ");
	scanf("%s", &optionChangeNickname);
	int playerNumber = string_to_int(is_numbers, optionChangeNickname);
	int amountOfPlayers = count_players(players_list);
	if (playerNumber != -18000) {
		if (playerNumber <= amountOfPlayers && playerNumber > 0) {
			char newNickname[40];
			struct players* player = return_player(players_list, playerNumber);
			printf("\t\t\t\tWpisz nowy nickname dla %s: ", player->Name);
			scanf("%s", &newNickname);
			player = change_nickname(player, newNickname);
		}
		else if (playerNumber == 0);
		else {
			printf("\t\t\t\tNie ma takiego gracza o takim nicku!\n\t\t\t\tWpisz poprawny numer\n");
			goto nicknamechange;
		}
	}
	else {
		printf("\t\t\t\tWprowadziłeś niepoprawne dane\n");
		goto nicknamechange;
	}
}


void deleteOnePlayer(struct players** lista_pointer) {
	delete_cycle_players(lista_pointer, lista_pointer);
	char numberOfPlayer[128];
deleteplayer:
	print_players(*lista_pointer, *lista_pointer, 0);
	puts("");
	printf("\t\t\t\tWprowadz numer gracza który ma zostać usunięty: ");
	scanf("%s", &numberOfPlayer);
	int amountOfPlayers = count_players(lista_pointer);
	int PlayerNumber = string_to_int(is_numbers, numberOfPlayer);
	if (PlayerNumber != -18000) {
		if (PlayerNumber <= amountOfPlayers && PlayerNumber > 0) {
			deleteOnePlayerNode(lista_pointer, PlayerNumber);
			cycleRegenPlayer(lista_pointer, lista_pointer);
			resetIdPlayers(lista_pointer, lista_pointer, 1);
			printf("\t\t\t\tUdało się usunąć wybranego gracza!\n");
		}
		else {
			printf("\t\t\t\tNie istnieje taki gracz o podanym numerze %d!!!\n", PlayerNumber);
			goto deleteplayer;
		}
	}
	else {
		printf("\t\t\t\tWpisałeś niepoprawne dane!\n\t\t\t\tWpisz je jeszcze raz!\n");
		goto deleteplayer;
	}

}

int standardModeGame(struct players** players_list) {
	srand(time(NULL));
	int amountOfPlayers = count_players(players_list);
	char option[256];
	struct categories* categoriesList = NULL;
	adding_categories_to_list(&categoriesList);
categoryselect:
	printf("\t\t\t\t _____________________________________________\n");
	printf("\t\t\t\t| [0] Wyjdz                                   |\n");
	print_categories(categoriesList, categoriesList);
	printf("\t\t\t\t ---------------------------------------------\n");
	printf("\t\t\t\tWybierz kategorię:");
	scanf("%s", &option);
	system("cls");
	int optionNumber = string_to_int(is_numbers, option);
	if (optionNumber != -18000) {
		int amountOFCategories = count_categories(&categoriesList);
		if (optionNumber > 0 && optionNumber <= amountOFCategories) {
			struct questions* questionsList = NULL;
			char* nameCategory = return_name_category(&categoriesList, optionNumber);
			adding_questions_to_list(&questionsList, nameCategory);
			int player = 1;
			while (player != amountOfPlayers + 1) {
				int amountOfQuestions = count_questions(&questionsList);
				char* ch;
				char answear[80];
				printf("\t\t\t\tKolej gracza o nazwie: %s\n", (*players_list)->Name);
				scanf("%c", &ch);
				system("cls");
				int proces = 1;
				while (proces != 3) {
					printf("\t\t\t\tOdpowiada gracz o nazwie: %s\n\n", (*players_list)->Name);
					int randomQuestion = (rand() % (amountOfQuestions - 1 + 1)) + 1;;
					struct questions* question = node_question_head(&questionsList, randomQuestion);
					printf("\t\t\t\t%s\n", question->sentense);
					printf("\t\t\t\t%s\n", question->A);
					printf("\t\t\t\t%s\n", question->B);
					printf("\t\t\t\t%s\n", question->C);
					printf("\t\t\t\t%s\n", question->D);
					printf("\t\t\t\tOdpowiedz: ");
					scanf("%s", &answear);
					system("cls");
					if (strlen(&answear) == 1) {
						if ((toupper(answear[0])) == *question->coorectAnswear) {
							(*players_list)->points = (*players_list)->points + 1;
						}
					}
					proces++;
				}
				player++;
				*players_list = (*players_list)->pNext;
			}
			return 1;
		}
		if (optionNumber == 0) {
			return 0;
		}
		else {
			printf("\t\t\t\tNie istnieje taka kategoria\n");
			goto categoryselect;
		}
	}
	else {
		printf("\t\t\t\tWpisałeś niepoprawne dane!");
		goto categoryselect;
	}
}

