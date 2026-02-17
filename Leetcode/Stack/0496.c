// 496. Next Greater Element I

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *res = (int *)malloc(sizeof(int)*nums1Size);
    int nge[nums2Size];
    // int *nge = (int *)malloc(sizeof(int)*nums2Size);
    int stack[nums2Size];
    int idx=-1;
    *returnSize = nums1Size;
    for(int i=nums2Size-1; i>=0; i--){
        while(idx > -1 && nums2[stack[idx]] < nums2[i]) idx--;
        if(idx > -1) nge[i] = nums2[stack[idx]];
        else nge[i] = -1;
        stack[++idx] = i;
    }
    for(int i=0; i<nums1Size; i++){
        for(int j=0; j < nums2Size; j++){
            if(nums1[i] == nums2[j]){
                res[i] = nge[j];
            }
        }
    }
    return res;
}