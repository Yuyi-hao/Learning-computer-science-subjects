// 138. Copy List with Random Pointer

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	struct Node *temp = head, *curr=head, *next=NULL;
    while(temp){
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->val = temp->val;
        new_node->next = temp->next;
        new_node->random = NULL;
        temp->next = new_node;
        temp = temp->next->next;
    }
    temp = head;
    while(temp){
        if(temp->random){
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }

    struct Node *dummy_node = (struct Node *)malloc(sizeof(struct Node));
    dummy_node->val = INT_MIN;
    dummy_node->next = NULL;
    dummy_node->random = NULL;
    struct Node *prev = dummy_node;
    temp = head;
    while(temp && temp->next){
        prev->next = temp->next;
        temp->next = temp->next->next;
        prev = prev->next;
        temp = temp->next;
    }
    struct Node *res = dummy_node->next;
    free(dummy_node);
    return res;
}