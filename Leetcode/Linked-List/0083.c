// Remove Duplicates from Sorted List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *temp = head;
    struct ListNode *rem_node = NULL;
    while(temp && temp->next){
        while(temp && temp->next && temp->val == temp->next->val){
            rem_node = temp->next;
            temp->next = temp->next->next;
            free(rem_node);
        }
        temp = temp->next;
    }
    return head;
}