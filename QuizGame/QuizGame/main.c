#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include "player_structure.h"
#include "player_functions.h"
#include "functions.h"
#include "category_functions.h"
#include "reading_files.h"

int main() {
	setlocale(LC_CTYPE, "UTF-8");
	setlocale(LC_ALL, "pl_PL");
	char option[128];
	int flagOrientation = 0;
	struct players* playersList = NULL;
	if (flagOrientation == 0) {
	mainhome:
		printf("\t\t\t\t ____________________________________________\n"
			"\t\t\t\t|                                            | \n"
			"\t\t\t\t|                  Quiz Game                 |\n"
			"\t\t\t\t|____________________________________________|\n"
			"\t\t\t\t| > Wpisz S aby rozpocz¹æ grê                |\n"
			"\t\t\t\t| > Wpisz A aby dodaæ graczy                 |\n"
			"\t\t\t\t| > Wpisz T aby zobaczyæ statystyki graczy   |\n"
			"\t\t\t\t| > Wpisz Q aby wyjœæ z gry                  |\n"
			"\t\t\t\t --------------------------------------------\n"
			"\t\t\t\t  Wybierz opcjê: ");
		scanf("%s", &option);
		system("cls");
		if (strlen(&option) != 1) {
			printf("\t\t\t\tNie ma takiej opcji :(\n\t\t\t\tWybierz inna istenij¹c¹ :)\n");
			goto mainhome;
		}
		else {
			if (toupper(option[0]) == 'S') {
			modeselect:
				if (playersList) {
					char optionMode[128];
					printf("\t\t\t\t ____________________________________________\n");
					printf("\t\t\t\t | [0] |        ->       Cofnij      <-      |\n");
					printf("\t\t\t\t | [1] |      ->      Standardowy      <-    |\n");
					printf("\t\t\t\t | [2] |      ->   Wszystkie pytania   <-    |\n");
					printf("\t\t\t\t --------------------------------------------\n");
					printf("\t\t\t\t  Wybierz opcjê : ");
					scanf("%s", &optionMode);
					system("cls");
					int numberMode = string_to_int(is_numbers, optionMode);
					if (numberMode != -18000) {
						if (numberMode == 1) {
							int aftergame = standardModeGame(&playersList);
							if (aftergame == 0)
								goto mainhome;
							else
								goto mainhome1;
						}
						else if (numberMode == 2) {
							int aftergame = random_question_mode(&playersList);
							if (aftergame == 0)
								goto mainhome;
							else
								goto mainhome1;
						}
						else if (numberMode == 0)
							goto mainhome;
						else {
							system("cls");
							printf("\t\t\t\tNie ma takiego trybu gry\n\t\t\t\tWybierz inny\n");
							goto modeselect;
						}
					}
					else {
						system("cls");
						printf("\t\t\t\tWpisa³eœ nieprawid³owe dane!\n");
						puts("");
						goto modeselect;
					}
				}
				else {
					system("cls");
					puts("");
					printf("\t\t\t\tNajpierw nale¿y dodaæ gracza!\n\t\t\t\tWróæ tutaj jak dodasz gracza :)\n");
					puts("");
					goto mainhome;
				}
			}
			else if (toupper(option[0]) == 'A') {
				system("cls");
				playersList = new_players(&playersList);
				goto mainhome;
			}
			else if (toupper(option[0]) == 'T') {
				if (playersList != NULL) {
					char optionStats[128];
					system("cls");
					players_stats(&playersList);
					puts("");
					printf("\t\t\t\t ____________________________________________\n");
					printf("\t\t\t\t|> Wpisz Z aby zmienic dowolny nick          |\n");
					printf("\t\t\t\t|> Wpisz D aby usun¹æ dowolnego gracza       |\n");
					printf("\t\t\t\t|> Wpisz A aby usun¹æ wszystkich graczy      |\n");
					printf("\t\t\t\t|> Wpisz R aby zresetowaæ punkty             |\n");
					printf("\t\t\t\t|> Wpisz coœ dowolnego aby kontynuowaæ       |\n");
					printf("\t\t\t\t --------------------------------------------\n");
					printf("\t\t\t\t   Wpisz opcjê: ");
					scanf("%s", &optionStats);
					system("cls");
					if (strlen(optionStats) != 1) goto mainhome;
					else {
						if (toupper(optionStats[0]) == 'Z') {
							changeNickname(&playersList);
							goto mainhome;
						}
						else if (toupper(optionStats[0]) == 'D') {
							deleteOnePlayer(&playersList);
							goto mainhome;
						}
						else if (toupper(optionStats[0]) == 'A') {
							delete_list_of_players(&playersList, 0);
							goto mainhome;
						}
						else if (toupper(optionStats[0]) == 'R') {
							resetPoints(&playersList, &playersList);
							goto mainhome;
						}
						else goto mainhome;
					}

				}
				else {
					system("cls");
					printf("\t\t\t\tLista graczy jest pusta najpierw dodaj graczy!\n");
					goto mainhome;
				}
			}
			else if (toupper(option[0]) == 'Q') {
				system("cls");
				printf("\t\t\t\tDziêkujemy z grê!");
				delete_list_of_players(&playersList, 0);
				return 0;
			}
			else {
				system("cls");
				printf("\t\t\t\tNie ma takiej opcji :(\n\t\t\t\twybierz inna :)\n");
				goto mainhome;
			}
		}
	}
mainhome1:
	printf("\t\t\t\t ____________________________________________\n"
		"\t\t\t\t|                                            | \n"
		"\t\t\t\t|                  Quiz Game                 |\n"
		"\t\t\t\t|____________________________________________|\n"
		"\t\t\t\t| > Wpisz S aby rozpocz¹æ grê                |\n"
		"\t\t\t\t| > Wpisz A aby dodaæ graczy                 |\n"
		"\t\t\t\t| > Wpisz T aby zobaczyæ statystyki graczy   |\n"
		"\t\t\t\t| > Wpisz D aby dodaæ pytanie                |\n"
		"\t\t\t\t| > Wpisz C aby dodaæ kategoriê              |\n"
		"\t\t\t\t| > Wpisz Q aby wyjœæ z gry                  |\n"
		"\t\t\t\t --------------------------------------------\n"
		"\t\t\t\t  Wybierz opcjê: ");
	scanf("%s", &option);
	if (strlen(&option) != 1) {
		printf("\t\t\t\tNie ma takiej opcji :(\n\t\t\t\tWybierz inna istenij¹c¹ :)\n");
		goto mainhome1;
	}
	else {
		if (toupper(option[0]) == 'S') {
		modeselect1:
			if (playersList) {
				char optionMode[128];
				printf("\t\t\t\t ____________________________________________\n");
				printf("\t\t\t\t | [0] |        ->       Cofnij      <-      |\n");
				printf("\t\t\t\t | [1] |      ->      Standardowy      <-    |\n");
				printf("\t\t\t\t | [2] |      ->   Wszystkie pytania   <-    |\n");
				printf("\t\t\t\t --------------------------------------------\n");
				printf("\t\t\t\t  Wybierz opcjê : ");
				scanf("%s", &optionMode);
				system("cls");
				int numberMode = string_to_int(is_numbers, optionMode);
				if (numberMode != -18000) {
					if (numberMode == 1) {
						int aftergame = standardModeGame(&playersList);
						if (aftergame == 0)
							goto mainhome1;
						else
							goto mainhome1;
					}
					else if (numberMode == 2) {
						int aftergame = random_question_mode(&playersList);
						if (aftergame == 0)
							goto mainhome1;
						else
							goto mainhome1;
					}
					else if (numberMode == 0)
						goto mainhome1;
					else {
						system("cls");
						printf("\t\t\t\tNie ma takiego trybu gry\n\t\t\t\tWybierz inny\n");
						goto modeselect1;
					}
				}
				else {
					system("cls");
					printf("\t\t\t\tWpisa³eœ nieprawid³owe dane!\n");
					puts("");
					goto modeselect1;
				}
			}
			else {
				system("cls");
				puts("");
				printf("\t\t\t\tNajpierw nale¿y dodaæ gracza!\n\t\t\t\tWróæ tutaj jak dodasz gracza :)\n");
				puts("");
				goto mainhome;
			}
		}
		else if (toupper(option[0]) == 'A') {
			system("cls");
			playersList = new_players(&playersList);
			goto mainhome1;
		}
		else if (toupper(option[0]) == 'T') {
			if (playersList != NULL) {
				char optionStats[128];
				system("cls");
				players_stats(&playersList);
				puts("");
				printf("\t\t\t\t ____________________________________________\n");
				printf("\t\t\t\t|> Wpisz Z aby zmienic dowolny nick          |\n");
				printf("\t\t\t\t|> Wpisz D aby usun¹æ dowolnego gracza       |\n");
				printf("\t\t\t\t|> Wpisz A aby usun¹æ wszystkich graczy      |\n");
				printf("\t\t\t\t|> Wpisz R aby zresetowaæ punkty             |\n");
				printf("\t\t\t\t|> Wpisz coœ dowolnego aby kontynuowaæ       |\n");
				printf("\t\t\t\t --------------------------------------------\n");
				printf("\t\t\t\t   Wpisz opcjê: ");
				scanf("%s", &optionStats);
				system("cls");
				if (strlen(optionStats) != 1) goto mainhome1;
				else {
					if (toupper(optionStats[0]) == 'Z') {
						changeNickname(&playersList);
						goto mainhome1;
					}
					else if (toupper(optionStats[0]) == 'D') {
						deleteOnePlayer(&playersList);
						if (playersList) {
							goto mainhome1;
						}
						else {
							goto mainhome;
						}
					}
					else if (toupper(optionStats[0]) == 'A') {
						delete_list_of_players(&playersList, 0);
						goto mainhome;
					}
					else if (toupper(optionStats[0]) == 'R') {
						resetPoints(&playersList, &playersList);
						goto mainhome1;
					}
					else goto mainhome1;
				}

			}
			else {
				system("cls");
				printf("\t\t\t\tLista graczy jest pusta najpierw dodaj graczy!\n");
				goto mainhome;
			}
		}
		else if (toupper(option[0]) == 'D') {
			add_new_question();
			goto mainhome1;
		}
		else if (toupper(option[0]) == 'C') {
			addNewCategoryByPlayer();
			goto mainhome1;
		}
		else if (toupper(option[0]) == 'Q') {
			system("cls");
			printf("\t\t\t\tDziêkujemy z grê!");
			delete_list_of_players(&playersList, 0);
			return 0;
		}
		else {
			system("cls");
			printf("\t\t\t\tNie ma takiej opcji :(\n\t\t\t\twybierz inna :)\n");
			goto mainhome1;
		}
	}
}