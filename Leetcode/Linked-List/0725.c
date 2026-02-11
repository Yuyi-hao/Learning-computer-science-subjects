// 725. Split Linked List in Parts
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
int getSize(struct ListNode *head){
    struct ListNode *temp;
    int size = 0;
    for(temp=head; temp; temp=temp->next){
        size++;
    }
    return size;
}
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    int size = getSize(head);
    int fix = size/k;
    int rem = size%k;
    *returnSize = k;
    struct ListNode **res = (struct ListNode **)calloc(k, sizeof(struct ListNode *));
    struct ListNode *temp = head, *next_list=NULL;
    for(int i=0; i<k; i++){
        res[i] = temp;
        int curr = fix + (rem > 0 ? 1 : 0);
        if(curr > fix) rem--;
        while(temp && curr>1){
            temp = temp->next;
            curr--;
        }
        if(temp){
            next_list = temp->next;
            temp->next = NULL;
            temp = next_list;
        }
    }
    return res;
}