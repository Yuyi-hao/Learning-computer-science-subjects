// 678. Valid Parenthesis String

#define MAX_LEN 101
bool checkValidString(char* s) {
    char low=0, high=0; // minimum and maximum possible '(' count 
    int idx = -1, stars=0;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] == '('){
            low++;
            high++;
        }else if(s[i] == ')'){
            low--;
            high--;
        }else{
            low--;
            high++;
        }
        if(high < 0) return false;
        if(low < 0) low=0;
    }
    return low==0;
}