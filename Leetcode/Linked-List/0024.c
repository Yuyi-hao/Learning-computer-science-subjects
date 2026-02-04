// 24. Swap Nodes in Pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode *temp = dummy;
    while(temp && temp->next && temp->next->next){
        struct ListNode *rest_list = temp->next->next->next;
        struct ListNode *a = temp->next, *b = temp->next->next;
        temp->next = b;
        b->next = a;
        a->next = rest_list;
        temp = a;
    }
    head = dummy->next;
    free(dummy);
    return head;
}