// 102. Binary Tree Level Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Assuming the number of element at present will never exceed the capacity

#define CAP 3000
#define push(q, x, front, rear)  q[rear] = (x), rear = (rear + 1) % CAP
#define pop(q, front, rear) (q[front++ % CAP])
#define empty(front, rear)       (front == rear)
#define size(front, rear)        ((rear - front + CAP) % CAP)

#define MAX_SIZE 2000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    // queue
    struct TreeNode *q[CAP];
    int front = 0, rear = 0;

    int **ans = (int **)malloc(sizeof(int *)*MAX_SIZE);
    *returnColumnSizes = (int *)malloc(sizeof(int)*MAX_SIZE);

    int curr_level = 0;
    push(q, root, front, rear);
    
    while(!empty(front, rear)){
        int curr_size = size(front, rear);
        (*returnColumnSizes)[curr_level] = curr_size;

        int *curr_level_node = (int *)malloc(sizeof(int)*curr_size);

        for(int i=0; i<curr_size; i++){
            struct TreeNode *curr_node = pop(q, front, rear);

            curr_level_node[i] = curr_node->val;
            if(curr_node->left) push(q, curr_node->left, front, rear);
            if(curr_node->right) push(q, curr_node->right, front, rear);
        }
        ans[curr_level++] = curr_level_node;
    }
    *returnSize = curr_level;
    return ans; 
}