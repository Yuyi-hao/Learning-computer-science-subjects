// 1856. Maximum Subarray Min-Product

#define MOD 1000000007
int maxSumMinProduct(int* nums, int numsSize) {
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

    long long prefix_sum_ltr[numsSize+1];
    prefix_sum_ltr[0] = 0ll;
    for(int i=0; i<numsSize; i++){
        prefix_sum_ltr[i+1] = prefix_sum_ltr[i]+(long long)nums[i];
    }

    long long ans = 0;
    for(int i=0; i<numsSize; i++){
        long long curr = ((long long)nums[i])*(prefix_sum_ltr[nlr[i]]-prefix_sum_ltr[nll[i]+1]);
        if(curr > ans) ans = curr;
    }
    return (int)(ans%MOD);
}