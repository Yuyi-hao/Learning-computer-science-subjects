// 503. Next Greater Element II

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int *res = (int *)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    int stack[numsSize+1], idx=-1;
    for(int i=numsSize-1; i>-1; i--){
        while(idx > -1 && stack[idx] <= nums[i]) idx--;
        stack[++idx] = nums[i];
    }
    for(int i=numsSize-1; i>-1; i--){
        while(idx > -1 && stack[idx] <= nums[i]) idx--;
        if(idx > -1) res[i] = stack[idx];
        else res[i] = -1;
        stack[++idx] = nums[i];
    }
    return res;
}