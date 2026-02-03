// 705. Design HashSet

typedef struct Node{
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node **hash;
    int size;    
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet *hashset = (MyHashSet *)malloc(sizeof(MyHashSet));
    if(!hashset) return NULL;
    hashset->hash = (Node **)calloc(1001, sizeof(Node *));
    hashset->size = 1001;
    return hashset;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = key;
    node->next = NULL;
    int keyIdx = (key%(obj->size));
    if((obj->hash)[keyIdx] == NULL){
        obj->hash[keyIdx] = node;
    }else{
        Node *temp = obj->hash[keyIdx];
        while(temp->next){
            if(temp->val == key){
                free(node);
                return;
            }
            temp = temp->next;
        }
        if(temp->val == key){
                free(node);
                return;
        }
        temp->next = node;
    }
    return;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int keyIdx = (key%(obj->size));
    if((obj->hash)[keyIdx] == NULL){
        return;
    }else{
        Node *temp = obj->hash[keyIdx];
        if(temp->val == key){
            if(temp->next){
                obj->hash[keyIdx] = temp->next;
            }else{
                obj->hash[keyIdx] = NULL;
            }
            free(temp);
            return;
        }else{
            while(temp->next){
                if(temp->next->val == key) break;
                temp = temp->next;
            }
            if(temp->next && temp->next->val == key){
                Node *old_node = temp->next;
                temp->next = temp->next->next;
                free(old_node);
            }
        }
    }
    return;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int keyIdx = (key%(obj->size));
    if((obj->hash)[keyIdx] == NULL){
        return false;
    }else{
        Node *temp = obj->hash[keyIdx];
        while(temp){
            if(temp->val == key) return true;
            temp = temp->next;
        }
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
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
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/