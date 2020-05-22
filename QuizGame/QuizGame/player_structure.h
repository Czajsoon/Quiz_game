#ifndef _PLAYER_STRUCTURE_H_
#define _PLAYER_STRUCTURE_H_
struct players {
	char Name[40];///<Nazwa gracza
	int points, numberPlayer;///<Punkty i numer gracza
	struct players* pNext;
};
#endif // !_PLAYER_STRUCTURE_H_