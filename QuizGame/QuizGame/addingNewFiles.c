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
#include "question_functions.h"
#include "question_structure.h"

void write_categories(struct categories* lista_pointer) {
	int elements = count_categories(&lista_pointer);
	FILE* plik;
	plik = fopen("kategorie.txt", "w");
	struct categories* start = lista_pointer;
	for (int i = 0; i < elements; i++) {
		fprintf(plik, "%s\n", lista_pointer->NameCategory);
		lista_pointer = lista_pointer->pNext;
	}
	fclose(plik);
}

void write_new_questions(char* categoryName, struct questions* lista_que) {
	int elements = count_questions(&lista_que);
	char filename[128];
	FILE* plik;
	strcpy(filename, categoryName);
	strcat(filename, ".txt");
	plik = fopen(filename, "w");
	for (int i = 0;i < elements;i++) {
		for (int j = 0;j < 6;j++) {
			if (j == 0) {
				fprintf(plik, "%s\n", lista_que->sentense);
			}
			else if (j == 1) {
				fprintf(plik, "[A] %s\n", lista_que->A);
			}
			else if (j == 2) {
				fprintf(plik, "[B] %s\n", lista_que->B);
			}
			else if (j == 3) {
				fprintf(plik, "[C] %s\n", lista_que->C);
			}
			else if (j == 4) {
				fprintf(plik, "[D] %s\n", lista_que->D);
			}
			else {
				fprintf(plik, "%s\n", lista_que->coorectAnswear);
				lista_que = lista_que->pNext;
			}
		}
	}
	fclose(plik);
}