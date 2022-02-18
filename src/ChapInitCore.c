#include "gbafe.h"

typedef uint8_t (*ChapterInitFunc) (void*);
extern ChapterInitFunc ChapterInitFuncList[];

void ChapterInitHook(void* E_MAPMAIN){
	extern void MapMain_StartIntroFx(void*); //  0x801550D
	
	ChapterInitFunc* it= ChapterInitFuncList;
	
	while(*it)
		(*it++)(E_MAPMAIN);
	
	// Vanilla
	MapMain_StartIntroFx(E_MAPMAIN);
	return;
}

