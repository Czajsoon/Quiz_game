#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "category_structure.h"
#include "category_functions.h"
#include "question_structure.h"
#include "question_functions.h"

void adding_categories_to_list(struct categories** lista_pointer) {
	char buffor[256];
	FILE* plik = fopen("kategorie.txt", "r");
	if (!plik) {
		printf("Nie uda³o siê otworzyæ pliku!");
	}
	else {
		while (fgets(buffor, 256, plik) != NULL) {
			create_and_add_category(lista_pointer, buffor, lista_pointer);
		}
		fclose(plik);
	}
}

void adding_questions_to_list(struct questions** lista_pointer, char* name) {
	//setlocale(LC_ALL, "pl_PL.UTF-8");
	//setlocale(LC_CTYPE, "pl_PL.UTF-8");
	char buffor[256];
	int lineNumber = 0;
	char filename[100];
	char* extension = ".txt";
	struct questions* nowy = NULL;
	strcpy(filename, name);
	strcat(filename, ".txt");
	/*sprintf(filename, "%s%s", name, extension);*/
	FILE* plik = fopen(filename, "r+");
	while (fgets(buffor, 256, plik) != NULL) {
		lineNumber++;
		if (lineNumber == 1) {
			nowy = (struct questions*)malloc(sizeof(struct questions));
			char* tab = delete_new_line_sign(buffor);
			for (int i = 0; i < 256; i++)
				nowy->sentense[i] = tab[i];
		}
		else if (lineNumber == 2) {
			char* tab = delete_new_line_sign(buffor);
			for (int i = 0; i < 256; i++)
				nowy->A[i] = tab[i];
		}
		else if (lineNumber == 3) {
			char* tab = delete_new_line_sign(buffor);
			for (int i = 0; i < 256; i++)
				nowy->B[i] = tab[i];
		}
		else if (lineNumber == 4) {
			char* tab = delete_new_line_sign(buffor);
			for (int i = 0; i < 256; i++)
				nowy->C[i] = tab[i];
		}
		else if (lineNumber == 5) {
			char* tab = delete_new_line_sign(buffor);
			for (int i = 0; i < 256; i++)
				nowy->D[i] = tab[i];
		}
		else if (lineNumber == 6) {
			for (int i = 0; i < 256; i++)
				nowy->coorectAnswear[i] = buffor[i];
			create_and_add_question(lista_pointer, nowy);
			lineNumber = 0;
		}
	}
	fclose(plik);
}