// 1475. Final Prices With a Special Discount in a Shop

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int stack[pricesSize], idx=-1;
    int *res = (int *)malloc(sizeof(int)*pricesSize);
    for(int i=pricesSize-1; i>-1; i--){
        while(idx > -1 && stack[idx] > prices[i]) idx--;
        if(idx > -1) res[i] = -stack[idx];
        else  res[i] = 0;
        stack[++idx] = prices[i];
    }
    for(int i=0; i<pricesSize; i++){
        res[i] += prices[i];
    }
    *returnSize = pricesSize;
    return res;
}