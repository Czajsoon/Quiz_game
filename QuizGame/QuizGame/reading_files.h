#ifndef _READING_FILES_H_
#define _READING_FILES_H_
/**Ta funkcja czyta z pliku tekstowego nazwy kategorii i dodaje je do listy kategorii
	@param lista_pointer wskaznik na liste kategorii
*/
void adding_categories_to_list(struct categories** lista_pointer);
/**Ta funkcja czyta z pliku tekstowego tresci pytan i dodaje je do listy pytan
	@param lista_pointer wskaznik na liste kategorii
	@param name nazwa kategorii
*/
void adding_questions_to_list(struct questions** lista_pointer, char* name);
#endif // !_READING_FILES_H_