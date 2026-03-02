// 316. Remove Duplicate Letters

#define MAX_LEN 10001
char* removeDuplicateLetters(char* s) {
    char *ans = (char *)malloc(sizeof(char)*MAX_LEN);
    int idx = -1;
    int freq[26] = {-1};
    int used[26] = {0};
    for(int i=0; s[i] != '\0'; i++) freq[s[i]-'a'] = i;
    
    for(int i=0; s[i]!= '\0'; i++){
        while(idx > -1 && 
                ans[idx] > s[i] 
                && freq[ans[idx]-'a'] > i
                && !used[s[i]-'a']){
            used[ans[idx]-'a'] = 0;
            idx--;
        }
        if(!used[s[i]-'a']){
            ans[++idx] = s[i];
            used[s[i]-'a'] = 1;
        }
    }
    ans[++idx] = '\0';
    return ans;
}