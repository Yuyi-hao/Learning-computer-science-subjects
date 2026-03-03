#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct{
    Node *head;
    Node *tail;
    int lenght;
} List;

void list_init(List *list, void (*destroy) (void *data)){
    
}

int main(){
   return 0;
}