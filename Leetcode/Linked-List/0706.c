// 706. Design HashMap

typedef struct Node{
    int key;
    int val;
    struct Node *next;
} Node;


typedef struct {
    Node **hash;
    int size; 
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap *hashset = (MyHashMap *)malloc(sizeof(MyHashMap));
    if(!hashset) return NULL;
    hashset->hash = (Node **)calloc(1001, sizeof(Node *));
    hashset->size = 1001;
    return hashset;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    node->val = value;

    int keyIdx = (key%(obj->size));
    if((obj->hash)[keyIdx] == NULL){
        obj->hash[keyIdx] = node;
    }else{
        Node *temp = obj->hash[keyIdx];
        while(temp->next){
            if(temp->key == key){
                temp->val = value;
                free(node);
                return;
            }
            temp = temp->next;
        }
        if(temp->key == key){
            temp->val = value;
            free(node);
            return;
        }
        temp->next = node;
    }
    return;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int keyIdx = (key%(obj->size));
    if((obj->hash)[keyIdx] == NULL){
        return -1;
    }else{
        Node *temp = obj->hash[keyIdx];
        while(temp){
            if(temp->key == key) return temp->val;
            temp = temp->next;
        }
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int keyIdx = (key%(obj->size));
    if((obj->hash)[keyIdx] == NULL){
        return;
    }else{
        Node *temp = obj->hash[keyIdx];
        if(temp->key == key){
            if(temp->next){
                obj->hash[keyIdx] = temp->next;
            }else{
                obj->hash[keyIdx] = NULL;
            }
            free(temp);
            return;
        }else{
            while(temp->next){
                if(temp->next->key == key) break;
                temp = temp->next;
            }
            if(temp->next && temp->next->key == key){
                Node *old_node = temp->next;
                temp->next = temp->next->next;
                free(old_node);
            }
        }
    }
    return;
}

void myHashMapFree(MyHashMap* obj) {
    for(int i=0; i < obj->size; i++){
        Node *curr = obj->hash[i];
        Node *next;
        while(curr){
            next = curr->next;
            free(curr);
            curr = next;
        }
    }
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/