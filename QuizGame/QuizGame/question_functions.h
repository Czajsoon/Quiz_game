#ifndef _QUESTIONS_FUNCTIONS_H_
#define _QUESTIONS_FUNCTIONS_H_
void create_and_add_question(struct questions** lista_pointer, struct questions* nowy);
void add_question_to_list(struct questions** lista_pointer, struct questions** head,
	struct questions* nowy);
struct questions* create_questons_list(struct questions** lista_pointer, struct questions* nowy);
void print_questions(struct questions** lista_pointer, struct questions** head);
void print_all_questions(struct questions** lista_pointer);
int count_questions(struct questions** lista_pointer);
int questions_elements(struct questions** lista_pointer, struct questions** head, int counter);
void print_Question(struct questions** lista_pointer, int number);
void print_element_question(struct questions** lista_pointer, struct questions** head, int number);
struct questions* question(struct questions** lista_pointer, struct questions** head, int number);
struct questions* node_question_head(struct questions** lista_pointer, int number);
void delete_cycle_questions(struct questions** lista_pointer, struct questions** head);
void delete_list_of_questions(struct questions** lista_pointer, int data);
#endif // !_QUESTIONS_FUNCTIONS_H_