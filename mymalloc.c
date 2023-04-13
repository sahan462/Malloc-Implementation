#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include "mymalloc.h"


struct node *head = NULL;
struct node *preblock = NULL;
char *ptr = memory;



void* addDataBlock(char *startpoint,size_t size){
	
	if (head == NULL){
		head = (struct node*)(startpoint);
		head->size = size;
		head->free = 0;
		head->nextblock = NULL;
		startpoint = (char*)head;
		preblock = head;		
	}else{
		struct node *block = (struct node*)(startpoint);
		block->size = size;
		block->free = 0;
		block->nextblock = NULL;
		startpoint = (char*)block;
		preblock->nextblock = block;
		preblock = block;
	}
	return startpoint; 
	
}



void* MyMalloc(size_t size){
	
	
	struct node *temp = NULL;
	struct node *Minblock = NULL;
	int  min = 25000;
	
	if(size > 25000 || size <= 0){
		
		return NULL;
		
	}else{
		
		temp = head;
		
		while(1){
			if(temp == NULL){
				if(Minblock == NULL || Minblock->size > &memory[25000] - ptr){
					if(&memory[25000] - ptr >= size+sizeof(struct node) ){
						temp = addDataBlock(ptr,size);
						ptr = (char*)temp + size + sizeof(struct node);
						return temp+sizeof(struct node);
					}else{
						return NULL;
					}
				}else{
					Minblock->free = 0;
					return Minblock+sizeof(struct node);
				}
				break;
			}
			else if(temp->free == 1){
				if (temp->size == size){
					Minblock = temp;
					Minblock->free = 0;
					return Minblock + sizeof(struct node);
					break;
				}else if(temp->size > size){
					if(temp->size-size < min){
						min = temp->size - size;
						Minblock = temp;
					}
				}
			}
			temp = temp->nextblock;
		}
	
	
	}
}

void MyFree(void *pointer){
	
	if((char*)(pointer) >= memory && (char*)(pointer) <= &memory[25000-1]){
		struct node *temp = (struct node*)(pointer);
		temp = temp - sizeof(struct node);
		temp->free = 1;	
		
		temp = head;
		
		while(temp != NULL){
			if(temp->free == 1 && temp->nextblock->free==1){
				temp->size = temp->size + temp->nextblock->size + sizeof(struct node);
				temp->nextblock = temp->nextblock->nextblock; 
				if(temp->nextblock == NULL){
					temp->size = temp->size + &memory[25000 - 1] - ptr + 1;
					ptr = (char*)temp;
				}
			}
			//printf("%d\n", temp->size);
			temp=temp->nextblock;

		}
		

				
	}else{
		printf("Not In Range!");
	}
}


