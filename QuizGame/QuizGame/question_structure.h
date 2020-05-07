#ifndef _QUESTION_STRUCTURE_H_
#define _QUESTION_STRUCTURE_H_
struct questions {
	char sentense[256];
	char A[256];
	char B[256];
	char C[256];
	char D[256];
	char coorectAnswear[256];
	int id;
	struct questions* pNext;
};
#endif // !_QUESTION_STRUCTURE_H_