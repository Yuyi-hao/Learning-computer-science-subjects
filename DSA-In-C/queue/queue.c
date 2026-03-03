#include "queue.h"
#include "list.h"

int queue_enqueue(Queue *queue, const void *data){
    return list_insert_next(queue, list_tail(queue), data);
}

int queue_dequeue(Queue *queue, void **data){
    return list_remove_next(queue, NULL, data);
}