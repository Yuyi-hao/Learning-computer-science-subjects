// 1290. Convert Binary Number in a Linked List to Integer
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int ans=0;
    struct ListNode *temp = head;
    while(temp){
        ans <<= 1;
        ans += temp->val;
        temp = temp->next;
    }
    return ans;
}