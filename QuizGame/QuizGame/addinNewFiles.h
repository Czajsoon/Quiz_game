#ifndef _ADDINGNEWFILES_H_
#define _ADDINGNEWFILES_H_
/**Ta funkcja zapisuje do pliku nowe kategorie 
	@param lista_pointer wska�nik na list� kategorii
*/
void write_categories(struct categories* lista_pointer);
/**Ta funkcja zapisuje do pliku nowe pytania
	@param categoryName nazwa kategorii
	@param lista_que wska�nik na list� pyta�
*/
void write_new_questions(char* categoryName, struct questions* lista_que);
#endif // !_ADDINGNEWFILES_H_