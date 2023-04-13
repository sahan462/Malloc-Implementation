#ifndef MALLOC_H_   
#define MALLOC_H_

char memory[25000];

struct node{
	size_t size;
	int free;
	struct node *nextblock;
};



void* MyMalloc(size_t size);
void MyFree(void *pointer);
void* addDataBlock(char *startpoint,size_t size);

#endif
