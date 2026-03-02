// 402. Remove K Digits

#define MAX_LEN 100001
char* removeKdigits(char* num, int k) {
    char *ans = (char *)malloc(sizeof(char)*MAX_LEN);
    int idx = -1;
    for(int i=0; num[i]!='\0'; i++){
        while(idx > -1 && (ans[idx] > num[i] && k>0)){
            idx--;
            k--;
        }
        if(!(idx == -1 && num[i] =='0'))ans[++idx] = num[i];
    }
    while(k > 0 && idx > -1){
        idx--;
        k--;
    }
    if(idx < 0) ans[++idx] = '0';
    ans[++idx] = '\0';
    return ans;
}