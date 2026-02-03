// Remove Linked List Elements

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *temp;
    struct ListNode *old_node;
    while(head && head->val == val){
        old_node = head;
        head = head->next;
        free(old_node);
    }
    temp = head;
    while(temp && temp->next){
        if(temp->next->val == val){
            old_node = temp->next;
            temp->next = temp->next->next;
            free(old_node);
        }else{
            temp = temp->next;
        }
    }
    return head;
}