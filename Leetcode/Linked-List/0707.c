// 707. Design Linked List

typedef struct Node{
    int val;
    struct Node *next;
} Node;

typedef struct {
    int size;
    Node *head;
    Node *tail;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    if(list == NULL) return list;    
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(!obj || (obj->size)-1 < index || index < 0) return -1;
    struct Node *temp = obj->head;
    while(index && temp){
        temp = temp->next;
        index--;
    }
    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL) return;
    node->val = val;
    node->next = obj->head;
    if(obj->tail == NULL) obj->tail = node;
    obj->head = node;
    obj->size++;
    return;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL) return;
    node->val = val;
    node->next = NULL;
    if(obj->tail) obj->tail->next = node;
    if(obj->head == NULL) obj->head = node;
    obj->tail = node;
    obj->size++;
    return;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index == 0){
        myLinkedListAddAtHead(obj, val);
        return;
    } else if(index == obj->size){
        myLinkedListAddAtTail(obj, val);
        return;
    }else if(index < 0 || index > obj->size){
        return;
    }
    Node *temp = obj->head;
    for(int i=0; i<index-1; i++){
        temp = temp->next;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(!new_node) return;
    new_node->val = val;
    new_node->next = temp->next;
    temp->next = new_node;
    obj->size++;
    return;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size) return;
    if(index == 0){
        Node *old_node = obj->head;
        obj->head = obj->head->next;
        if(obj->size <= 1){
            obj->tail = obj->head;
        }
        obj->size--;
        free(old_node);
        return;
    }
    Node *temp = obj->head;
    for(int i=0; i<index-1; i++){
        temp = temp->next;
    }
    Node *old_node = temp->next;
    temp->next = old_node->next;
    if(old_node == obj->tail)
        obj->tail = temp;
    obj->size--;
    free(old_node);
    return;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node *curr = obj->head;
    while(curr){
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/