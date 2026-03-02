// 1673. Find the Most Competitive Subsequence

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* mostCompetitive(int* nums, int numsSize, int k, int* returnSize) {
    int *ans = (int *)malloc(sizeof(int)*numsSize), idx=-1;
    *returnSize = k;
    for(int i=0; i<numsSize; i++){
        while(idx > -1 && ans[idx] > nums[i] && ( k <= numsSize-i+idx)) idx--;
        ans[++idx] = nums[i];
    }
    return ans;
}