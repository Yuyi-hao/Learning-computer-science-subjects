// 1249. Minimum Remove to Make Valid Parentheses

char* minRemoveToMakeValid(char* s) {
    int len = strlen(s);
    int idx=0, depth=0;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '('){
            ++idx;
            depth += 1;
        }else if(s[i] == ')' && depth > 0){
            depth -= 1;
        }
    }
    idx -= depth;
    char *res = (char *)malloc(sizeof(char)*(len+1));
    int res_idx=0, brack_idx=0, curr_depth=0;
    for(int i=0; i<len; i++){
        if(s[i] == '('){
            if(brack_idx < idx){
                res[res_idx++] = '(';
                curr_depth++;
                brack_idx++;
            }
        }else if(s[i] == ')'){
            if(curr_depth > 0){
                res[res_idx++] = ')';
                curr_depth--;
            }
        }else{
            res[res_idx++] = s[i];
        }
    }
    res[res_idx] = '\0';
    return res;
}