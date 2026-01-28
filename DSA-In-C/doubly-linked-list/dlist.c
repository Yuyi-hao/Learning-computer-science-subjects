#include <stdlib.h>
#include <string.h>

#include "dlist.h"

void dlist_init(DList *list, void (*destroy)(void *data)){
    // Initialize the list
    list->destroy = destroy;
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return;
}

void dlist_destroy(DList *list){
    // free all nodes memory
    void *data;
    if(list->destroy != NULL) return; 
    while(dlist_size(list) > 0){
        if(dlist_remove(list, dlist_tail(list), (void **)&data) == 0){
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(DList));
    return;
}

int dlist_insert_next(DList *list, DListElement *element, const void *data){
    if(element == NULL && dlist_size(list) != 0) return -1;
    DListElement *new_element = (DListElement *)malloc(sizeof(DListElement));
    if(new_element == NULL){
        return -1;
    }

    new_element->data = (void *)data;
    if(dlist_size(list) == 0){
        list->head = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = new_element;
    }
    else{
        new_element->next = element->next;
        new_element->prev = element;

        if(element->next == NULL){
            list->tail = new_element;
        }
        else{
            element->next->prev = new_element;
        }
        element->next = new_element;
    }
    list->size++;
    return 0;
}

int dlist_insert_prev(DList *list, DListElement *element, const void *data){
    if(element == NULL && dlist_size(list) != 0) return -1;
    DListElement *new_element = (DListElement *)malloc(sizeof(DListElement));
    if(new_element == NULL){
        return -1;
    }

    new_element->data = (void *)data;
    if(dlist_size(list) == 0){
        list->head = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = new_element;
    }
    else{
        new_element->next = element;
        new_element->prev = element->prev;

        if(element->prev == NULL){
            list->head = new_element;
        }
        else{
            element->prev->next = new_element;
        }
        element->prev = new_element;
    }
    list->size++;
    return 0;
}

int dlist_remove(DList *list, DListElement *element, void **data){
    if(element==NULL || dlist_size(list) == 0) return -1;
    
    *data = element->data;
    if(element == list->head){
        list->head = element->next;
        if(list->head == NULL)
            list->tail = NULL;
        else
            element->next->prev = NULL;
    }
    else{
        element->prev->next = element->next;
        if(element->next == NULL)
            list->tail = element->prev;
        else
            element->next->prev = element->prev;
    }
    free(element);
    list->size--;
    return 0;
}