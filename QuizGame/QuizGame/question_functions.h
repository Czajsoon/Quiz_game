#ifndef _QUESTIONS_FUNCTIONS_H_
#define _QUESTIONS_FUNCTIONS_H_
/**Ta funkcja tworzy nowa liste pytañ lub dodaje pytanie do istnijacej listy
	@param lista_pointer wskaznik na liste pytan
	@param nowy wskaznik na nowy element do dodania
*/
void create_and_add_question(struct questions** lista_pointer, struct questions* nowy);
/**Ta funkcja dodaje pytanie do istniejacej listy
	@param lista_pointer wskaznik na liste pytan
	@param head wskaznik na liste pytan
	@param nowy wskaznik na nowy element do dodania
*/
void add_question_to_list(struct questions** lista_pointer, struct questions** head,
	struct questions* nowy);
/**Ta funkcja tworzy nowa liste pytan 
	@param lista_pointer wskaznik na liste pytan
	@param nowy wskaznik na nowy element do dodania
*/
struct questions* create_questons_list(struct questions** lista_pointer, struct questions* nowy);
/**Ta funkcja wypisuje pytania
	@param lista_pointer wskaznik na liste pytan
	@param head wskaznik na liste pytan
*/
void print_questions(struct questions** lista_pointer, struct questions** head);
/**Ta funkcja wypisuje pytania
	@param lista_pointer wskaznik na liste pytan
*/
void print_all_questions(struct questions** lista_pointer);
/**Ta funkcja zlicza ilosc pytan
	@param lista_pointer wskaznik na liste pytan
*/
int count_questions(struct questions** lista_pointer);
/**Ta funkcja zlicza ilosc pytan
	@param lista_pointer wskaznik na liste pytan
	@param head wskaznik na liste pytan
	@param counter licznik pytan
*/
int questions_elements(struct questions** lista_pointer, struct questions** head, int counter);
/**Ta funkcja wypisuje pytanie o konkretnym id
	@param lista_pointer wskaznik na liste pytan
	@param number numer id pytania
*/
void print_Question(struct questions** lista_pointer, int number);
/**Ta funkcja wypisuje pytanie o konkretnym id
	@param lista_pointer wskaznik na liste pytan
	@param head wskaznik na liste pytan
	@param number numer id pytania
*/
void print_element_question(struct questions** lista_pointer, struct questions** head, int number);
/**Ta funkcja zwraca wskaznik na konkretne pytanie o podanym id
	@param lista_pointer wskaznik na liste pytan
	@param head wskaznik na liste pytan
	@param number numer id pytania
*/
struct questions* question(struct questions** lista_pointer, struct questions** head, int number);
/**Ta funkcja zwraca wskaznik na konkretne pytanie o podanym id
	@param lista_pointer wskaznik na liste pytan
	@param number numer id pytania
*/
struct questions* node_question_head(struct questions** lista_pointer, int number);
/**Ta funkcja usuwa cyklicznosc listy 
	@param lista_pointer wskaznik na liste pytan
	@param head wskaznik na liste pytan
*/
void delete_cycle_questions(struct questions** lista_pointer, struct questions** head);
/**Ta funkcja usuwa liste pytan
	@param lista_pointer wskaznik na liste pytan
	@param data informacja dla funkcji zawsze na 0
*/
void delete_list_of_questions(struct questions** lista_pointer, int data);
/**Ta funkcja wypisuje wszystkie pytania z listy
	@param lista_pointer wskaznik napierwszy element listy pytan
*/
void printAllQue(struct questions* lista_pointer);
/**Ta funkcja zwraca wskaznik na pytanie o podanum id
	@param lista_pointer wskaznik na liste pytan
	@param number id pytania
*/
struct questions* return_que(struct questions* lista_pointer, int number);
#endif // !_QUESTIONS_FUNCTIONS_H_