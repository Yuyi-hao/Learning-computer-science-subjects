// 2104. Sum of Subarray Ranges

long long subArrayRanges(int* nums, int numsSize) {
    int nll[numsSize], nlr[numsSize], stack[numsSize], idx=-1;
    for(int i=0; i<numsSize; i++){
        while(idx > -1 && nums[stack[idx]] > nums[i]) idx--;
        if(idx > -1) nll[i] = stack[idx];
        else nll[i] = -1;
        stack[++idx] = i;
    }
    idx = -1;
    for(int i=numsSize-1; i > -1; i--){
        while(idx > -1 && nums[stack[idx]] >= nums[i]) idx--;
        if(idx > -1) nlr[i] = stack[idx];
        else nlr[i] = numsSize;
        stack[++idx] = i;
    }
    long long minimum_sum = 0;
    for(int i=0; i<numsSize; i++){
        minimum_sum += ((long long)nums[i]*(long long)(i-nll[i])*(long long)(nlr[i]-i));
    }
    idx = -1;
    for(int i=0; i<numsSize; i++){
        while(idx > -1 && nums[stack[idx]] <= nums[i]) idx--;
        if(idx > -1) nll[i] = stack[idx];
        else nll[i] = -1;
        stack[++idx] = i;
    }
    idx = -1;
    for(int i=numsSize-1; i > -1; i--){
        while(idx > -1 && nums[stack[idx]] < nums[i]) idx--;
        if(idx > -1) nlr[i] = stack[idx];
        else nlr[i] = numsSize;
        stack[++idx] = i;
    }
    long long maximum_sum = 0;
    for(int i=0; i<numsSize; i++){
        maximum_sum += ((long long)nums[i]*(long long)(i-nll[i])*(long long)(nlr[i]-i));
    }
    return maximum_sum-minimum_sum;
}