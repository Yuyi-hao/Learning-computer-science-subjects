#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

typedef struct DListElement_{
    void *data;
    struct DListElement_ *next;
    struct DListElement_ *prev;
} DListElement;

typedef struct DList_{
    int  size;
    int  (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    DListElement *head;
    DListElement *tail;
} DList;

void dlist_init(DList *list, void (*destroy)(void *data));

void dlist_destroy(DList *list);

int dlist_insert_next(DList *list, DListElement *element, const void *data);
int dlist_insert_prev(DList *list, DListElement *element, const void *data);

int dlist_remove(DList *list, DListElement *element, void **data);

#define dlist_size(list) ((list)->size)

#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)

#define dlist_is_head(element) ((element)->prev == NULL ? 1: 0)

#define dlist_is_tail(element) ((element)->next == NULL ? 1: 0)

#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->prev)

#endif