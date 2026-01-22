#include <stdio.h>
#include "list.h"
#include "frame.h"

void destroy(void *data){
    free(data);
}

int main(){
    List frames;
    list_init(&frames, destroy);
    for(int i=0; i<10; i+=2){
        free_frame(&frames, i);
    }
    ListElement *temp;
    for(temp = frames.head; temp && temp->next; temp=temp->next){
        printf("%d -> ", *(int*)(temp->data));
    }
    if(temp){
        printf("%d\n", *(int*)(temp->data));
    }
    alloc_frame(&frames);
    alloc_frame(&frames);
    for(temp = frames.head; temp && temp->next; temp=temp->next){
        printf("%d -> ", *(int*)(temp->data));
    }
    if(temp){
        printf("%d\n", *(int*)(temp->data));
    }
    return 0;
}