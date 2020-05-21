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
#include "category_structure.h"
#include "category_functions.h"
#include "question_structure.h"
#include "question_functions.h"
#include "reading_files.h"
#include "addinNewFiles.h"
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
	char number_of_players[80], name[40];
	int flag1 = 0, size_name = 40, size_number = 80;
numberofplayerslevel:
	printf("\t\t\t\t______________________________________\n");
	printf("\t\t\t\t -> Podaj ilu chcesz dodać graczy: ");
	gets_s(number_of_players, size_number);
	system("cls");
	int players = string_to_int(is_numbers, number_of_players);
	if (players != -18000) {
		if (players > 0) {
			if (*lista_pointer == NULL) {
				for (int i = 0; i < players; i++) {
				playername:;
					printf("\t\t\t\tWprowadz nazwę gracza %d: ", 1 + i);
					gets_s(name, size_name);
					if (i > 0)
						if (same_players_name(*lista_pointer, name)) {
							system("cls");
							print_players(*lista_pointer, *lista_pointer, 0);
							printf("\t\t\t\tTaki gracz już istnieje wprowadz inna nazwę\n");
							goto playername;
						}
					if (strlen(name) == 0) {
						system("cls");
						if (i > 0) {
							print_players(*lista_pointer, *lista_pointer, 0);
						}
						printf("\t\t\t\tGracz nie może mieć pustej nazwy\n");
						goto playername;
					}
					system("cls");
					create_and_add_list_players(lista_pointer, name, lista_pointer);
					print_players(*lista_pointer, *lista_pointer, 0);
				}
			}
			else {
				int amountOfPlayers = count_players(lista_pointer);
				for (int i = 0; i < players; i++) {
				playername1:;
					print_players(*lista_pointer, *lista_pointer, 0);
					printf("\t\t\t\tWprowadz nazwę gracza %d: ", amountOfPlayers + 1 + i);
					gets_s(name, size_name);
					if (same_players_name(*lista_pointer, name)) {
						system("cls");
						printf("\t\t\t\tTaki gracz już istnieje wprowadz inna nazwę\n");
						goto playername1;
					}
					if (strlen(name) == 0) {
						system("cls");
						printf("\t\t\t\tGracz nie może mieć pustej nazwy\n");
						goto playername1;
					}
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
	for (int i = 0; i < amount_of_elements; i++) {
		playersArray[i] = *players;
		players = players->pNext;
	}
	for (int i = 0; i < amount_of_elements - 1; i++) {
		for (int j = 0; j < amount_of_elements - i - 1; j++) {
			if (playersArray[j].points < playersArray[j + 1].points) {
				struct players temp = playersArray[j];
				playersArray[j] = playersArray[j + 1];
				playersArray[j + 1] = temp;
			}
		}
	}
	printf("\t\t\t __________________________________________________________\n");
	for (int i = 0; i < amount_of_elements; i++) {
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
	printf("\t\t\t\t -> Naciśnij enter aby nie wpisywać nowego nicku\n");
	printf("\t\t\t\t    Wpisz numer gracza do zmiany nazwy: ");
	gets_s(optionChangeNickname, 128);
	system("cls");
	int playerNumber = string_to_int(is_numbers, optionChangeNickname);
	int amountOfPlayers = count_players(players_list);
	if (playerNumber != -18000) {
		if (playerNumber <= amountOfPlayers && playerNumber > 0) {
			char newNickname[40];
			struct players* player = return_player(players_list, playerNumber);
			printf("\t\t\t\tWpisz nowy nickname dla %s: ", player->Name);
			gets_s(newNickname, 40);
			player = change_nickname(player, newNickname);
		}
		else if (playerNumber == 0);
		else {
			printf("\t\t\t\tNie ma takiego gracza o takim nicku!\n\t\t\t\tWpisz poprawny numer\n");
			goto nicknamechange;
		}
	}
	else if (optionChangeNickname[0] == '\n');
	else {
		printf("\t\t\t\tWprowadziłeś niepoprawne dane\n");
		goto nicknamechange;
	}
}

void resetPlayerPoints(struct players* players_list) {
	char optionResetPoints[128];
	print_players(players_list, players_list, 0);
resetPoints:;
	printf("\t\t\t\t -> Naciśnij enter aby nie wpisywać nowego nicku\n");
	printf("\t\t\t\t    Wpisz numer gracza aby zresetować punkty: ");
	gets_s(optionResetPoints, 128);
	system("cls");
	int playerNumber = string_to_int(is_numbers, optionResetPoints);
	int amountOfPlayers = count_players(&players_list);
	if (playerNumber != -18000 && playerNumber != 0) {
		if (playerNumber <= amountOfPlayers && playerNumber > 0)
			resetPointsPlayer(players_list, playerNumber);
		else {
			printf("\t\t\t\tNie ma takiego gracza!\n\t\t\t\tWpisz poprawny numer\n");
			goto resetPoints;
		}
	}
	else if (playerNumber == 0);
	else {
		printf("\t\t\t\t    Wprowadziłeś niepoprawne dane\n");
		goto resetPoints;
	}
}

void deleteOnePlayer(struct players** lista_pointer) {
	delete_cycle_players(lista_pointer, lista_pointer);
	char numberOfPlayer[128];
deleteplayer:
	print_players(*lista_pointer, *lista_pointer, 0);
	puts("");
	printf("\t\t\t\tWprowadz numer gracza który ma zostać usunięty: ");
	gets_s(numberOfPlayer, 128);
	int amountOfPlayers = count_players(lista_pointer);
	int PlayerNumber = string_to_int(is_numbers, numberOfPlayer);
	system("cls");
	if (PlayerNumber != -18000) {
		if (PlayerNumber <= amountOfPlayers && PlayerNumber > 0) {
			system("cls");
			deleteOnePlayerNode(lista_pointer, PlayerNumber);
			cycleRegenPlayer(lista_pointer, lista_pointer);
			resetIdPlayers(lista_pointer, lista_pointer, 1);
			printf("\t\t\t\tUdało się usunąć wybranego gracza!\n");
		}
		else {
			system("cls");
			printf("\t\t\t\tNie istnieje taki gracz o podanym numerze %d!!!\n", PlayerNumber);
			goto deleteplayer;
		}
	}
	else {
		system("cls");
		printf("\t\t\t\tWpisałeś niepoprawne dane!\n");
		goto deleteplayer;
	}

}

bool if_question_questioned(int size, int* tab, int number) {
	for (int i = 0; i < size; i++) {
		if (tab[i] == number)
			return true;
	}
	return false;
}

int standarModeMQue(struct players** players_list) {
	srand(time(NULL));
	int amountOfPlayers = count_players(players_list);
	char option1[256];
	struct categories* categoriesList = NULL;
	adding_categories_to_list(&categoriesList);
catmque:;
	printf("\t\t\t\t _____________________________________________\n");
	printf("\t\t\t\t| [0] Wyjdz                                   |\n");
	print_categories(categoriesList, categoriesList);
	printf("\t\t\t\t ---------------------------------------------\n");
	printf("\t\t\t\tWybierz kategorię:");
	gets_s(option1, 256);
	system("cls");
	int optionNumber = string_to_int(is_numbers, option1);
	if (optionNumber != -18000) {
		int amountOFCategories = count_categories(&categoriesList);
		if (optionNumber > 0 && optionNumber <= amountOFCategories) {
			struct questions* questionsList = NULL;
			char* nameCategory = return_name_category(&categoriesList, optionNumber);
			adding_questions_to_list(&questionsList, nameCategory);
			int amountOfQue = count_questions(&questionsList);
			char numOfQue[256];
		getNumQue:;
			printf("\t\t\t\tPodaj liczbę pytań: ");
			gets_s(numOfQue, 256);
			int numberOfQuestions = string_to_int(is_numbers, numOfQue);
			if (numberOfQuestions != -18000) {
				if (numberOfQuestions > 0 && numberOfQuestions <= amountOfQue) {
					int player = 1;
					while (player != amountOfPlayers + 1) {
						int amountOfQuestions = count_questions(&questionsList);
						char answear[80];
						int proces = 1, size_answear = 80;
						int tab[70];
						char buffer[256];
						for (int i = 0; i < 70; i++) {
							tab[i] = 0;
						}
						printf("\t\t\t\tOdpowiada gracz o nazwie: %s\n\n", (*players_list)->Name);
						printf("\t\t\t\tNaciśnij enter aby zacząć...");
						gets_s(buffer, 256);
						system("cls");
						while (proces != numberOfQuestions + 1) {
						generateRandom:;
							int randomQuestion = (rand() % (amountOfQuestions - 1 + 1)) + 1;
							struct questions* question = node_question_head(&questionsList, randomQuestion);
							if (if_question_questioned(5, tab, randomQuestion)) goto generateRandom;
							else tab[proces - 1] = question->id;
							if (proces == 1) printf("\n\n");
							puts("");
							printf("\t\t\t\t%s\n", question->sentense);
							printf("\t\t\t\t[A] %s\n", question->A);
							printf("\t\t\t\t[B] %s\n", question->B);
							printf("\t\t\t\t[C] %s\n", question->C);
							printf("\t\t\t\t[D] %s\n", question->D);
							printf("\t\t\t\tOdpowiedz: ");
							gets_s(answear, size_answear);
							system("cls");
							if (strlen(&answear) == 1) {
								if ((toupper(answear[0])) == *question->coorectAnswear) {
									(*players_list)->points = (*players_list)->points + 1;
									printf("\t\t\t\tPoprawna odpowiedz!!!\n\t\t\t\tDo twojego konta dodano punkt za poprawną odpowiedz\n");
								}
								else {
									printf("\t\t\t\tNiepoprawna odpowiedz!!!\n\n");
								}
							}
							else {
								printf("\t\t\t\tNiepoprawna odpowiedz!!!\n\n");
							}
							proces++;
						}
						player++;
						*players_list = (*players_list)->pNext;
					}
					delete_list_of_category(&categoriesList, 0);
					delete_list_of_questions(&questionsList, 0);
					system("cls");
					return 1;
				}
				else if (numberOfQuestions > 70) {
					system("cls");
					printf("\t\t\t\tPodałęś zbyt duża liczbe maksymalna liczba to 70!\n");
					goto getNumQue;
				}
				else if (numberOfQuestions > amountOfQue) {
					system("cls");
					printf("\t\t\t\tPodałeś zbyt dużą liczbę pytań\n");
					printf("\t\t\t\tLiczba pytań w tej kategorii to: %d\n", amountOfQue);
					printf("\t\t\t\tDodaj %d pytań do kategorii o nazwie %s\n", numberOfQuestions - amountOfQue, nameCategory);
					printf("\t\t\t\tLub podaj mniejszą ilośc pytań\n");
					delete_list_of_questions(&questionsList, 0);
					goto catmque;
				}
				else {
					system("cls");
					printf("\t\t\t\tPodano nieprawidłową liczbę pytań\n");
					delete_list_of_questions(&questionsList, 0);
					goto catmque;
				}
			}
			else {
				system("cls");
				printf("\t\t\t\tWpisałeś niepoprawne dane!\n");
				goto getNumQue;
			}

		}
		else if (optionNumber == 0) return 0;
		else {
			system("cls");
			printf("\t\t\t\tNie ma takiej kategorii\n");
			goto catmque;
		}
	}
	else {
		system("cls");
		printf("\t\t\t\tWpisałeś niepoprawne dane!\n");
		goto catmque;
	}
}

int standardModeGame(struct players** players_list) {
	srand(time(NULL));
	int amountOfPlayers = count_players(players_list);
	char option1[256];
	struct categories* categoriesList = NULL;
	adding_categories_to_list(&categoriesList);
categoryselect:
	printf("\t\t\t\t _____________________________________________\n");
	printf("\t\t\t\t| [0] Wyjdz                                   |\n");
	print_categories(categoriesList, categoriesList);
	printf("\t\t\t\t ---------------------------------------------\n");
	printf("\t\t\t\tWybierz kategorię:");
	gets_s(option1, 256);
	system("cls");
	int optionNumber = string_to_int(is_numbers, option1);
	if (optionNumber != -18000) {
		int amountOFCategories = count_categories(&categoriesList);
		if (optionNumber > 0 && optionNumber <= amountOFCategories) {
			struct questions* questionsList = NULL;
			char* nameCategory = return_name_category(&categoriesList, optionNumber);
			adding_questions_to_list(&questionsList, nameCategory);
			int player = 1;
			while (player != amountOfPlayers + 1) {
				int amountOfQuestions = count_questions(&questionsList);
				char answear[80];
				int proces = 1, size_answear = 80;
				int tab[5];
				char buffer[256];
				for (int i = 0; i < 5; i++) {
					tab[i] = 0;
				}
				printf("\t\t\t\tOdpowiada gracz o nazwie: %s\n\n", (*players_list)->Name);
				printf("\t\t\t\tNaciśnij enter aby zacząć...");
				gets_s(buffer, 256);
				system("cls");
				while (proces != 6) {
				generateRandom:;
					int randomQuestion = (rand() % (amountOfQuestions - 1 + 1)) + 1;
					struct questions* question = node_question_head(&questionsList, randomQuestion);
					if (if_question_questioned(5, tab, randomQuestion)) goto generateRandom;
					else tab[proces - 1] = question->id;
					if (proces == 1) printf("\n\n");
					puts("");
					printf("\t\t\t\t%s\n", question->sentense);
					printf("\t\t\t\t[A] %s\n", question->A);
					printf("\t\t\t\t[B] %s\n", question->B);
					printf("\t\t\t\t[C] %s\n", question->C);
					printf("\t\t\t\t[D] %s\n", question->D);
					printf("\t\t\t\tOdpowiedz: ");
					gets_s(answear, size_answear);
					system("cls");
					if (strlen(&answear) == 1) {
						if ((toupper(answear[0])) == *question->coorectAnswear) {
							(*players_list)->points = (*players_list)->points + 1;
							printf("\t\t\t\tPoprawna odpowiedz!!!\n\t\t\t\tDo twojego konta dodano punkt za poprawną odpowiedz\n");
						}
						else {
							printf("\t\t\t\tNiepoprawna odpowiedz!!!\n\n");
						}
					}
					else {
						printf("\t\t\t\tNiepoprawna odpowiedz!!!\n\n");
					}
					proces++;
				}
				player++;
				*players_list = (*players_list)->pNext;
			}
			delete_list_of_questions(&questionsList, 0);
			delete_list_of_category(&categoriesList, 0);
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

bool is_category_in_categories(struct categories* lista_pointer, char* newName) {
	if (lista_pointer) {
		struct categories* start = lista_pointer;
		do {
			if (strcmp(lista_pointer->NameCategory, newName) == 0)
				return true;
			lista_pointer = lista_pointer->pNext;
		} while (lista_pointer != start);
		if (strcmp(lista_pointer->NameCategory, newName) == 0)
			return true;
		else return false;
	}
}

void changeQuestion() {
	struct questions* queList = NULL;
	struct categories* catList = NULL;
	char category[256];
	adding_categories_to_list(&catList);
changeQueCategorySelect:;
	print_categories(catList, catList);
	printf("\t\t\t\tWybierz numer kategorii: ");
	gets_s(category, 256);
	int numberCategory = string_to_int(is_numbers, category);
	if (strlen(category) == 0);
	else if (numberCategory == -18000) {
		system("cls");
		printf("\t\t\t\tWpisałeś niepoprawne dane!\n");
		goto changeQueCategorySelect;
	}
	else {
		int countCategories = count_categories(&catList);
		if (numberCategory > 0 && numberCategory <= countCategories) {
			char* categoryName = return_name_category(&catList, numberCategory);
			adding_questions_to_list(&queList, categoryName);
			char question[256];
		wrongQueNubmer:;
			printAllQue(queList);
			printf("\t\t\t\tWybierz number pytania: ");
			gets_s(question, 256);
			int QueNumber = string_to_int(is_numbers, question);
			if (QueNumber != -18000) {
				int countQuestions = count_questions(&queList);
				if (QueNumber > 0 && QueNumber <= countQuestions) {
					char question[256];
					struct questions* newOne = (struct questions*)malloc(sizeof(struct questions));
					struct questions* oldQue = return_que(queList, QueNumber);
					for (int j = 0; j < 6; j++) {
						if (j == 0) {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\tpoprzednia treść pytania: %s\n", oldQue->sentense);
							puts("");
							printf("\t\t\t\tPodaj treść pytania : ");
							gets_s(question, 256);
							question[0] = toupper(question[0]);
							for (int x = 0; x < 256; x++)
								newOne->sentense[x] = question[x];
							system("cls");
						}
						else if (j == 1) {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\tpoprzednia treść pytania: %s\n", oldQue->sentense);
							printf("\t\t\t\tpoprzednia odpowiedz A: %s\n", oldQue->A);
							puts("");
							printf("\t\t\t\tNowo wprowadzone dane\n");
							puts("");
							printf("\t\t\t\t%s\n", newOne->sentense);
							printf("\t\t\t\tPodaj odpowiedz A\n");
							printf("\t\t\t\t[A] ");
							gets_s(question, 256);
							question[0] = toupper(question[0]);
							if (strlen(question) == 0) {
								char buff[] = "--";
								for (int x = 0; x < 256; x++)
									question[x] = buff[x];
							}
							for (int x = 0; x < 256; x++)
								newOne->A[x] = question[x];
							system("cls");
						}
						else if (j == 2) {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\tpoprzednia treść pytania: %s\n", oldQue->sentense);
							printf("\t\t\t\tpoprzednia odpowiedz A: %s\n", oldQue->A);
							printf("\t\t\t\tpoprzednia odpowiedz B: %s\n", oldQue->B);
							puts("");
							printf("\t\t\t\tNowo wprowadzone dane\n");
							puts("");
							printf("\t\t\t\t%s\n", newOne->sentense);
							printf("\t\t\t\tNowo wprowadzone odpowiedzi\n");
							printf("\t\t\t\t[A] %s\n", newOne->A);
							printf("\t\t\t\tPodaj odpowiedz B\n");
							printf("\t\t\t\t[B] ");
							gets_s(question, 256);
							question[0] = toupper(question[0]);
							if (strlen(question) == 0) {
								char buff[] = "--";
								for (int x = 0; x < 256; x++)
									question[x] = buff[x];
							}
							for (int x = 0; x < 256; x++)
								newOne->B[x] = question[x];
							system("cls");
						}
						else if (j == 3) {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\tpoprzednia treść pytania: %s\n", oldQue->sentense);
							printf("\t\t\t\tpoprzednia odpowiedz A: %s\n", oldQue->A);
							printf("\t\t\t\tpoprzednia odpowiedz B: %s\n", oldQue->B);
							printf("\t\t\t\tpoprzednia odpowiedz C: %s\n", oldQue->C);
							puts("");
							printf("\t\t\t\tNowo wprowadzone dane\n");
							puts("");
							printf("\t\t\t\t%s\n", newOne->sentense);
							printf("\t\t\t\tNowo wprowadzone odpowiedzi\n");
							printf("\t\t\t\t[A] %s\n", newOne->A);
							printf("\t\t\t\t[B] %s\n", newOne->B);
							printf("\t\t\t\tPodaj odpowiedz C\n");
							printf("\t\t\t\t[C] ");
							gets_s(question, 256);
							question[0] = toupper(question[0]);
							if (strlen(question) == 0) {
								char buff[] = "--";
								for (int x = 0; x < 256; x++)
									question[x] = buff[x];
							}
							for (int x = 0; x < 256; x++)
								newOne->C[x] = question[x];
							system("cls");
						}
						else if (j == 4) {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\tpoprzednia treść pytania: %s\n", oldQue->sentense);
							printf("\t\t\t\tpoprzednia odpowiedz A: %s\n", oldQue->A);
							printf("\t\t\t\tpoprzednia odpowiedz B: %s\n", oldQue->B);
							printf("\t\t\t\tpoprzednia odpowiedz C: %s\n", oldQue->C);
							printf("\t\t\t\tpoprzednia odpowiedz D: %s\n", oldQue->D);
							puts("");
							printf("\t\t\t\tNowo wprowadzone dane\n");
							puts("");
							printf("\t\t\t\t%s\n", newOne->sentense);
							printf("\t\t\t\tNowo wprowadzone odpowiedzi\n");
							printf("\t\t\t\t[A] %s\n", newOne->A);
							printf("\t\t\t\t[B] %s\n", newOne->B);
							printf("\t\t\t\t[C] %s\n", newOne->C);
							printf("\t\t\t\tPodaj odpowiedz D\n");
							printf("\t\t\t\t[D] ");
							gets_s(question, 256);
							question[0] = toupper(question[0]);
							if (strlen(question) == 0) {
								char buff[] = "--";
								for (int x = 0; x < 256; x++)
									question[x] = buff[x];
							}
							for (int x = 0; x < 256; x++)
								newOne->D[x] = question[x];
							system("cls");
						}
						else {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\t%s\n", newOne->sentense);
							printf("\t\t\t\t[A] %s\n", newOne->A);
							printf("\t\t\t\t[B] %s\n", newOne->B);
							printf("\t\t\t\t[C] %s\n", newOne->C);
							printf("\t\t\t\t[D] %s\n", newOne->D);
							printf("\t\t\t\t(Np. A lub B lub C lub D)\n");
							printf("\t\t\t\tPodaj prawidłową odpowiedz: ");
							gets_s(question, 256);
							question[0] = toupper(question[0]);
							for (int x = 0; x < 256; x++)
								newOne->coorectAnswear[x] = question[x];
							system("cls");
						}
					}
					for (int i = 0; i < 256; i++) {
						oldQue->sentense[i] = newOne->sentense[i];
						oldQue->A[i] = newOne->A[i];
						oldQue->B[i] = newOne->B[i];
						oldQue->C[i] = newOne->C[i];
						oldQue->D[i] = newOne->D[i];
						oldQue->coorectAnswear[i] = newOne->coorectAnswear[i];
					}
					free(newOne);
					write_new_questions(categoryName, queList);
				}
				else {
					system("cls");
					printf("\t\t\t\tNie ma takiego pytania!\n");
					goto wrongQueNubmer;
				}
			}
			else {
				system("cls");
				printf("\t\t\t\tWpisałeś niepoprawne dane!\n");
				goto wrongQueNubmer;
			}
		}
		else {
			system("cls");
			printf("\t\t\t\tNie ma takiej kategorii!\n");
			goto changeQueCategorySelect;
		}
	}
}

void addNewCategoryByPlayer() {
	srand(time(NULL));
	struct categories* categoriesList = NULL;
	adding_categories_to_list(&categoriesList);
	char newCategoryName[256];
	int size = 256;
	int flag = 0;
categoryname:
	printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
	printf("\t\t\t\t _____________________________________________\n");
	print_categories(categoriesList, categoriesList);
	printf("\t\t\t\t ---------------------------------------------\n");
	printf("\t\t\t\tPodaj nazwę nowej kategorii: ");
	gets_s(newCategoryName, size);
	system("cls");
	if (is_category_in_categories(categoriesList, newCategoryName)) {
		printf("\t\t\t\tTaka nazwa kategorii już istnieje podaj inną\n");
		goto categoryname;
	}
	else {
		newCategoryName[0] = toupper(newCategoryName[0]);
		create_and_add_category(&categoriesList, newCategoryName, &categoriesList);
		write_categories(categoriesList);
		printf("\t\t\t\tDodaj 5 pytań do stworzonej kategorii o nazwie: %s\n", newCategoryName);
		struct questions* queList = NULL;
		struct questions* newOne = NULL;
		char question[256];
		for (int i = 0; i < 5; i++) {
			struct questions* newOne = (struct questions*)malloc(sizeof(struct questions));
			for (int j = 0; j < 6; j++) {
				if (j == 0) {
					printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
					printf("\t\t\t\tPodaj treść pytania [%d]: ", i + 1);
					gets_s(question, 256);
					question[0] = toupper(question[0]);
					for (int x = 0; x < 256; x++)
						newOne->sentense[x] = question[x];
					system("cls");
				}
				else if (j == 1) {
					printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
					printf("\t\t\t\t%s\n", newOne->sentense);
					printf("\t\t\t\tPodaj odpowiedz A\n");
					printf("\t\t\t\t[A] ");
					gets_s(question, 256);
					question[0] = toupper(question[0]);
					if (strlen(question) == 0) {
						char buff[] = "--";
						for (int x = 0; x < 256; x++)
							question[x] = buff[x];
					}
					for (int x = 0; x < 256; x++)
						newOne->A[x] = question[x];
					system("cls");
				}
				else if (j == 2) {
					printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
					printf("\t\t\t\t%s\n", newOne->sentense);
					printf("\t\t\t\tPoprzednie wprowadzone odpowiedzi\n");
					printf("\t\t\t\t[A] %s\n", newOne->A);
					printf("\t\t\t\tPodaj odpowiedz B\n");
					printf("\t\t\t\t[B] ");
					gets_s(question, 256);
					question[0] = toupper(question[0]);
					if (strlen(question) == 0) {
						char buff[] = "--";
						for (int x = 0; x < 256; x++)
							question[x] = buff[x];
					}
					for (int x = 0; x < 256; x++)
						newOne->B[x] = question[x];
					system("cls");
				}
				else if (j == 3) {
					printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
					printf("\t\t\t\t%s\n", newOne->sentense);
					printf("\t\t\t\tPoprzednie wprowadzone odpowiedzi\n");
					printf("\t\t\t\t[A] %s\n", newOne->A);
					printf("\t\t\t\t[B] %s\n", newOne->B);
					printf("\t\t\t\tPodaj odpowiedz C\n");
					printf("\t\t\t\t[C] ");
					gets_s(question, 256);
					question[0] = toupper(question[0]);
					if (strlen(question) == 0) {
						char buff[] = "--";
						for (int x = 0; x < 256; x++)
							question[x] = buff[x];
					}
					for (int x = 0; x < 256; x++)
						newOne->C[x] = question[x];
					system("cls");
				}
				else if (j == 4) {
					printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
					printf("\t\t\t\t%s\n", newOne->sentense);
					printf("\t\t\t\tPoprzednie wprowadzone odpowiedzi\n");
					printf("\t\t\t\t[A] %s\n", newOne->A);
					printf("\t\t\t\t[B] %s\n", newOne->B);
					printf("\t\t\t\t[C] %s\n", newOne->C);
					printf("\t\t\t\tPodaj odpowiedz D\n");
					printf("\t\t\t\t[D] ");
					gets_s(question, 256);
					question[0] = toupper(question[0]);
					if (strlen(question) == 0) {
						char buff[] = "--";
						for (int x = 0; x < 256; x++)
							question[x] = buff[x];
					}
					for (int x = 0; x < 256; x++)
						newOne->D[x] = question[x];
					system("cls");
				}
				else {
					printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
					printf("\t\t\t\t%s\n", newOne->sentense);
					printf("\t\t\t\t[A] %s\n", newOne->A);
					printf("\t\t\t\t[B] %s\n", newOne->B);
					printf("\t\t\t\t[C] %s\n", newOne->C);
					printf("\t\t\t\t[D] %s\n", newOne->D);
					printf("\t\t\t\t(Np. A lub B lub C lub D)\n");
					printf("\t\t\t\tPodaj prawidłową odpowiedz: ");
					gets_s(question, 256);
					question[0] = toupper(question[0]);
					for (int x = 0; x < 256; x++)
						newOne->coorectAnswear[x] = question[x];
					create_and_add_question(&queList, newOne);
					system("cls");
				}
			}
		}
		printf("\t\t\t\tGratulacje!!! Udało ci sie stworzyć nową kategorie!!!\n");
		write_new_questions(newCategoryName, queList);
		delete_list_of_category(&categoriesList, 0);
		delete_list_of_questions(&queList, 0);
	}
}

void add_new_question() {
	setlocale(LC_CTYPE, "UTF-8");
	setlocale(LC_ALL, "pl_PL");
	struct categories* listaKategorii = NULL;
	char category[256];
	adding_categories_to_list(&listaKategorii);
	int size = 256;
	int flag = 0;
addque:
	printf("\t\t\t\tJeśli nie ma twojej kategorii wpisz 0\n");
	printf("\t\t\t\t _____________________________________________\n");
	print_categories(listaKategorii, listaKategorii);
	printf("\t\t\t\t ---------------------------------------------\n");
	printf("\t\t\t\tWybierz numer z jakiej kategorii chcesz dodać pytanie: ");
	gets_s(category, size);
	system("cls");
	int categoryNumber = string_to_int(is_numbers, category);
	if (categoryNumber == -18000) {
		printf("\t\t\t\tWpisałeś niepoprawne dane!\n");
		goto addque;
	}
	else {
		if (categoryNumber > 0 && categoryNumber <= count_categories(&listaKategorii)) {
			char* categoryName = return_name_category(&listaKategorii, categoryNumber);
		howManyQue:
			printf("\t\t\t\tPodaj ile pytań chcesz dodać: ");
			char numberOfQue[256];
			gets_s(numberOfQue, size);
			system("cls");
			int number = string_to_int(is_numbers, numberOfQue);
			if (number != -18000) {
				struct questions* queList = NULL;
				adding_questions_to_list(&queList, categoryName);
				int questinNumber = count_questions(&queList);
				char buffor[256];
				for (int i = 0; i < number; i++) {
					struct questions* newOne = (struct questions*)malloc(sizeof(struct questions));
					for (int j = 0; j < 6; j++) {
						if (j == 0) {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\tPodaj treść pytania [%d]: ", questinNumber + 1 + i);
							gets_s(buffor, 256);
							for (int x = 0; x < 256; x++)
								newOne->sentense[x] = buffor[x];
							printf("\t\t\t\t%s", newOne->sentense);
							system("cls");
						}
						else if (j == 1) {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\t%s\n", newOne->sentense);
							printf("\t\t\t\tPodaj odpowiedz A\n");
							printf("\t\t\t\t[A] ");
							gets_s(buffor, 256);
							buffor[0] = toupper(buffor[0]);
							if (strlen(buffor) == 0) {
								char buff[] = "--";
								for (int x = 0; x < 256; x++)
									buffor[x] = buff[x];
							}
							for (int x = 0; x < 256; x++)
								newOne->A[x] = buffor[x];
							system("cls");
						}
						else if (j == 2) {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\t%s\n", newOne->sentense);
							printf("\t\t\t\tPoprzednie wprowadzone odpowiedzi\n");
							printf("\t\t\t\t[A] %s\n", newOne->A);
							printf("\t\t\t\tPodaj odpowiedz B\n");
							printf("\t\t\t\t[B] ");
							gets_s(buffor, 256);
							buffor[0] = toupper(buffor[0]);
							if (strlen(buffor) == 0) {
								char buff[] = "--";
								for (int x = 0; x < 256; x++)
									buffor[x] = buff[x];
							}
							for (int x = 0; x < 256; x++)
								newOne->B[x] = buffor[x];
							system("cls");
						}
						else if (j == 3) {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\t%s\n", newOne->sentense);
							printf("\t\t\t\tPoprzednie wprowadzone odpowiedzi\n");
							printf("\t\t\t\t[A] %s\n", newOne->A);
							printf("\t\t\t\t[B] %s\n", newOne->B);
							printf("\t\t\t\tPodaj odpowiedz C\n");
							printf("\t\t\t\t[C] ");
							gets_s(buffor, 256);
							buffor[0] = toupper(buffor[0]);
							if (strlen(buffor) == 0) {
								char buff[] = "--";
								for (int x = 0; x < 256; x++)
									buffor[x] = buff[x];
							}
							for (int x = 0; x < 256; x++)
								newOne->C[x] = buffor[x];
							system("cls");
						}
						else if (j == 4) {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\t%s\n", newOne->sentense);
							printf("\t\t\t\tPoprzednie wprowadzone odpowiedzi\n");
							printf("\t\t\t\t[A] %s\n", newOne->A);
							printf("\t\t\t\t[B] %s\n", newOne->B);
							printf("\t\t\t\t[C] %s\n", newOne->C);
							printf("\t\t\t\tPodaj odpowiedz D\n");
							printf("\t\t\t\t[D] ");
							gets_s(buffor, 256);
							buffor[0] = toupper(buffor[0]);
							if (strlen(buffor) == 0) {
								char buff[] = "--";
								for (int x = 0; x < 256; x++)
									buffor[x] = buff[x];
							}
							for (int x = 0; x < 256; x++)
								newOne->D[x] = buffor[x];
							system("cls");
						}
						else {
							printf("\t\t\t\tUwaga wprowadzaj dane bez znaków polskich!!!\n");
							printf("\t\t\t\t%s\n", newOne->sentense);
							printf("\t\t\t\t[A] %s\n", newOne->A);
							printf("\t\t\t\t[B] %s\n", newOne->B);
							printf("\t\t\t\t[C] %s\n", newOne->C);
							printf("\t\t\t\t[D] %s\n", newOne->D);
							printf("\t\t\t\t(Np. A lub B lub C lub D)\n");
							printf("\t\t\t\tPodaj prawidłową odpowiedz: ");
							gets_s(buffor, 256);
							buffor[0] = toupper(buffor[0]);
							for (int x = 0; x < 256; x++)
								newOne->coorectAnswear[x] = buffor[x];
							create_and_add_question(&queList, newOne);
						}
					}
				}
				printf("\t\t\t\tGratulacje!!! Udało ci sie dodać %d pytań\n\t\t\t\tdo kategorii o nazwie %s!!!\n", number, categoryName);
				write_new_questions(categoryName, queList);
				delete_list_of_category(&listaKategorii, 0);
				delete_list_of_questions(&queList, 0);
			}
			else {
				printf("\t\t\t\tPodałeś nieprawidłowa dane\n");
				goto howManyQue;
			}
		}
		else if (categoryNumber == 0);
		else {
			printf("\t\t\t\tNie ma takiej kategorii!!!\n");
			goto addque;
		}
	}
}

bool catque_wystapily(int* tabCat, int* tabQue, int size, int numberCat, int numberQue) {
	for (int i = 0; i < size; i++) {
		if (tabCat[i] == numberCat && tabQue[i] == numberQue)
			return true;
	}
	return false;
}

void random_question_mode(struct players** players_list) {
	srand(time(NULL));
	struct categories* listaKategorii = NULL;
	struct questions* listaPytan = NULL;
	char buffor[256], answear[256];
	int player = 1, flag = 0, tabCat[5], tabQue[5], size_answear = 256;;
	while (player != count_players(players_list) + 1) {
		printf("\t\t\t\tOdpowiada gracz o nicku %s\n", (*players_list)->Name);
		printf("\t\t\t\tNacisnij Enter, aby zacząć odpowiadac...");
		for (int i = 0; i < 5; i++) {
			tabCat[i] = tabQue[i] = 0;
		}
		gets_s(buffor, 256);
		system("cls");
		int proces = 1;
		while (proces != 6) {
		RANDQUESTION:;
			adding_categories_to_list(&listaKategorii);
			int amountOfCategories = count_categories(&listaKategorii);
			int randomCategory = (rand() % (amountOfCategories - 1 + 1)) + 1;
			struct categories* category = return_category(listaKategorii, randomCategory);
			adding_questions_to_list(&listaPytan, category->NameCategory);
			int amountOfQuestions = count_questions(&listaPytan);
			int randomQuestion = (rand() % (amountOfQuestions - 1 + 1)) + 1;
			struct questions* question = node_question_head(&listaPytan, randomQuestion);
			if (catque_wystapily(tabCat, tabQue, 5, randomCategory, randomQuestion)) {
				delete_list_of_category(&listaKategorii, 0);
				delete_list_of_questions(&listaPytan, 0);
				goto RANDQUESTION;
			}
			else {
				tabCat[proces - 1] = category->id;
				tabQue[proces - 1] = question->id;
			}
			if (proces == 1) printf("\n\n");
			puts("");
			printf("\t\t\t\t%s\n", question->sentense);
			printf("\t\t\t\t[A] %s\n", question->A);
			printf("\t\t\t\t[B] %s\n", question->B);
			printf("\t\t\t\t[C] %s\n", question->C);
			printf("\t\t\t\t[D] %s\n", question->D);
			printf("\t\t\t\tOdpowiedz: ");
			gets_s(answear, size_answear);
			system("cls");
			if (strlen(&answear) == 1) {
				if ((toupper(answear[0])) == *question->coorectAnswear) {
					(*players_list)->points = (*players_list)->points + 1;
					printf("\t\t\t\tPoprawna odpowiedz!!!\n\t\t\t\tDo twojego konta dodano punkt za poprawną odpowiedz\n");
				}
				else printf("\t\t\t\tNiepoprawna odpowiedz!!!\n\n");
			}
			else printf("\t\t\t\tNiepoprawna odpowiedz!!!\n\n");
			delete_list_of_category(&listaKategorii, 0);
			delete_list_of_questions(&listaPytan, 0);
			proces++;
		}
		*players_list = (*players_list)->pNext;
		player++;
	}
}


void random_question_mode_race(struct players** players_list) {
	srand(time(NULL));
	struct palyers* startP = (*players_list);
	struct categories* listaKategorii = NULL;
	struct questions* listaPytan = NULL;
	char buffor[256], answear[256];
	int player = 1, flag = 0, tabCat[5], tabQue[5], size_answear = 256;;
	double* timeTab = calloc(count_players(players_list), sizeof(double));
	while (player != count_players(players_list) + 1) {
		double playertime = 0;
		printf("\t\t\t\tOdpowiada gracz o nicku %s\n", (*players_list)->Name);
		printf("\t\t\t\tNacisnij Enter, aby zacząć odpowiadac...");
		for (int i = 0; i < 5; i++) {
			tabCat[i] = tabQue[i] = 0;
		}
		gets_s(buffor, 256);
		system("cls");
		int proces = 1;
		while (proces != 6) {
		RANDQUESTION:;
			adding_categories_to_list(&listaKategorii);
			int amountOfCategories = count_categories(&listaKategorii);
			int randomCategory = (rand() % (amountOfCategories - 1 + 1)) + 1;
			struct categories* category = return_category(listaKategorii, randomCategory);
			adding_questions_to_list(&listaPytan, category->NameCategory);
			int amountOfQuestions = count_questions(&listaPytan);
			int randomQuestion = (rand() % (amountOfQuestions - 1 + 1)) + 1;
			struct questions* question = node_question_head(&listaPytan, randomQuestion);
			if (catque_wystapily(tabCat, tabQue, 5, randomCategory, randomQuestion)) {
				delete_list_of_category(&listaKategorii, 0);
				delete_list_of_questions(&listaPytan, 0);
				goto RANDQUESTION;
			}
			else {
				tabCat[proces - 1] = category->id;
				tabQue[proces - 1] = question->id;
			}
			if (proces == 1) printf("\n\n");
			clock_t start = clock();
			puts("");
			printf("\t\t\t\t%s\n", question->sentense);
			printf("\t\t\t\t[A] %s\n", question->A);
			printf("\t\t\t\t[B] %s\n", question->B);
			printf("\t\t\t\t[C] %s\n", question->C);
			printf("\t\t\t\t[D] %s\n", question->D);
			printf("\t\t\t\tOdpowiedz: ");
			gets_s(answear, size_answear);
			clock_t stop = clock();
			double czas = ((1000 * (stop - start) + (CLOCKS_PER_SEC >> 1)) / CLOCKS_PER_SEC);
			playertime += czas;
			system("cls");
			if (strlen(&answear) == 1) {
				if ((toupper(answear[0])) == *question->coorectAnswear) {
					(*players_list)->points = (*players_list)->points + 2;
					printf("\t\t\t\tPoprawna odpowiedz!!!\n\t\t\t\tDo twojego konta dodano punkt za poprawną odpowiedz\n");
				}
				else printf("\t\t\t\tNiepoprawna odpowiedz!!!\n\n");
			}
			else printf("\t\t\t\tNiepoprawna odpowiedz!!!\n\n");
			delete_list_of_category(&listaKategorii, 0);
			delete_list_of_questions(&listaPytan, 0);
			proces++;
		}
		playertime = playertime / 1000;
		timeTab[player - 1] = playertime;
		*players_list = (*players_list)->pNext;
		player++;
	}
	if (count_players(players_list) >= 3) {
		double min1 = 1000000, min2 = 1000000, min3 = 1000000;
		struct players* player1 = NULL, * player2 = NULL, * player3 = NULL;
		for (int i = 0; i < count_players(players_list); i++) {
			if (min1 > timeTab[i]) {
				min3 = min2;
				min2 = min1;
				min1 = timeTab[i];
			}
			else if (min2 > timeTab[i]) {
				min3 = min2;
				min2 = timeTab[i];
			}

			else if (min3 > timeTab[i]) {
				min3 = timeTab[i];
			}
		}
		for (int i = 0; i < count_players(players_list); i++) {
			if (min1 == timeTab[i])
				player1 = return_player(players_list, i + 1);
			else if (min2 == timeTab[i])
				player2 = return_player(players_list, i + 1);
			else if (min3 == timeTab[i])
				player3 = return_player(players_list, i + 1);
		}
		printf("\t\t\t\tGracz %s zdobywa 3pkt. za najszybsze rozwiazanie quizu!\n\t\t\t\tZ czasem %f sek.\n", player1->Name, min1);
		player1->points = player1->points + 3;
		printf("\t\t\t\tGracz %s zdobywa 2pkt. drugie miejsce\n\t\t\t\tZ czasem: %f sek.\n", player2->Name, min2);
		player2->points = player2->points + 2;
		printf("\t\t\t\tGracz %s zdobywa 1pkt. trzecie miejsce\n\t\t\t\tZ czasem %f sek.\n", player3->Name, min3);
		player3->points = player3->points + 1;
		(*players_list) = startP;
		free(timeTab);
	}
}

int standardModeGameRace(struct players** players_list) {
	srand(time(NULL));
	struct palyers* startP = (*players_list);
	int amountOfPlayers = count_players(players_list);
	char option1[256];
	struct categories* categoriesList = NULL;
	adding_categories_to_list(&categoriesList);
categoryselect:
	printf("\t\t\t\t _____________________________________________\n");
	printf("\t\t\t\t| [0] Wyjdz                                   |\n");
	print_categories(categoriesList, categoriesList);
	printf("\t\t\t\t ---------------------------------------------\n");
	printf("\t\t\t\tWybierz kategorię:");
	gets_s(option1, 256);
	system("cls");
	int optionNumber = string_to_int(is_numbers, option1);
	if (optionNumber != -18000) {
		int amountOFCategories = count_categories(&categoriesList);
		if (optionNumber > 0 && optionNumber <= amountOFCategories) {
			struct questions* questionsList = NULL;
			char* nameCategory = return_name_category(&categoriesList, optionNumber);
			adding_questions_to_list(&questionsList, nameCategory);
			double* timeTab = calloc(count_players(players_list), sizeof(double));
			int player = 1;
			while (player != amountOfPlayers + 1) {
				int amountOfQuestions = count_questions(&questionsList);
				char answear[80];
				int proces = 1, size_answear = 80;
				int tab[5];
				char buffer[256];
				double playertime = 0;
				for (int i = 0; i < 5; i++) {
					tab[i] = 0;
				}
				printf("\t\t\t\tOdpowiada gracz o nazwie: %s\n\n", (*players_list)->Name);
				printf("\t\t\t\tNaciśnij enter aby zacząć...");
				gets_s(buffer, 256);
				system("cls");
				while (proces != 6) {
				generateRandom:;
					int randomQuestion = (rand() % (amountOfQuestions - 1 + 1)) + 1;
					struct questions* question = node_question_head(&questionsList, randomQuestion);
					if (if_question_questioned(5, tab, randomQuestion)) goto generateRandom;
					else tab[proces - 1] = question->id;
					if (proces == 1) printf("\n\n");
					clock_t start = clock();
					puts("");
					printf("\t\t\t\t%s\n", question->sentense);
					printf("\t\t\t\t[A] %s\n", question->A);
					printf("\t\t\t\t[B] %s\n", question->B);
					printf("\t\t\t\t[C] %s\n", question->C);
					printf("\t\t\t\t[D] %s\n", question->D);
					printf("\t\t\t\tOdpowiedz: ");
					gets_s(answear, size_answear);
					clock_t stop = clock();
					double czas = ((1000 * (stop - start) + (CLOCKS_PER_SEC >> 1)) / CLOCKS_PER_SEC);
					playertime += czas;
					system("cls");
					if (strlen(&answear) == 1) {
						if ((toupper(answear[0])) == *question->coorectAnswear) {
							(*players_list)->points = (*players_list)->points + 1;
							printf("\t\t\t\tPoprawna odpowiedz!!!\n\t\t\t\tDo twojego konta dodano punkt za poprawną odpowiedz\n");
						}
						else {
							printf("\t\t\t\tNiepoprawna odpowiedz!!!\n\n");
						}
					}
					else {
						printf("\t\t\t\tNiepoprawna odpowiedz!!!\n\n");
					}
					proces++;
				}
				playertime = playertime / 1000;
				timeTab[player - 1] = playertime;
				player++;
				*players_list = (*players_list)->pNext;
			}
			if (count_players(players_list) >= 3) {
				double min1 = 1000000, min2 = 1000000, min3 = 1000000;
				struct players* player1 = NULL, * player2 = NULL, * player3 = NULL;
				for (int i = 0; i < count_players(players_list); i++) {
					if (min1 > timeTab[i]) {
						min3 = min2;
						min2 = min1;
						min1 = timeTab[i];
					}
					else if (min2 > timeTab[i]) {
						min3 = min2;
						min2 = timeTab[i];
					}

					else if (min3 > timeTab[i]) {
						min3 = timeTab[i];
					}
				}
				for (int i = 0; i < count_players(players_list); i++) {
					if (min1 == timeTab[i])
						player1 = return_player(players_list, i + 1);
					else if (min2 == timeTab[i])
						player2 = return_player(players_list, i + 1);
					else if (min3 == timeTab[i])
						player3 = return_player(players_list, i + 1);
				}
				printf("\t\t\t\tGracz %s zdobywa 3pkt. za najszybsze rozwiazanie quizu!\n\t\t\t\tZ czasem %f sek.\n", player1->Name, min1);
				player1->points = player1->points + 3;
				printf("\t\t\t\tGracz %s zdobywa 2pkt. drugie miejsce\n\t\t\t\tZ czasem: %f sek.\n", player2->Name, min2);
				player2->points = player2->points + 2;
				printf("\t\t\t\tGracz %s zdobywa 1pkt. trzecie miejsce\n\t\t\t\tZ czasem %f sek.\n", player3->Name, min3);
				player3->points = player3->points + 1;
				free(timeTab);
			}
			delete_list_of_questions(&questionsList, 0);
			delete_list_of_category(&categoriesList, 0);
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