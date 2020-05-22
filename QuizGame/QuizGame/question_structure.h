#ifndef _QUESTION_STRUCTURE_H_
#define _QUESTION_STRUCTURE_H_
struct questions {
	char sentense[256];///<Tresc pytania 
	char A[256];///<tresc a
	char B[256];///<tresc b
	char C[256];///<tresc c
	char D[256];///<tresc d
	char coorectAnswear[256];///<poprawna odpowiedz
	int id;///<
	struct questions* pNext;
};
#endif // !_QUESTION_STRUCTURE_H_