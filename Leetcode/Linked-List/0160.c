// Intersection of Two Linked Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// think about a+b and b+a the main issue we can't traverse one by one is both could be of different length at the intersection so somehow make it same length the idea comes there a+b == b+a
 struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* a=headA, *b=headB;
    while(a!=b){
        a = a?a->next:headB;
        b = b?b->next:headA;
    }
    return a;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* head1 = headA;
    while(head1){
        struct ListNode* head2 = headB;
        while(head2){
            if(head1 == head2) return head1;
            head2 = head2->next;
        }
        head1 = head1->next;
    }
    return NULL;
}