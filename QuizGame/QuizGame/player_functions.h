#include <stdbool.h>
#ifndef _PLAYER_FUNCTIONS_H_
#define _PLAYER_FUNCTIONS_H_
/**Ta funkcja tworzy liste graczy o pierwszym elemencie o podanej nazwie
	@param lista_pointer wskaznik na liste graczy
	@param name nazwa nowego gracza
*/
struct players* create_list_players(struct players** lista_pointer, char name[]);
/**Ta funkcja dodaje nowego gracza o podanej nazwie lub tworzy liste graczy i dodaje jednego gracz a o podanej nazwie
	@param lista_pointer wskaznik na liste graczy
	@param name nazwa nowego gracza
	@param head wskaznik na liste graczy
*/
void create_and_add_list_players(struct players** lista_pointer, char name[], struct players** head);
/**Ta funkcja wypisuje wszystkich graczy 
	@param lista_pointer wskaznik na pierwszy element listy graczy
	@param head wskaznik na pierwszy element listy graczy
	@param index wskazyje czy jest to poczatek listy graczy zawsze na 0
*/
void print_players(struct players* lista_pointer, struct players* head, int index);
/**Ta funkcja usuwa cyklicznosc listy graczy
	@param lista_pointer wskaznik na liste graczy
	@param head wskaznik na liste graczy
*/
void delete_cycle_players(struct players** lista_pointer, struct players** head);
/**Ta funkcja usuwa liste graczy
	@param lista_pointer wskaznik na liste graczy
	@param data informacja dla funkcji zawsze na 0
*/
void delete_list_of_players(struct players** lista_pointer, int data);
/**Ta funkcja zwraca liczbe graczy 
	@param lista_pointer wskaznik na liste graczy
	@param head wskaznik na liste graczy
	@param counter licznik graczy
*/
int number_of_players(struct players** lista_pointer, struct players** head, int counter);
/**Ta funkcja zwraca liczbe graczy 
	@param lista_pointer wskaznik na liste graczy
*/
int count_players(struct players** lista_pointer);
/**Ta funkcja zwraca wskaznik gracza o podanej liczbie punktow
	@param lista_pointer wskaznik na liste graczy
	@param points liczba punktow
*/
struct players* player_with_points(struct players** lista_pointer, int points);
/**Ta funkcja zwraca wskaznik gracza o podanej liczbie punktow
	@param lista_pointer wskaznik na liste graczy
	@param head wskaznik na liste graczy
	@param points liczba punktow
*/
struct players* pointer_player_with_points(struct players** lista_pointer, struct players** head, int points);
/**Ta funkcja zwraca gracza o podanym id
	@param lista_pointer wskaznik na liste graczy
	@param head wskaznik na liste graczy
	@param number id gracza
*/
struct players* find_player_by_number(struct players** lista_pointer, struct players** head, int number);
/**Ta funkcja zwraca gracza o podanym id
	@param lista_pointer wskaznik na liste graczy
	@param number id gracza
*/
struct players* return_player(struct players** lista_pointer, int number);
/**Ta funkcja zwraca wskaznik na gracza to nowej nazwie
	@param player wskaznik na gracza
	@param newNick tablica nowego nicku
*/
struct players* change_nickname(struct players* player, char newNick[]);
/**Ta funkcja usuwa gracza o podanym id
	@param lista_pointer wskaznik na liste graczy
	@param number id gracza
*/
void deleteOnePlayerNode(struct players** lista_pointer, int number);
/**Ta funkcja przywraca cyklicznoœæ listy graczy
	@param lista_pointer wskaznik na liste graczy
	@param head wskaznik na liste graczy
*/
void cycleRegenPlayer(struct players** lista_pointer, struct players** head);
/**Ta funkcja ustawia nowe id dla wszystkich graczy 
	@param lista_pointer wskaznik na liste graczy
	@param head wskaznik na liste graczy
	@param startingNumber liczba zaczynajaca numeracje graczy
*/
void resetIdPlayers(struct players** lista_pointer, struct players** head, int startingNumber);
/**Ta funkcja zwraca czy wystapila juz taka nazwa w liscie graczy
	@param wskaznik na pierwszy element listy graczy
	@param Name sprawdzana nazwa gracza
*/
bool same_players_name(struct players* lista_pointer, char* Name);
/**Ta funkcja ustawia graczowi 0 punktow
	@param wskaznik na pierwszy element listy graczy
	@param number id gracza
*/
void resetPointsPlayer(struct players* lista_pointer, int number);
#endif // !_PLAYER_FUNCTIONS_H_
