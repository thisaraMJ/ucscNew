#include<stdio.h>
#include<stdbool.h>

char memory[25000];

struct memBlock
{
	int size;
	bool allocated;
	void *begin;
	struct memBlock *next;
};

void *MyMalloc(int Bytes);

void MyFree(void* ptr);
