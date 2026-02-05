// 92. Reverse Linked List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reversed_list(struct ListNode *leftPtr, struct ListNode *rest_list){
    struct ListNode *curr = leftPtr, *prevPtr = rest_list, *next=NULL;
    while(curr){
        next = curr->next;
        curr->next = prevPtr;
        prevPtr = curr;
        curr = next;
    }
    return prevPtr;
}
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(left == right) return head;
    int count = right-left+1;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 501;
    dummy->next = head;
    struct ListNode *second_half = NULL, *left_node = dummy;
    while(left>1){
        left_node = left_node->next;
        left--;
    }
    struct ListNode *right_node = left_node;
    while(count > 0){
        right_node = right_node->next;
        count--;
    }
    struct ListNode *rest_list = right_node->next;
    right_node->next = NULL;
    left_node->next = reversed_list(left_node->next, rest_list);
    head = dummy->next;
    free(dummy);
    (dummy);
    return head;
}