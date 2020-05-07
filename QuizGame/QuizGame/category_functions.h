#ifndef _CATEGORIES_FUNCTIONS_H_
#define _CATEGORIES_FUNCTIONS_H_
struct categories* create_category_list(struct categories** list_pointer, char* data);
void create_and_add_category(struct categories** lista_pointer, char* data, struct categories** head);
void print_categories(struct categories* lista_pointer, struct categories* head);
bool find_category(struct categories** lista_pointer, int number, struct categories** head);
char* return_name_category(struct categories** lista_pointer, int id);
char* name_category(struct categories** lista_pointer, int id);
void delete_new_line_categories(struct categories** lista_pointer);
void delete_new_line_sign_categories(struct categories** lista_pointer, struct categories** head);
#endif // !_CATEGORIES_FUNCTIONS_H_