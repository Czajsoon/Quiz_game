#include <stdbool.h>
#ifndef _CATEGORIES_FUNCTIONS_H_
#define _CATEGORIES_FUNCTIONS_H_
struct categories* create_category_list(struct categories** list_pointer, char* data);
void create_and_add_category(struct categories** lista_pointer, char* data, struct categories** head);
void print_categories(struct categories* lista_pointer, struct categories* head);
bool find_category(struct categories** lista_pointer, int number, struct categories** head);
char* return_name_category(struct categories** lista_pointer, int id);
char* name_category(struct categories** lista_pointer, int id);
int number_of_categories(struct categories** lista_pointer, struct categories** head, int counter);
int count_categories(struct categories** lista_pointer);
void delete_cycle_category(struct categories** lista_pointer, struct categories** head);
void delete_list_of_category(struct categories** lista_pointer, int data);
struct categories* return_category(struct categories* lista_pointer, int number);
#endif // !_CATEGORIES_FUNCTIONS_H_