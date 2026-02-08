// 114. Flatten Binary Tree to Linked List

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if(!root || (!(root->left) && !(root->right))) return;
    struct TreeNode *left_list = root->left;
    flatten(root->left);
    struct TreeNode *right_list = root->right;
    flatten(root->right);
    struct TreeNode *temp = left_list;
    while(temp && temp->right){
        temp = temp->right;
    }
    if(temp) temp->right = right_list;
    if(!left_list){
        root->right = right_list;
    }else{
        root->right = left_list;
    }
    root->left = NULL;
    return;   
}