// 844. Backspace String Compare

bool backspaceCompare(char* s, char* t) {
    int s_stack[201] = {0}, s_idx=-1;  
    int t_stack[201] = {0}, t_idx=-1;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '#'){
            if(s_idx >= 0) s_idx--;
        }else{
            s_stack[++s_idx] = s[i];
        }
    }
    for(int i=0; t[i] != '\0'; i++){
        if(t[i] == '#'){
            if(t_idx >= 0) t_idx--;
        }else{
            t_stack[++t_idx] = t[i];
        }
    }
    if(s_idx != t_idx) return false;
    for(int i=0; i<=s_idx; i++){
        if(s_stack[i] != t_stack[i]) return false;
    }
    return true;
}