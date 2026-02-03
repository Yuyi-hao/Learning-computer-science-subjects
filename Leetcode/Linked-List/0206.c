/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head) return NULL;
    struct ListNode *prev = NULL, *rem_list, *curr=head;
    while(curr){
        rem_list = curr->next;
        curr->next = prev;
        prev = curr;
        curr = rem_list;
    }
    return prev;
}