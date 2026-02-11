// 328. Odd Even Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *even=(struct ListNode *)malloc(sizeof(struct ListNode));
    even->next = NULL;
    struct ListNode *temp = even, *curr=head;
    while(curr && curr->next){
        temp->next = curr->next;
        temp = temp->next;
        curr->next = curr->next->next;
        if(curr->next) curr = curr->next;
    }
    if(curr) curr->next = even->next;
    temp->next = NULL;
    free(even);
    return head;
}