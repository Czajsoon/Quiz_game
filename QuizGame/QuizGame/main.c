#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include "player_structure.h"
#include "player_functions.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "pl_PL");
	char option[128];
	struct players* playersList = NULL;
mainhome:
	printf(" ___________________________\n"
		"|                           |\n"
		"|         Quiz Game         |\n"
		"|___________________________|\n"
		"> Wpisz S aby rozpocz¹æ grê\n"
		"> Wpisz A aby dodaæ graczy\n"
		"> Wpisz T aby zobaczyæ statystyki graczy\n"
		"> Wpisz Q aby wyjœæ z gry\n"
		"Wybierz opcjê: ");
	scanf("%s", &option);
	if (strlen(&option) != 1) {
		system("cls");
		printf("nie ma takiej opcji :(\nWybierz inna istenij¹c¹ :)\n");
		goto mainhome;
	}
	else {
		if (toupper(option[0]) == 'S') {
			printf("chuju z³oty");
		}
		else if (toupper(option[0]) == 'A') {
			system("cls");
			playersList = new_players(&playersList);
			goto mainhome;
		}
		else if (toupper(option[0]) == 'T') {
			if (playersList != NULL) {
				system("cls");
				
				goto mainhome;
			}
			else {
				system("cls");
				printf("Lista graczy jest pusta najpierw dodaj graczy!\n");
				goto mainhome;
			}
		}
		else if (toupper(option[0]) == 'Q') {
			system("cls");
			printf("Dziêkujemy z grê!");
			return 0;
		}
		else {
			system("cls");
			printf("nie ma takiej opcji :(\n wybierz inna :)\n");
			goto mainhome;
		}
	}
}