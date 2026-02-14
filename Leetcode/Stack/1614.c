// 1614. Maximum Nesting Depth of the Parentheses

int maxDepth(char* s) {
    int depth=0, curr_depth = 0;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '(') curr_depth++;
        else if(s[i] == ')') curr_depth--;
        depth = fmax(curr_depth, depth);
    }
    return depth;
}