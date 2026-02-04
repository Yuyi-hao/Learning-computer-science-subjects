// 2. Add Two Numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ans=NULL, *left=l1, *right=l2, *curr=NULL;
    int carry = 0;
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = (left->val+right->val)%10;
    node->next = NULL;
    carry = (left->val+right->val)/10;
    ans = node;
    curr = node;
    left = left->next;
    right = right->next;
    while(left && right){
        int sum = (left->val+right->val+carry);
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = sum%10;
        node->next = NULL;
        carry = sum/10;
        curr->next = node;
        curr = curr->next;
        left = left->next;
        right = right->next;
    }
    while(left){
        int sum = (left->val+carry);
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = sum%10;
        node->next = NULL;
        carry = sum/10;
        curr->next = node;
        curr = curr->next;
        left = left->next;
    }
    while(right){
        int sum = (right->val+carry);
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = sum%10;
        node->next = NULL;
        carry = sum/10;
        curr->next = node;
        curr = curr->next;
        right = right->next;

    }
    if(carry){
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;
        curr->next = node;
    }
    return ans;
}