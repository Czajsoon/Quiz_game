#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#include "question_structure.h"

struct questions* create_questons_list(struct questions** lista_pointer, struct questions* nowy) {
	nowy->id = 1;
	*lista_pointer = nowy;
	(*lista_pointer)->pNext = nowy;
	return *lista_pointer;
}

void add_question_to_list(struct questions** lista_pointer, struct questions** head,
	struct questions* nowy) {
	if ((*lista_pointer)->pNext != *head)
		add_question_to_list(&(*lista_pointer)->pNext, head, nowy);
	else {
		nowy->id = (*lista_pointer)->id + 1;
		(*lista_pointer)->pNext = nowy;
		nowy->pNext = *head;
	}
}

void create_and_add_question(struct questions** lista_pointer, struct questions* nowy) {
	if (*lista_pointer)
		add_question_to_list(lista_pointer, lista_pointer, nowy);
	else
		*lista_pointer = create_questons_list(lista_pointer, nowy);
}

void print_questions(struct questions** lista_pointer, struct questions** head) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head) {
			printf("Pytanie nr[%d].\n Tre�� pytania: %s\n%s\n%s\n%s\n%s\nPoprawna odpowiedz to: %s", (*lista_pointer)->id, (*lista_pointer)->sentense
				, (*lista_pointer)->A, (*lista_pointer)->B, (*lista_pointer)->C, (*lista_pointer)->D, (*lista_pointer)->coorectAnswear);
			print_questions(&(*lista_pointer)->pNext, head);
		}
		else printf("Pytanie nr[%d].\n Tre�� pytania: %s\n%s\n%s\n%s\n%s\nPoprawna odpowiedz to: %s", (*lista_pointer)->id, (*lista_pointer)->sentense
			, (*lista_pointer)->A, (*lista_pointer)->B, (*lista_pointer)->C, (*lista_pointer)->D, (*lista_pointer)->coorectAnswear);
	}
}

void print_all_questions(struct questions** lista_pointer) {
	print_questions(lista_pointer, lista_pointer);
}

int questions_elements(struct questions** lista_pointer, struct questions** head, int counter) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head) {
			return 1 + questions_elements(&(*lista_pointer)->pNext, head, counter);
		}
		else {
			return counter + 1;
		}
	}
	else return counter;
}

int count_questions(struct questions** lista_pointer) {
	int counter = 0;
	return questions_elements(lista_pointer, lista_pointer, counter);
}

void print_element_question(struct questions** lista_pointer, struct questions** head, int number) {
	if (*lista_pointer) {
		if ((*lista_pointer)->pNext != *head) {
			if ((*lista_pointer)->id == number) {
				printf("%s\n%s\n%s\n%s\n%s\n", (*lista_pointer)->sentense, (*lista_pointer)->A, (*lista_pointer)->B, (*lista_pointer)->C,
					(*lista_pointer)->D);
				return;
			}
			print_element_question(&(*lista_pointer)->pNext, head, number);
		}
		else {
			if ((*lista_pointer)->id == number)
				printf("%s\n%s\n%s\n%s\n%s\n", (*lista_pointer)->sentense, (*lista_pointer)->A, (*lista_pointer)->B, (*lista_pointer)->C,
					(*lista_pointer)->D);
			return;
		}
	}
}

void print_Question(struct questions** lista_pointer, int number) {
	print_element_question(lista_pointer, lista_pointer, number);
}