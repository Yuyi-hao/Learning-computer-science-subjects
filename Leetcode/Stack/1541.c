// 1541. Minimum Insertions to Balance a Parentheses String

int minInsertions(char* s) {
    int ops=0, need=0;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '('){
            if(need&1){
                ops++;
                need--;
            }
            need += 2;
        }else{
            need--;
            if(need < 0){
                ops++;
                need+= 2;
            }
        }
    }
    return ops+need;
}