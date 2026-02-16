// 1021. Remove Outermost Parentheses

#define MAX_LEN 100001
char* removeOuterParentheses(char* s) {
    char *res = (char *)malloc(sizeof(char)*MAX_LEN);
    int idx=0, depth=0;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '('){
            depth++;
            if(depth > 1){
                res[idx++] = s[i];
            }
        }else{
            depth--;
            if(depth > 0){
                res[idx++] = s[i];
            }
        }
    }
    res[idx] = '\0';
    return res;  
}

// first revision
#define MAX_LEN 100001
char* removeOuterParentheses(char* s) {
    char *res = (char *)malloc(sizeof(char)*MAX_LEN);
    int idx=-1, depth=0;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '(') depth++;
        if(depth > 1) res[++idx] = s[i];
        if(s[i] == ')') depth--;
    }
    res[++idx] = '\0';
    return res;
}