// 1019. Next Greater Node In Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode *reverse_list(struct ListNode *head){
    struct ListNode *curr=head, *prev=NULL, *next=NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int get_size(struct ListNode *head){
    int size=0;
    struct ListNode *temp=head;
    while(temp){
        temp = temp->next;
        size++;
    }
    return size;
}

int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    head = reverse_list(head);
    int size = get_size(head);
    int stack[size], idx=-1;
    int *res = (int *)malloc(sizeof(int)*size);
    int i=size-1;
    for(struct ListNode *temp=head; temp && i > -1; i--, temp=temp->next){
        while(idx > -1 && stack[idx] <= temp->val) idx--;
        if(idx > -1) res[i] = stack[idx];
        else res[i] = 0;
        stack[++idx] = temp->val;
    }
    *returnSize = size;
    head = reverse_list(head);
    return res;
}