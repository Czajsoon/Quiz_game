#ifndef _PLAYER_FUNCTIONS_H_
#define _PLAYER_FUNCTIONS_H_
struct players* create_list_players(struct players** lista_pointer, char name[]);
void create_and_add_list_players(struct players** lista_pointer, char name[], struct players** head);
void print_players(struct players* lista_pointer, struct players* head, int index);
void delete_cycle_players(struct players** lista_pointer, struct players** head);
void delete_list_of_players(struct players** lista_pointer, int data);
int number_of_players(struct players** lista_pointer, struct players** head, int counter);
int count_players(struct players** lista_pointer);
struct players* player_with_points(struct players** lista_pointer, int points);
struct players* pointer_player_with_points(struct players** lista_pointer, struct players** head, int points);
struct players* find_player_by_number(struct players** lista_pointer, struct players** head, int number);
struct players* return_player(struct players** lista_pointer, int number);
struct players* change_nickname(struct players* player, char newNick[]);
#endif // !_PLAYER_FUNCTIONS_H_
