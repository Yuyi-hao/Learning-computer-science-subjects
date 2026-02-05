// 86. Partition List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    dummy->val = 101;
    struct ListNode *dummy2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy2->next = NULL;
    dummy2->val = 101;
    struct ListNode *temp=dummy, *b=dummy2;
    while(temp->next){
        if(temp->next->val >= x){
            b->next = temp->next;
            temp->next = temp->next->next;
            b->next->next = NULL;
            b = b->next;
        }else{
            temp = temp->next;
        }
    }
    temp->next = dummy2->next;
    head = dummy->next;
    free(dummy);
    free(dummy2);
    return head;
}