// 907. Sum of Subarray Minimums

#define MOD 1000000007

int sumSubarrayMins(int* arr, int arrSize) {
    int nll[arrSize], nlr[arrSize], stack[arrSize], idx=-1;
    for(int i=0; i<arrSize; i++){
        while(idx > -1 && arr[stack[idx]] > arr[i]) idx--;
        if(idx > -1) nll[i] = stack[idx];
        else nll[i] = -1;
        stack[++idx] = i;
    }
    idx = -1;
    for(int i=arrSize-1; i>-1; i--){
        while(idx > -1 && arr[stack[idx]] >= arr[i]) idx--;
        if(idx > -1) nlr[i] = stack[idx];
        else nlr[i] = arrSize;
        stack[++idx] = i;
    }
    long long ans = 0;

    for(int i = 0; i < arrSize; i++) {
        long long left = i - nll[i];
        long long right = nlr[i] - i;
        ans = (ans + (arr[i] * left * right) % MOD)%MOD;
    }
    return (int)ans;
}