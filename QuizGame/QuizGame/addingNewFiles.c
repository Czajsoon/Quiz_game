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