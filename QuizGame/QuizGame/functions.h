#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
int is_numbers(char string[]);
int string_to_int(int(*number)(char string[]), char thisString[]);
struct player* new_players(struct players** lista_pointer);
#endif // !_FUNCTIONS_H_