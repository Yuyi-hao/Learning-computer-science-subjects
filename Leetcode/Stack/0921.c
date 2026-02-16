// 921. Minimum Add to Make Parentheses Valid
int minAddToMakeValid(char* s) {
    int curr_depth=0, neg_depth=0, pos_depth;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '('){
            curr_depth++;
        }
        else curr_depth--;
        if(curr_depth < 0){
            neg_depth++;
            curr_depth++;
        }
    }
    return neg_depth +curr_depth;
}

// first revision
int minAddToMakeValid(char* s) {
    int res=0, need=0;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '('){
            need++;
        }else{
            if(need > 0) need--;
            else{
                res++;
            }
        }
    }
    return res+need;
}