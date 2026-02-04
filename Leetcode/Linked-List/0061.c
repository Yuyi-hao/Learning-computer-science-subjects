// 61. Rotate List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getLength(struct ListNode *head){
    int size =0;
    while(head){
        size++;
        head = head->next;
    }
    return size;
}

struct ListNode *getTail(struct ListNode *head){
    struct ListNode *temp = head;
    while(temp && temp->next){
        temp = temp->next;
    }
    return temp;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head) return head;
    int size = getLength(head);
    k = k%size;
    if(k==0 || size<2) return head;
    struct ListNode *temp = head;
    struct ListNode *tail = getTail(head);
    int n = size-k;
    while(n>1){
        temp = temp->next;
        n--;
    }
    struct ListNode *rest = temp->next;
    tail->next = head;
    head = rest;
    temp->next = NULL;
    return head;
}