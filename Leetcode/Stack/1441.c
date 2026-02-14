// 1441. Build an Array With Stack Operations

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_LEN 200

char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char **res = (char **)malloc(sizeof(char *)*MAX_LEN);
    int idx = 0, target_idx=0;
    int stack[MAX_LEN] = {0}, stack_idx=-1;
    for(int i=1; i<= n && target_idx < targetSize; i++){
        stack[++stack_idx] = i;
        res[idx++] = "Push";
        if(target[target_idx] != stack[stack_idx]){
            stack_idx--;
            res[idx++] = "Pop";
        }else{
            target_idx++;
        }
    }
    *returnSize = idx; 
    return res;
}

/*
Worst Case Output Size Calculation:

Let:
m = targetSize
last = target[targetSize - 1]

We iterate from i = 1 to last.

For each number:
- If number is in target → 1 operation ("Push")
- If number is NOT in target → 2 operations ("Push", "Pop")

Total numbers processed = last

Among them:
- m numbers are in target
- (last - m) numbers are skipped

Total operations =
    m * 1 + (last - m) * 2
  = m + 2(last - m)
  = 2 * last - m

Since:
- last ≤ n ≤ 100
- m ≥ 1

Worst case occurs when:
    last = 100
    m = 1

Maximum operations =
    2 * 100 - 1
  = 199

So allocating size 200 is safe.
*/
