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
	int flagOrientation = 0, size_option = 128;
	struct players* playersList = NULL;
	if (flagOrientation == 0) {
	mainhome:
		printf("\t\t\t\t ____________________________________________\n"
			"\t\t\t\t|                                            | \n"
			"\t\t\t\t|                  Quiz Game                 |\n"
			"\t\t\t\t|____________________________________________|\n"
			"\t\t\t\t| > Wpisz S aby rozpocz�� gr�                |\n"
			"\t\t\t\t| > Wpisz A aby doda� graczy                 |\n"
			"\t\t\t\t| > Wpisz T aby zobaczy� statystyki graczy   |\n"
			"\t\t\t\t| > Wpisz Q aby wyj�� z gry                  |\n"
			"\t\t\t\t --------------------------------------------\n"
			"\t\t\t\t  Wybierz opcj�: ");
		gets_s(option, size_option);
		system("cls");
		if (strlen(option) != 1) {
			printf("\t\t\t\tNie ma takiej opcji :(\n\t\t\t\tWybierz inna istenij�c� :)\n");
			goto mainhome;
		}
		else {
			if (toupper(option[0]) == 'S') {
			modeselect:
				if (playersList) {
					char optionMode[128];
					printf("\t\t\t\t __________________________________________________\n");
					printf("\t\t\t\t | [0] |           ->       Cofnij      <-         |\n");
					printf("\t\t\t\t | [1] |         ->      Standardowy      <-       |\n");
					printf("\t\t\t\t | [2] |         ->   Wszystkie pytania   <-       |\n");
					printf("\t\t\t\t | [3] |         ->   Standardowy Race   <-        |\n");
					printf("\t\t\t\t | [4] |        -> Wszystkie Pytania Race <-       |\n");
					printf("\t\t\t\t | [5] |     -> Standard zmienna ilo�� pyta� <-    |\n");
					printf("\t\t\t\t | [6] | ->Wszystkie Pytania zmienna ilo�� pyta�<- |\n");
					printf("\t\t\t\t --------------------------------------------------\n");
					printf("\t\t\t\t  Wybierz opcj� : ");
					gets_s(optionMode, 128);
					system("cls");
					int numberMode = string_to_int(is_numbers, optionMode);
					if (numberMode != -18000) {
						if (numberMode == 1) {
							int aftergame = standardModeGame(&playersList);
							if (aftergame == 0) {
								system("cls");
								goto mainhome;
							}
							else
								system("cls");
							goto mainhome1;
						}
						else if (numberMode == 2) {
							random_question_mode(&playersList);
							system("cls");
							goto mainhome1;
						}
						if (numberMode == 3) {
							int aftergame = standardModeGameRace(&playersList);
							if (aftergame == 0) {
								goto mainhome;
							}
							else
								goto mainhome1;
						}
						else if (numberMode == 4) {
							random_question_mode_race(&playersList);
							goto mainhome1;
						}
						else if (numberMode == 5) {
							int aftergame = standarModeMQue(&playersList);
							if (aftergame == 0) {
								goto mainhome;
							}
							else
								goto mainhome1;
						}
						else if (numberMode == 6) {

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
						printf("\t\t\t\tWpisa�e� nieprawid�owe dane!\n");
						puts("");
						goto modeselect;
					}
				}
				else {
					system("cls");
					puts("");
					printf("\t\t\t\tNajpierw nale�y doda� gracza!\n\t\t\t\tWr�� tutaj jak dodasz gracza :)\n");
					puts("");
					goto mainhome;
				}
			}
			else if (toupper(option[0]) == 'A') {
				system("cls");
				playersList = new_players(&playersList);
				system("cls");
				goto mainhome;
			}
			else if (toupper(option[0]) == 'T') {
				if (playersList != NULL) {
					char optionStats[128];
					int size_stats = 128;
					system("cls");
				selectstatsmenu:;
					players_stats(&playersList);
					puts("");
					printf("\t\t\t\t _____________________________________________\n");
					printf("\t\t\t\t|> Wpisz Z aby zmienic dowolny nick           |\n");
					printf("\t\t\t\t|> Wpisz D aby usun�� dowolnego gracza        |\n");
					printf("\t\t\t\t|> Wpisz A aby usun�� wszystkich graczy       |\n");
					printf("\t\t\t\t|> Naci�nij Enter aby przej�� do menu g��wnego|\n");
					printf("\t\t\t\t ---------------------------------------------\n");
					printf("\t\t\t\t   Wpisz opcj�: ");
					gets_s(optionStats, size_stats);
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
						else if (optionStats[0] == '\n') goto mainhome;
						else {
							printf("\t\t\t\tNie ma takiej opcji w wyborze\n\t\t\t\tWybierz istniej�c�\n");
							goto selectstatsmenu;
						}
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
				printf("\t\t\t\tDzi�kujemy z gr�!");
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
		"\t\t\t\t| > Wpisz S aby rozpocz�� gr�                |\n"
		"\t\t\t\t| > Wpisz A aby doda� graczy                 |\n"
		"\t\t\t\t| > Wpisz T aby zobaczy� statystyki graczy   |\n"
		"\t\t\t\t| > Wpisz D aby doda� pytanie                |\n"
		"\t\t\t\t| > Wpisz C aby doda� kategori�              |\n"
		"\t\t\t\t| > Wpisz Z aby zmieni� tre�� pytania        |\n"
		"\t\t\t\t| > Wpisz Q aby wyj�� z gry                  |\n"
		"\t\t\t\t --------------------------------------------\n"
		"\t\t\t\t  Wybierz opcj�: ");
	gets_s(option, size_option);
	system("cls");
	if (strlen(option) != 1) {
		printf("\t\t\t\tNie ma takiej opcji :(\n\t\t\t\tWybierz inna istenij�c� :)\n");
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
				printf("\t\t\t\t | [3] |      ->   Standardowy Race   <-     |\n");
				printf("\t\t\t\t | [4] | -> Tryb wy�cigu wszystkich pyta� <- |\n");
				printf("\t\t\t\t | [5] |     -> Standard zmienna ilo�� pyta� <-    |\n");
				printf("\t\t\t\t --------------------------------------------\n");
				printf("\t\t\t\t  Wybierz opcj� : ");
				gets_s(optionMode, 128);
				system("cls");
				int numberMode = string_to_int(is_numbers, optionMode);
				if (numberMode != -18000) {
					if (numberMode == 1) {
						int aftergame = standardModeGame(&playersList);
						if (aftergame == 0) {
							system("cls");
							goto mainhome1;
						}
						else
							system("cls");
						goto mainhome1;
					}
					else if (numberMode == 2) {
						random_question_mode(&playersList);
						system("cls");
						goto mainhome1;
					}
					if (numberMode == 3) {
						int aftergame = standardModeGameRace(&playersList);
						if (aftergame == 0) {
							goto mainhome1;
						}
						else
							goto mainhome1;
					}
					else if (numberMode == 4) {
						random_question_mode_race(&playersList);
						goto mainhome1;
					}
					else if (numberMode == 5) {
						int aftergame = standarModeMQue(&playersList);
						if (aftergame == 0) {
							goto mainhome1;
						}
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
					printf("\t\t\t\tWpisa�e� nieprawid�owe dane!\n");
					puts("");
					goto modeselect1;
				}
			}
			else {
				system("cls");
				puts("");
				printf("\t\t\t\tNajpierw nale�y doda� gracza!\n\t\t\t\tWr�� tutaj jak dodasz gracza :)\n");
				puts("");
				goto mainhome;
			}
		}
		else if (toupper(option[0]) == 'A') {
			system("cls");
			playersList = new_players(&playersList);
			system("cls");
			goto mainhome1;
		}
		else if (toupper(option[0]) == 'T') {
			if (playersList != NULL) {
				system("cls");
			selectstatsmenu1:;
				char optionStats[128];
				int size_stats = 128;
				players_stats(&playersList);
				puts("");
				printf("\t\t\t\t _____________________________________________\n");
				printf("\t\t\t\t|> Wpisz Z aby zmienic dowolny nick           |\n");
				printf("\t\t\t\t|> Wpisz D aby usun�� dowolnego gracza        |\n");
				printf("\t\t\t\t|> Wpisz A aby usun�� wszystkich graczy       |\n");
				printf("\t\t\t\t|> Wpisz R aby zresetowa� punkty              |\n");
				printf("\t\t\t\t|> Wpisz N aby zresetowa� punkty dla gracza   |\n");
				printf("\t\t\t\t|> Naci�nij Enter aby przej�� do menu g��wnego|\n");
				printf("\t\t\t\t ---------------------------------------------\n");
				printf("\t\t\t\t   Wpisz opcj�: ");
				gets_s(optionStats, size_stats);
				system("cls");
				if (strlen(optionStats) == 0) goto mainhome1;
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
					else if (toupper(optionStats[0]) == 'N') {
						resetPlayerPoints(playersList);
						goto mainhome1;
					}
					else if (strlen(optionStats) == 0) goto mainhome1;
					else {
						printf("\t\t\t\tNie ma takiej opcji w wyborze\n\t\t\t\tWybierz istniej�c�\n");
						goto selectstatsmenu1;
					}
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
		else if (toupper(option[0]) == 'Z') {
			changeQuestion();
		}
		else if (toupper(option[0]) == 'Q') {
			system("cls");
			printf("\t\t\t\tDzi�kujemy z gr�!");
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