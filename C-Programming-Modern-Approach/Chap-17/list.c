#include <stdlib.h>
#include <string.h>

#include "list.h"

void list_init(List *list, void (*destroy) (void *data)){
    // Initialize the list
    list->destroy = destroy;
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return;
}

void list_destroy(List *list){
    // free all nodes memory
    void *data;
    if(list->destroy != NULL){
        while(list_size(list) > 0){
            if(list_rem_next(list, NULL, (void**) &data)==0)
                list->destroy(data);
        }
    }
    memset(list, 0, sizeof(List));
    return;
}
