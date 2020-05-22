#ifndef _ADDINGNEWFILES_H_
#define _ADDINGNEWFILES_H_
void write_categories(struct categories* lista_pointer);///< Ta funkcja zapisuje do pliku nowe kategorie 
/*
@param lista_pointer wskaŸnik na listê kategorii
*/
void write_new_questions(char* categoryName, struct questions* lista_que);///< Ta funkcja zapisuje do pliku nowe pytania
/*
@param lista_que wskaŸnik na listê pytañ
*/
#endif // !_ADDINGNEWFILES_H_