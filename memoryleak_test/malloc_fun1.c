#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int enable_malloc_hook = 1;

extern void *__libc_malloc(size_t size);

int enable_free_hook = 1;
extern void *__libc_free(void *p);

void *malloc(size_t size){


    if(enable_malloc_hook){
       enable_malloc_hook = 0;

       void *p = __libc_malloc(size);
       void *caller = __builtin_return_address(0);

       char buff[128] = {0};
       sprintf(buff,"./mem/%p.mem", p);

       FILE *fp = fopen(buff,"w");
       fprintf(fp,"[+%p]malloc --> addr:%p size:%lu\n", caller, p, size);
       fflush(fp);

       enable_malloc_hook = 1;
       return p;   
    }

    else
    {
       return __libc_malloc(size);
    }

    return NULL;
}

//void free(void *p){
//
//    if(enable_free_hook){
//       enable_free_hook = 0;
//       char buff[128] = {0};
//       sprintf(buff,"./mem/%p.mem",p);
//    
//       if(unlink(buff) < 0){
//        printf("double free:%p,,line no=%d\n",p,__LINE__);
//       }
//
//       __libc_free(p);
//
//       enable_free_hook = 1;
//    }
//    else{
//      __libc_free(p);
//    }
////}

int main(){

	printf("Hello world!\n");
	void *p1 = malloc(10);
//	void *p2 = malloc(20);

//	printf("the address of p1 is %p\n",p1);
//	printf("the address of p2 is %p\n",p2);

	free(p1);

//	void *p3 = malloc(30);
//	void *p4 = malloc(40);

	//free(p2);
	//free(p4);

	return 0;
}
