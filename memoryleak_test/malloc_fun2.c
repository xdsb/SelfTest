#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define malloc(size) malloc_hook(size, __FILE__, __LINE__)

#define free(p) free_hook(p, __FILE__, __LINE__)
 
void *malloc_hook(size_t size, const char *file, int line) {
 
    void *p = malloc(size);
 
    char buff[128] = {0};
    sprintf(buff, "./mem/%p.mem", p);
 
    FILE *fp = fopen(buff, "w");
    fprintf(fp, "[+%s:%d]malloc --> addr:%p size:%lu\n", file, line, p, size);
    fflush(fp);
 
    fclose(fp);
 
    return p;
 
}
 
void free_hook(void *p,  const char *file, int line) {
 
    char buff[128] = {0};
    sprintf(buff, "./mem/%p.mem", p);
 
    if (unlink(buff) < 0) {
        printf("double free: %p\n", p);
        return;
    }
 
    free(p);
 
}
 
#define malloc(size)   malloc_hook(size, __FILE__, __LINE__)
 
#define free(p)    free_hook(p, __FILE__, __LINE__)
 
 
// gcc -o memleak_0 memleak_0.c -g
// addr2line -f -e  memleak_0  -a 0x4006d8
int main() {
 
 
    void *p1 = malloc(10);
    void *p2 = malloc(20);
 
    free(p1);
 
    void *p3 = malloc(30);   // memory leak
    void *p4 = malloc(40);
 
    free(p2);
    free(p4);
    free(p4); // double free
 
    return 0;
 
}
