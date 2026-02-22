// 1793. Maximum Score of a Good Subarray
int maximumScore(int* nums, int numsSize, int k) {
    int nll[numsSize], nlr[numsSize], stack[numsSize], idx=-1;
    for(int i=0; i<numsSize; i++){
        while(idx > -1 && nums[stack[idx]] > nums[i]) idx--;
        if(idx > -1) nll[i] = stack[idx];
        else nll[i] = -1;
        stack[++idx] = i;
    }
    idx = -1;
    for(int i=numsSize-1; i>-1; i--){
        while(idx > -1 && nums[stack[idx]] >= nums[i]) idx--;
        if(idx > -1) nlr[i] = stack[idx];
        else nlr[i] = numsSize;
        stack[++idx] = i;
    }
    int ans =0;
    for(int i=0; i< numsSize; i++){
        int left = nll[i];
        int right = nlr[i];
        if(left < k && k < right){
            int curr = nums[i]*(right-left-1);
            if(curr > ans) ans = curr;
        }
    }
    return ans;
}