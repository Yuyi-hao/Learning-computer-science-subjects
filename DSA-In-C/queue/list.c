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
            if(list_remove_next(list, NULL, (void**) &data)==0)
                list->destroy(data);
        }
    }
    memset(list, 0, sizeof(List));
    return;
}

int list_insert_next(List *list, ListElement *element, const void *data){
    ListElement *new_element = (ListElement *)malloc(sizeof(ListElement));
    if(new_element == NULL){
        return -1;
    }

    new_element->data = (void *)data;
    if(element == NULL){
        if(list_size(list) == 0)
            list->tail = new_element;
        new_element->next = list->head;
        list->head = new_element;
    }
    else{
        if(element->next == NULL)
            list->tail = new_element;
        new_element->next = element->next;
        element->next = new_element;
    }
    list->size++;
    return 0;
}

int list_remove_next(List *list, ListElement *element, void **data){
    ListElement *old_ele;
    if(list_size(list) == 0){
        return -1;
    }
    if(element == NULL){
        *data = list->head->data;
        old_ele = list->head;
        list->head = list->head->next;
        if(list_size(list) == 1){
            list->tail = NULL;
        }
    }
    else{
        if(element->next == NULL){
            return -1;
        }
        *data = element->next->data;
        old_ele = element->next;
        element->next = element->next->next;
        if(element->next == NULL){
            list->tail = element;
        }
    }
    free(old_ele);
    list->size--;
    return 0;

}