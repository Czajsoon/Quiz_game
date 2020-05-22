#ifndef _CATEGORY_STRUCTURE_H_
#define _CATEGORY_STRUCTURE_H_
struct categories {
	char NameCategory[256];///<Nazwa kategorii
	int id;///<numer id kategorii
	struct categories* pNext;
};
#endif // !_CATEGORY_STRUCTURE_H_