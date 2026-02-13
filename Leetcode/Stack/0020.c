// 20. Valid Parentheses

#define MAX_LEN 10000
bool isValid(char* s) {
    char stack[MAX_LEN] = {0};
    int curr_idx = -1;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '(' || s[i]=='{' || s[i]=='['){
            stack[++curr_idx] = s[i];
        }
        else{
            if(curr_idx == -1) return false;
            if(s[i] == ')'){
                if(stack[curr_idx] != '(') return false;
            }else if(s[i] == ']'){
                if(stack[curr_idx] != '[') return false;
            }else if(s[i] == '}'){
                if(stack[curr_idx] != '{') return false;
            }
            curr_idx--;
        }
    }
    return curr_idx == -1;
}