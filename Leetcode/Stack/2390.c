// 2390. Removing Stars From a String

#define MAX_LEN 100001
char* removeStars(char* s) {
    char *res = (char *)malloc(sizeof(char)*MAX_LEN);
    int idx=-1;
    for(int i=0; s[i] != '\0'; i++){
        if(idx > -1 && s[i] == '*') idx--;
        else res[++idx] = s[i];
    }
    res[++idx] = '\0';
    return res;
}