// 962. Maximum Width Ramp

#define MAX_LEN 50001
int maxWidthRamp(int* nums, int numsSize) {
    int stack[MAX_LEN], idx=-1;
    for(int i=0; i<numsSize; i++){
        if(idx == -1 || nums[stack[idx]] >= nums[i]){
            stack[++idx] = i;
        } 
    }
    int ans=0;
    for(int i=numsSize-1; i>-1; i--){
        while(idx > -1 && nums[stack[idx]] <= nums[i]){
            ans = fmax(ans, i-stack[idx]);
            idx--;
        }
    }
    return ans;
}