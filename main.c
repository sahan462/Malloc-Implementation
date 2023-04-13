#include<stdio.h>
#include "mymalloc.h"



int main(void){
	
    void *ptr1 = MyMalloc(3000);
    printf("ptr1: %p\n", ptr1);
    void *ptr2 = MyMalloc(2000);
    printf("ptr2: %p\n", ptr2);
    void *ptr3 = MyMalloc(1000);
    printf("ptr3: %p\n", ptr3);
    MyFree(ptr1);
    void *ptr4 = MyMalloc(500);
    printf("ptr4: %p\n", ptr4);
    void *ptr5 = MyMalloc(2000);
    printf("ptr5: %p\n", ptr5);
    
    return 0;

}


