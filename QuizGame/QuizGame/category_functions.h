#include <stdbool.h>
#ifndef _CATEGORIES_FUNCTIONS_H_
#define _CATEGORIES_FUNCTIONS_H_
/**Ta funkcja dodaje nowa kategorie i zwraca jej poczatek
	@param list_pointer wskaünik na liste kategorii
	@param data nazwa nowej kategorii
*/
struct categories* create_category_list(struct categories** list_pointer, char* data);
/**Ta funkcja dodaje nowy element do listy jesli jest pysta to ja tworzy
	@param lista_pointer wskaznik na liste kategorii
	@param data nazwa nowej kategorii
	@param head wskaønik na poczatek listy kategorii
*/
void create_and_add_category(struct categories** lista_pointer, char* data, struct categories** head);
/**Ta funkcja wypisuje cala liste kategorii
	@param lista_pointer wskaznik na poczatek listy kategorii
	@param head wskaznik na pierwszy element kategorii
*/
void print_categories(struct categories* lista_pointer, struct categories* head);
/**Ta funkcja zwraca wartosc true/false jesli zostala lub nie znaleziona kategoria o podanym numerze
	@param lista_pointer wskaznik na liste kategorii
	@param number id kategorii
	@param head wskaønik na poczatek listy kategorii
*/
bool find_category(struct categories** lista_pointer, int number, struct categories** head);
/**Ta funkcja zwraca nazwe kategorii 
	@param lista_pointer wskaznik na liste kategorii
	@param id numer id kategorii
*/
char* return_name_category(struct categories** lista_pointer, int id);
/**Ta funkcja zwraca nazwe kategorii
	@param lista_pointer wskaznik na liste kategorii
	@param id numer id kategorii
*/
char* name_category(struct categories** lista_pointer, int id);
/**Ta funkcja zwraca liczbe kategorii w liscie
	@param lista_pointer wskaznik na liste kategorii
	@param head wskaønik na poczatek listy kategorii
	@param counter licznik kategorii
*/
int number_of_categories(struct categories** lista_pointer, struct categories** head, int counter);
/**Ta funkcja zwraca liczbe kategorii w liscie
	@param lista_pointer wskaznik na poczatek listy kategorii
*/
int count_categories(struct categories** lista_pointer);
/**Ta funkcja usuwa cyklicznosc listy 
	@param lista_pointer wskaznik na liste kategorii
	@param head wskaønik na poczatek listy kategorii
*/
void delete_cycle_category(struct categories** lista_pointer, struct categories** head);
/**Ta funkcja usuwa cala liste kategorii
	@param lista_pointer wskaznik na liste kategorii
	@param data informacja dla funkcji o usuwanym elemencie zawsze 0
*/
void delete_list_of_category(struct categories** lista_pointer, int data);
/**Ta funkcja zwraca wskaznik na strukture i podanym id
	@param lista_pointer wskaznik na liste kategorii
	@param number numer id kategorii
*/
struct categories* return_category(struct categories* lista_pointer, int number);
#endif // !_CATEGORIES_FUNCTIONS_H_