// 146. LRU Cache

#define MAP_SIZE 10001

typedef struct Node{
    int key;
    int val;
    struct Node *next;
    struct Node *prev;
} Node;


typedef struct DLL{
    struct Node *head;
    struct Node *tail;
    int size;
}DLL;

typedef struct LRUCache{
    struct Node **map;
    struct DLL *dll;
    int capacity;
} LRUCache;

void deleteNode(struct DLL *dll, struct Node *node){
    if(!node) return;
    if(node == dll->head){
        dll->head = dll->head->next;
        if(dll->head) dll->head->prev = NULL;
        else dll->tail = NULL;
    }
    else if(node == dll->tail){
        dll->tail = dll->tail->prev;
        if(dll->tail) dll->tail->next = NULL;
        else dll->head = NULL;

    }
    else{
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    free(node);
    dll->size -= 1;
    return;
}

void insertNode(struct DLL *dll, struct Node *node){
    if(!node) return;
    if(dll->tail){
        dll->tail->next = node;
        node->prev = dll->tail;
        dll->tail = dll->tail->next;
    }
    else{
        dll->head = node;
        dll->tail = node;
    }
    node->next = NULL;
    dll->size += 1;
    return;
}

LRUCache* lRUCacheCreate(int capacity) {
    struct LRUCache *cache = (struct LRUCache*)malloc(sizeof(struct LRUCache));
    cache->capacity = capacity;
    cache->dll = (struct DLL *)malloc(sizeof(struct DLL));
    cache->dll->head = NULL;
    cache->dll->tail = NULL;
    cache->dll->size = 0;
    cache->map = (struct Node **)calloc(MAP_SIZE, sizeof(struct Node *));
    return cache;
}

void lRUCachePut(LRUCache* obj, int key, int value);

int lRUCacheGet(LRUCache* obj, int key) {
    if(obj->map[key] != NULL){
        int val = obj->map[key]->val;
        lRUCachePut(obj, key, val);
        return val;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if(obj->map[key] != NULL){
        deleteNode(obj->dll, obj->map[key]);
        obj->map[key] = NULL;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->key = key;
    new_node->val = value;
    insertNode(obj->dll, new_node);
    obj->map[key] = new_node;
    
    if(obj->capacity < obj->dll->size){
        obj->map[obj->dll->head->key] = NULL;
        deleteNode(obj->dll, obj->dll->head);
    }
    return;
}

void lRUCacheFree(LRUCache* obj) {
    struct Node *temp = obj->dll->head, *next;
    while(temp){
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(obj->dll);
    free(obj->map);
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/

// important test case 
// Input
// ["LRUCache","get","put","get","put","put","get","get"]
// [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
// Output
// [null,-1,null,-1,null,null,2,6]
// Expected
// [null,-1,null,-1,null,null,2,6]