// 901. Online Stock Span

#define MAX_CALLS 10001

typedef struct Node{
    int price;
    int span;
}Node;

typedef struct {
    struct Node **stack;
    int idx;
    int size;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner *obj = (StockSpanner *)malloc(sizeof(StockSpanner));
    obj->size = MAX_CALLS;
    obj->idx = -1;
    obj->stack = (struct Node **)malloc(sizeof(struct Node*)*obj->size);
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span=1;
    while(obj->idx > -1 && obj->stack[obj->idx]->price <= price){
        span += obj->stack[obj->idx]->span;
        obj->idx--;
    }
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->price = price;
    node->span = span;
    obj->stack[++(obj->idx)] = node;
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    for(int i=0; i<=obj->idx; i++){
        free(obj->stack[i]);
    }
    free(obj);
    return;
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/