// 3174. Clear Digits

char* clearDigits(char* s) {
    char *ans = (char *)malloc((strlen(s)+1)*(sizeof(char)));
    int idx = -1;
    for(int i=0; s[i]; i++){
        if(idx >= -1 && s[i] >= '0' && s[i] <= '9') idx -= 1;
        else ans[++idx] = s[i];
    }
    ans[++idx] = '\0';
    return ans;
}