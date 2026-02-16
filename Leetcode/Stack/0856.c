// 856. Score of Parentheses

int scoreOfParentheses(char* s) {
    int score = 0;
    int depth = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            depth++;
        } else {
            depth--;
            if (s[i-1] == '(') {   // only primitive pair
                score += 1 << depth;
            }
        }
    }
    return score;
}

// first revision
int scoreOfParentheses(char* s) {
    int depth=0;
    int score=0;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '(') depth++;
        if(s[i] == ')' && s[i-1] == '(') score += (1<<(depth-1));
        if(s[i] == ')') depth--;
    }
    return score;
}