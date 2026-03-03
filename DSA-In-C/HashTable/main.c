#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DA_INIT_CAP 10

#define da_append(da, item)                                                           \
    do{                                                                               \
        if((da)->count >= (da)->capacity){                                            \
            (da)->capacity = (da)->capacity==0?DA_INIT_CAP:(da)->capacity*2;          \
            (da)->items = realloc((da)->items, (da)->capacity*sizeof(*(da)->items));  \
            assert((da)->items != NULL && "Not enough memory");                       \
        }                                                                             \
        (da)->items[(da)->count++] = (item);                                          \
    }while(0)                                                                         \

typedef struct{
    int *items;
    int count;
    int capacity;
} Da;


int main(){
    Da da = {0};
    for(int i=0; i<20; i++) da_append(&da, i);
    for(int i=0; i<20; i++) printf("%d ", da.items[i]);
    printf("\n");
    printf("Hello, World\n");
    return 0;
}