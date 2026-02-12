// 1171. Remove Zero Sum Consecutive Nodes from Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    if(!head) return head;
    struct ListNode *curr = head;
    int prev_sum=0;
    while(curr != NULL){
        prev_sum += curr->val;
        if(prev_sum == 0){
            head = curr->next;
            return removeZeroSumSublists(head);
        }
        curr = curr->next;
    }
    head->next = removeZeroSumSublists(head->next);
    return head;
}


/*
Better Approach: Use hashmap to map the sum with nodes  it would be o(n) time complexity 
*/