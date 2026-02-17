// 456. 132 Pattern

bool find132pattern(int* nums, int numsSize) {
    int stack[numsSize], idx=-1, num=INT_MIN;
    for(int i=numsSize-1; i>-1; i--){
        if(nums[i] < num) return true;
        while(idx > -1 && stack[idx] < nums[i]){
            num = stack[idx];
            idx--;
        }
        stack[++idx] = nums[i];
    }
    return false;
}