#include <stdio.h>
#include <stdbool.h>

#define queue_push(queue, front, rear, capacity, data) \
        do{ \
            if(!is_full(front, rear, capacity)){ \
                if(front == -1){ \
                    rear = 0; \
                    front++; \
                } \
                queue[rear] = data; \
                rear = (rear+1)%capacity; \
            } \
        } while(0)
        
#define queue_pop(queue, front, rear, capacity, data) \
        do{ \
            if(!(front == -1)){ \
                *data = queue[front];\
                front = (front+1)%capacity; \
                if(front == rear){ \
                    front = -1; \
                    rear = -1; \
                } \
            } \
        } while(0)

int queue_size(int front, int rear, int capacity){
    if(front == -1) return 0;
    if(rear >= front) return rear-front+1;
    return capacity-front+rear+1;
}

bool is_full(int front, int rear, int capacity){
    return queue_size(front, rear, capacity) >= capacity;
}


int main(){
    int capacity=10;
    int queue[10], front=-1, rear=-1;
    for(int i=0; i<30; i++){
        int curr_size = queue_size(front, rear, capacity);
        if( curr_size == capacity){
            int curr;
            queue_pop(queue, front, rear, capacity, &curr);
            printf("%d ", curr);
        }
        queue_push(queue, front, rear, capacity, i);
    }
    printf("\n");
    return 0;
}