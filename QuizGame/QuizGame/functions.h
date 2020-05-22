#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
/*
	@param string[] tablica znakow do sprawdzenia czy wprowadzone znaki to liczby
*/
int is_numbers(char string[]);///<Ta funkcja sprawdza czy w wprowadzonej tablicy istnieja same liczby
/*
	@param *number wskŸnik na funkcjê is_numbers
	@param thisString[] tablica znków do zamiany
*/
int string_to_int(int(*number)(char string[]), char thisString[]);///<Ta funkcja zamienia i zwraca liczbê wprowadzon¹ przez tablice znakow
/*
	@param **lista_pointer wskaznik na liste graczy
*/
struct players* new_players(struct players** lista_pointer);///<Ta funkcja dodaje nowych graczy do gry po wprowadzeniu nicku
/*
	@param **lista_pointer wskaznik na liste graczy
*/
void players_stats(struct players** players_list);///<Ta funkcja wyswietla tabele graczy posortowana od najwiekszego wyniku do najmniejszego
/*
	@param **lista_pointer wskaznik na liste graczy
*/
void changeNickname(struct players** players_list);///<Ta funkcja wprowadza mozliwosc zmiany nicku dowolnego istniejacego gracza
/*
	@param **lista_pointer wskaznik na liste graczy
*/
void deleteOnePlayer(struct players** lista_pointer);///<Ta funkcja usowa jednego wybranego gracza z listy 
/*
	@param **lista_pointer wskaznik na liste graczy	
	@param number to index gracza tory ma zostac usuniety
*/
void deleteOnePlayerNode(struct players** lista_pointer, int number);///<Ta funkcja usuwa gracza o podanym numerze
/*
	@param **lista_pointer wskaznik na liste graczy
	@param **head wskaznik na poczatek listy  
*/
void resetPoints(struct players** lista_pointer, struct players** head);///<Ta funkcja ustawia punkty wszystkich graczy na 0
/*
	@param *lista_pointer wskaznik na poczatek listy graczy
*/
void resetPlayerPoints(struct players* players_list);///<Ta funkcja ustawia punkty wszystkich graczy na 0
/*
	@param **lista_pointer wskaznik na liste graczy
*/
int standardModeGame(struct players** players_list);///<ta funkcja to standardowy trub gry zwraca on czy gracz zakonczyl tryb przed rozpoczeciem sesji gry czy przeszedl ten tryb
void addNewCategoryByPlayer();///<Ta funkcja pozwala na dodanie nowej kategorii do quizu
void add_new_question();///<Ta funkcja pozwala na dodanie nowych pytan do quizu
/*
	@param **lista_pointer wskaznik na liste graczy
*/
void random_question_mode(struct players** players_list);///<Ta funkcja to tryb gry oparty na wygenerowaniu losowych pytan z calej bazy danych
/*
	@param *lista_pointer wskaznik na poczatek listy kategorii
	@param *newName nazwa ketegorii
*/
bool is_category_in_categories(struct categories* lista_pointer, char* newName);///<Ta funkcja sprawdza czy podana kategoria juz wystapila czy nie
/*
	@param tabCat wskaznik na tablice int w ktorej zawarte sa kategorie ktore wystapily
	@param tabQue wskaznik na tablice int w ktorej zawarte sa pytania ktore wystapily
	@param size rozmiar tablicy
	@param numberCat numer id kategorii
	@param numberQue numer id pytania 
*/
bool catque_wystapily(int* tabCat, int* tabQue, int size, int numberCat, int numberQue);///<Ta funkcja sprawdza czy podana kategoria i pytanie z tej kategorii wystapilo 
/*
	@param size rozmiar tablicy
	@param tab wskaznik na tablice
	@param number id pytania
*/
bool if_question_questioned(int size, int* tab, int number);///<Ta funkcja sprawdza czy pytanie zostalo juz zadane
/*
	@param **lista_pointer wskaznik na liste graczy
*/
void random_question_mode_race(struct players** players_list);///<Ta funkcja to tryb gry oparty na zasadach wyœcigu trybu losowych pytan calego quizu 
/*
	@param **lista_pointer wskaznik na liste graczy
*/
int standardModeGameRace(struct players** players_list);///<Ta funkcja to tryb gry oparty na wyœcigu trybu standardowego
void changeQuestion();///<Ta funkcja pozwala na zmiane/edycje pytania 
/*
	@param **lista_pointer wskaznik na liste graczy
*/
int standarModeMQue(struct players** players_list);///<Ta funkcja to tryb gry oparty na odpowiadaniu na dowolna ilosc pytan oparty na zasadach trybu standardowego
/*
	@param **lista_pointer wskaznik na liste graczy
*/
int random_question_mode_questions(struct players** players_list);///<Ta funkcja to tryb gry oparty na odpowiadaniu na dowolna ilosc pytan oparty na zasadach trybu losowych pytan
int countAllQuestions();///<Ta funkcja zlicza wszystkie pytania dostepne w bazie pytan
#endif // !_FUNCTIONS_H_