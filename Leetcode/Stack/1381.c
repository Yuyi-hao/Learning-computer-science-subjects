
// 1381. Design a Stack With Increment Operation

typedef struct {
    int *data;
    int *inc;
    int size;
    int idx;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    CustomStack *stack = (CustomStack *)malloc(sizeof(CustomStack));
    stack->size = maxSize;
    stack->data = (int *)malloc(sizeof(int)*(stack->size));
    stack->inc = (int *)calloc(stack->size, sizeof(int));
    stack->idx = -1;
    return stack; 
}

void customStackPush(CustomStack* obj, int x) {
    if(obj->idx < obj->size-1) obj->data[++(obj->idx)] = x;
    return;
}

int customStackPop(CustomStack* obj) {
    if(obj->idx > -1){
        int val = obj->data[obj->idx];
        int inc = obj->inc[obj->idx];
        obj->inc[obj->idx] = 0;
        obj->idx--;
        if(obj->idx > -1) obj->inc[obj->idx] += inc;
        return val+inc;
    }
    return -1;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    if(obj->idx > -1) obj->inc[(k-1 <= obj->idx)?k-1:obj->idx] += val;
}

void customStackFree(CustomStack* obj) {
    free(obj->data);
    free(obj->inc);
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/