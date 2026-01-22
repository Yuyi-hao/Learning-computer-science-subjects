#include <stdlib.h>
#include "list.h"
#include "frame.h"

int alloc_frame(List *frames){
    int frame_number, *data;
    if(list_size(frames) == 0){
        return -1;
    }
    if(list_remove_next(frames, NULL, (void **)&data) != 0){
        return -1;
    }
    frame_number = *data;
    free(data);
    return frame_number;
}

int free_frame(List *frames, int frame_number){
    int *data;
    data = (int *)malloc(sizeof(int));
    if(data == NULL) return -1;
    *data = frame_number;
    if(list_insert_next(frames, NULL, data) != 0){
        return -1;
    }
    return 0;
}