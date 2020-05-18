#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <wchar.h>
#include "category_structure.h"
#include "category_functions.h"
#include "question_structure.h"
#include "question_functions.h"

char* delete_new_line_sign(char* string) {
	int lenth = strlen(string);
	char buffor[256];
	for (int i = 0; i < lenth + 1; i++) {
		char c = string[i];
		if (c != '\n') {
			if (c == '\0') {
				buffor[i] = '\0';
				return buffor;
			}
			buffor[i] = c;
		}
		else {
			buffor[i] = '\0';
			return buffor;
		}
	}
}

char* delete_index_in_question(char* this_string) {
	int lenth = strlen(this_string);
	int flag = 0;
	int index1 = 0;
	int index = 0;
	char buffor[256];
	for (int i = 0;i < lenth+1;i++) {
		char c = this_string[i];
		if (flag == 0) {
			if (isspace(c))
				flag++;
			index++;
		}
	}
	for (int i = 0;i < lenth+1;i++) {
		if (i >= index) {
			buffor[index1] = this_string[index];
			index++;
			index1++;
		}
	}
	return buffor;
}

void adding_categories_to_list(struct categories** lista_pointer) {
	wchar_t buffor[256];
	wchar_t buffor1[256];
	FILE* plik = fopen("kategorie.txt", "r");
	if (!plik) {
		printf("nie uda³o siê otworzyæ pliku!");
	}
	else {
		while (fgets(buffor, 256, plik) != NULL) {
			wchar_t* buf = delete_new_line_sign(buffor);
			for (int i = 0; i < 256; i++)
				buffor[i] = buf[i];
			create_and_add_category(lista_pointer, buffor, lista_pointer);
		}
		fclose(plik);
	}
}

void adding_questions_to_list(struct questions** lista_pointer, char* name) {
	wchar_t buffor[256];
	int linenumber = 0;
	char filename[100];
	char* extension = ".txt";
	struct questions* nowy = NULL;
	strcpy(filename, name);
	strcat(filename, ".txt");
	FILE* plik = fopen(filename, "r+");
	while (fgets(buffor, 256, plik) != NULL) {
		linenumber++;
		if (linenumber == 1) {
			nowy = (struct questions*)malloc(sizeof(struct questions));
			wchar_t* tab = delete_new_line_sign(buffor);
			wchar_t buffor1[256];
			for (int i = 0;i < 256;i++) {
				buffor1[i] = tab[i];
			}
			char* tab1 = delete_new_line_sign(buffor1);
			for (int i = 0; i < 256; i++)
				nowy->sentense[i] = tab1[i];
		}
		else if (linenumber == 2) {
			wchar_t buffor1[256];
			wchar_t* tab = delete_index_in_question(buffor);
			for (int i = 0;i < 256;i++) {
				buffor1[i] = tab[i];
			}
			char* tab1 = delete_new_line_sign(buffor1);
			for (int i = 0; i < 256; i++)
				nowy->A[i] = tab1[i];
		}
		else if (linenumber == 3) {
			wchar_t buffor1[256];
			wchar_t* tab = delete_index_in_question(buffor);
			for (int i = 0;i < 256;i++) {
				buffor1[i] = tab[i];
			}
			char* tab1 = delete_new_line_sign(buffor1);
			for (int i = 0; i < 256; i++)
				nowy->B[i] = tab1[i];
		}
		else if (linenumber == 4) {
			wchar_t buffor1[256];
			wchar_t* tab = delete_index_in_question(buffor);
			for (int i = 0;i < 256;i++) {
				buffor1[i] = tab[i];
			}
			char* tab1 = delete_new_line_sign(buffor1);
			for (int i = 0; i < 256; i++)
				nowy->C[i] = tab1[i];
		}
		else if (linenumber == 5) {
			wchar_t buffor1[256];
			wchar_t* tab = delete_index_in_question(buffor);
			for (int i = 0;i < 256;i++) {
				buffor1[i] = tab[i];
			}
			char* tab1 = delete_new_line_sign(buffor1);
			for (int i = 0; i < 256; i++)
				nowy->D[i] = tab1[i];
		}
		else if (linenumber == 6) {
			wchar_t* tab = delete_new_line_sign(buffor);
			for (int i = 0; i < 256; i++)
				nowy->coorectAnswear[i] = tab[i];
			create_and_add_question(lista_pointer, nowy);
			linenumber = 0;
		}
	}
	fclose(plik);
}