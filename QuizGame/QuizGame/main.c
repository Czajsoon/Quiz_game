#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include "player_structure.h"

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

		}
		else if (toupper(option[0]) == 'T') {

		}
		else if (toupper(option[0]) == 'Q') {
			printf("Dziêkujemy z grê!");
			return 0;
		}
		else {
			printf("nie ma takiej opcji :(\n wybierz inna :)\n");
			goto mainhome;
		}
	}
}