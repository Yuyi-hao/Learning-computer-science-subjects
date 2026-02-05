// 82. Remove Duplicates from Sorted List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode *temp = dummy;
    while(temp && temp->next && temp->next->next){
        if(temp->next->val == temp->next->next->val){
            int curr = temp->next->val;
            struct ListNode *curr_node = temp;
            while(curr_node->next && curr_node->next->val == curr){
                struct ListNode *old_node = curr_node->next;
                curr_node->next = old_node->next;
                free(old_node);
            }
        }else{
            temp = temp->next;
        }
    }
    head = dummy->next;
    free(dummy);
    return head;
}