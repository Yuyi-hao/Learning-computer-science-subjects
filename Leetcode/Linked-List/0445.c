// 445. Add Two Numbers II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverse_list(struct ListNode *head){
    struct ListNode *temp = head, *prev=NULL, *next=NULL;
    while(temp){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    l1 = reverse_list(l1);
    l2 = reverse_list(l2);
    struct ListNode *a=l1, *b=l2;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = NULL;
    struct ListNode *c = dummy;
    int carry = 0;
    while(a || b){
        int sum = 0;
        if(a && b){
            sum = a->val+b->val+carry;
            a = a->next;
            b = b->next;
        }else if(a){
            sum = a->val+carry;
            a = a->next;
        }else{
            sum = b->val+carry;
            b = b->next;
        }

        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = sum%10;
        carry = sum/10;
        node->next = NULL;
        c->next = node;
        c = node;
    }
    if(carry != 0){
        int sum = carry;
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = sum%10;
        carry = sum/10;
        node->next = NULL;
        c->next = node;
        c = node;
    }
    struct ListNode *res = reverse_list(dummy->next);
    free(dummy);
    l1 = reverse_list(l1);
    l2 = reverse_list(l2);
    return res;
}
