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


// first revision
#define MAX_LEN 100001
char* minRemoveToMakeValid(char* s) {
    int open_brakcets=0, close_brackets=0;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '(') open_brakcets++;
        else if(s[i] == ')' && open_brakcets > close_brackets) close_brackets++;
    }
    int balanced = fmin(open_brakcets, close_brackets), used=0;
    char *res = (char *)malloc(sizeof(char)*MAX_LEN);
    int idx=-1;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '('){
            if(balanced > 0 && balanced > used){
                used++;
                res[++idx] = s[i];
            }
        }else if(s[i] == ')'){
            if(used > 0 && balanced > 0){
                used--;
                balanced--;
                res[++idx] = s[i];
            }
        }else{
            res[++idx] = s[i];
        }
    }
    res[++idx] = '\0';
    return res;

}