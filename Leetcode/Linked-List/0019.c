// 19. Remove Nth Node From End of List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getLength(struct ListNode *head){
    int size=0;
    while(head){
        head = head->next;
        size++;
    }
    return size;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int size = getLength(head);
    int k = size-n;
    if(k==0){
        struct ListNode *old_node = head;
        head = head->next;
        free(old_node);
        return head;
    }
    struct ListNode *temp = head;
    while(k>1 && temp){
        temp = temp->next;
        k--;
    }
    struct ListNode *old_node = temp->next;
    temp->next = old_node->next;
    free(old_node);
    return head;
}