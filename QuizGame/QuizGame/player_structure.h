#ifndef _PLAYER_STRUCTURE_H_
#define _PLAYER_STRUCTURE_H_
struct players {
	char Name[40];
	int points, numberPlayer;
	struct players* pNext;
};
#endif // !_PLAYER_STRUCTURE_H_