// 3507. Minimum Pair Removal to Sort Array I

typedef struct Node{
    int val;
    struct Node *next; 
} Node;

Node *makeList(int *nums, int numsSize){
    Node *head;
    head = (Node *)malloc(sizeof(Node));
    head->val = nums[0];
    head->next = NULL;
    Node *temp = head;
    for(int i=1; i<numsSize; i++){
        Node *node = (Node *)malloc(sizeof(Node));
        node->val = nums[i];
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
    }
    return head;
}

void destroyList(Node *head){
    Node *temp = head, *next=NULL;
    while(temp){
        next = temp->next;
        free(temp);
        temp = next;
    }
    return;
}

bool isSorted(Node *head){
    while(head && head->next){
        if(head->val > head->next->val) return false;
        head = head->next;
    }
    return true;
}

int minimumPairRemoval(int* nums, int numsSize) {
    Node *ll = makeList(nums, numsSize);
    int operations = 0;
    while(!isSorted(ll)){
        Node *temp=ll, *minPtr=NULL;
        int currMin = INT_MAX;
        while(temp && temp->next){
            if((temp->val + (temp->next)->val) < currMin){
                minPtr = temp;
                currMin = temp->val + (temp->next)->val;
            }
            temp = temp->next;
        }
        if(!minPtr) break;
        Node *old_node = minPtr->next;
        minPtr->val += minPtr->next->val;
        minPtr->next = old_node->next;
        free(old_node);
        operations++;
    }
    destroyList(ll);
    return operations;
}