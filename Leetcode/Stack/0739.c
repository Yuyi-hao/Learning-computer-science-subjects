// 739. Daily Temperatures

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int stack[temperaturesSize];
    int idx=-1;
    int *res = (int *)malloc(sizeof(int)*temperaturesSize);
    *returnSize = temperaturesSize;
    for(int i=temperaturesSize-1; i>-1; i--){
        while(idx > -1 && temperatures[stack[idx]] <= temperatures[i]) idx--;
        if(idx > -1) res[i] = stack[idx]-i;
        else res[i] = 0;
        stack[++idx] = i;
    }
    return res;
}