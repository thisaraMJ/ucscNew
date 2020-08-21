#include <stdio.h>
#include<stdbool.h>
#include "mymalloc.h"

struct memBlock *freeSpace = (void*)memory;

void *MyMalloc(int Bytes){
	

	if(!freeSpace->size){
		freeSpace->size = 24000;
	    freeSpace->allocated = false;
	    freeSpace->begin = (void*)memory+1000;
	    freeSpace->next = NULL;
		printf("1st memory block initialized\n");
		
	}
	
	struct memBlock* cptr = freeSpace;
	struct memBlock* preptr = freeSpace;
	while(((cptr->size < Bytes)||(cptr->allocated == true))&&(cptr->next != NULL)){
		preptr = cptr;
		cptr = cptr->next;	
	}
	//printf("whileou\n");
	if(cptr->size == Bytes){
	//	printf("exctfittngIN\n");
		cptr->allocated = true;
		cptr->begin = preptr->begin+(preptr->size);
		printf("Exact fitting block allocated\n");
		return ((void*)(cptr->begin));
	}
	
	else if((cptr->size)>(Bytes)){
	//	printf("largeFitIN\n");
		struct memBlock *new = (void*)(cptr+sizeof(struct memBlock));
		new->size = (cptr->size)-Bytes;
		new->allocated = false;
		new->next = cptr->next;
		new->begin = cptr->begin+Bytes;
		cptr->size = Bytes; 
		cptr->allocated = true;
		cptr->next = new;
		printf("Block allocated with a split\n");
		return ((void*)(cptr->begin));
	}
	
	else{
		//printf("menFullIN\n");
		//printf("Sorry. Memory is full\n");
		return NULL;
	}
	
}

void MyFree(void* ptr){
	struct memBlock *preptr;     
	struct memBlock* cptr = (void*)memory;
	
	if((void*)(memory+1000) <= ptr){
		if(ptr<=(void*)(memory+25000)){
			while(cptr->begin != ptr ){
			preptr = cptr;
			cptr = cptr->next;
		    } 
		    
		cptr->allocated = false;
		
	    if(preptr->allocated == false){
			
			preptr->size += (cptr->size);
			preptr->next = cptr->next;
			cptr = preptr;
			printf("successfully merge free momories\n");
					
		}
		//
		if(cptr->next != NULL){	
	
			if(cptr->next->allocated == false){
				
				cptr->size += (cptr->next->size);
			    cptr->next = cptr->next->next;
			    printf("successfully merge free momories\n");
			}	
		}
	
	}
	printf("Successfully free the allocated memory!\n");
	}
	else
	    printf("Invalid pointer\n");
}
