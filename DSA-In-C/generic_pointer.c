#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swap(void *a, void *b, int size){
    void *tmp;
    if((tmp = malloc(size)) == NULL) return -1;

    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
    free(tmp);
    return 0;
}

int main(){
    int a=10, b=20;
    printf("Before Swap: %d %d\n", a, b);
    swap(&a, &b, sizeof(a));
    printf("After Swap: %d %d\n", a, b);
}