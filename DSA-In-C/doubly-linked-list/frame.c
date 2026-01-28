#include <stdlib.h>
#include "dlist.h"
#include "frame.h"

int alloc_frame(DList *frames){
    int frame_number, *data;
    if(dlist_size(frames) == 0){
        return -1;
    }
    if(dlist_remove(frames, dlist_head(frames), (void **)&data) != 0){
        return -1;
    }
    frame_number = *data;
    free(data);
    return frame_number;
}

int free_frame(DList *frames, int frame_number){
    int *data;
    data = (int *)malloc(sizeof(int));
    if(data == NULL) return -1;
    *data = frame_number;
    if(dlist_insert_prev(frames, dlist_head(frames), data) != 0){
        return -1;
    }
    return 0;
}