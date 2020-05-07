#ifndef _PLAYER_FUNCTIONS_H_
#define _PLAYER_FUNCTIONS_H_
struct players* create_list_players(struct players** lista_pointer, char name[]);
void create_and_add_list_players(struct players** lista_pointer, char name[], struct players** head);
void print_players(struct players* lista_pointer, struct players* head);
void delete_cycle_players(struct players** lista_pointer, struct players** head);
void delete_list_of_players(struct players** lista_pointer, int data);
#endif // !_PLAYER_FUNCTIONS_H_
