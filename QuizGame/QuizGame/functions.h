#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
int is_numbers(char string[]);
int string_to_int(int(*number)(char string[]), char thisString[]);
struct players* new_players(struct players** lista_pointer);
void players_stats(struct players** players_list);
void changeNickname(struct players** players_list);
void deleteOnePlayer(struct players** lista_pointer);
void deleteOnePlayerNode(struct players** lista_pointer, int number);
void resetPoints(struct players** lista_pointer, struct players** head);
void resetPlayerPoints(struct players* players_list);
int standardModeGame(struct players** players_list);
void addNewCategoryByPlayer();
void add_new_question();
void random_question_mode(struct players** players_list);
bool is_category_in_categories(struct categories* lista_pointer, char* newName);
bool catque_wystapily(int* tabCat, int* tabQue, int size, int numberCat, int numberQue);
bool if_question_questioned(int size, int* tab, int number);
void random_question_mode_race(struct players** players_list);
int standardModeGameRace(struct players** players_list);
void changeQuestion();
#endif // !_FUNCTIONS_H_