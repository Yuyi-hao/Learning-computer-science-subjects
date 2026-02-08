// 109. Convert Sorted List to Binary Search Tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if(!head || !(head->next) || !(head->next->next)){
        if(!head){
            return NULL;
        }
        else if(head->next == NULL){
            struct TreeNode *curr_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            curr_node->val = head->val;
            curr_node->left = NULL;
            curr_node->right = NULL;
            return curr_node;
        }
        else{
            struct TreeNode *head_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            struct TreeNode *right_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            head_node->val = head->val;
            head_node->left = NULL;
            head_node->right = right_node;
            right_node->val = head->next->val;
            right_node->left = NULL;
            right_node->right = NULL;
            return head_node;
        }
    }
    struct ListNode *slow = head, *fast = head->next->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct TreeNode *curr_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    curr_node->val = slow->next->val;
    curr_node->right = sortedListToBST(slow->next->next);
    free(slow->next);
    slow->next =  NULL;
    curr_node->left = sortedListToBST(head);
    return curr_node;
}
