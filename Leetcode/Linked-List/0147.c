// 147. Insertion Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// IMPORTANT APPROACH
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *lastSorted = head;
    struct ListNode *curr = head->next;

    while (curr) {
        if (lastSorted->val <= curr->val) {
            lastSorted = lastSorted->next;
        } else {
            lastSorted->next = curr->next;
            struct ListNode *prev = dummy;
            while (prev->next->val < curr->val) {
                prev = prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;
        }
        curr = lastSorted->next;
    }
    head = dummy->next;
    free(dummy);
    return head;
}

/*
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    for(struct ListNode *curr = head; curr;){
        struct ListNode *c_node = curr;
        curr = curr->next;
        struct ListNode *temp = dummy;
        while(temp && temp->next && temp->next->val < c_node->val){
            temp = temp->next;
        }
        c_node->next = temp->next;
        temp->next = c_node;
    }
    head = dummy->next;
    free(dummy);
    return head;
}
*/