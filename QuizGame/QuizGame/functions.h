#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
int is_numbers(char string[]);
int string_to_int(int(*number)(char string[]), char thisString[]);
struct player* new_players(struct players** lista_pointer);
void players_stats(struct players** players_list);
void changeNickname(struct players** players_list);
void deleteOnePlayer(struct players** lista_pointer);
void deleteOnePlayerNode(struct players** lista_pointer, int number);
void resetPoints(struct players** lista_pointer, struct players** head);
int standardModeGame(struct players** players_list);
void addNewCategoryByPlayer();
#endif // !_FUNCTIONS_H_