#include"mymalloc.h"
#include<stdio.h>

int main(){
	
	int *p = (int*)MyMalloc(100*sizeof(int));
	char *q = (char*)MyMalloc(250*sizeof(char));
	int *r = (int*)MyMalloc(1000*sizeof(int));
	MyFree(p);
	char *w=(char*)MyMalloc(700);
	MyFree(r);
	int *k = (int*)MyMalloc(1000*sizeof(int));
	MyFree(w);
	MyFree(k);
	
	
	printf("successfull!");
}
