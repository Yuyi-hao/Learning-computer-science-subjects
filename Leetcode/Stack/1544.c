1544. Make The String Great

char* makeGood(char* s) {
    char *res = (char *)malloc(sizeof(char)*101);
    int idx=-1;
    for(int i=0; s[i] != '\0'; i++){
        if(idx > -1 && fabs(res[idx]-s[i])==32) idx--;
        else res[++idx] = s[i];
    }
    res[++idx] = '\0';
    return res;
}