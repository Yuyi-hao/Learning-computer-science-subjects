// 817. Linked List Components

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MAX_N 10000
int numComponents(struct ListNode* head, int* nums, int numsSize) {
    int hash[MAX_N] = {0};
    for(int i=0; i<numsSize; i++){
        hash[nums[i]] = 1;
    }
    struct ListNode *temp = head;
    int components = numsSize;
    while(temp->next){
        if(hash[temp->val] && hash[temp->next->val]) components--;
        temp = temp->next;
    }
    return components;
}