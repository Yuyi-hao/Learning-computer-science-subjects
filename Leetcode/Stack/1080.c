//1081. Smallest Subsequence of Distinct Characters

#define MAX_LEN 10001
char* smallestSubsequence(char* s) {
    char *ans = (char *)malloc(sizeof(char)*MAX_LEN);
    int indexs[26] = {-1}, used[26]={0}, idx=-1;
    for(int i=0; s[i]!= '\0'; i++) indexs[s[i]-'a'] = i;
    for(int i=0; s[i]!= '\0'; i++){
        while(idx > -1 && ans[idx] > s[i] && indexs[ans[idx]-'a'] > i && !used[s[i]-'a']){
            used[ans[idx]-'a'] = 0;
            idx--;
        }
        if(!used[s[i]-'a']){
            ans[++idx] = s[i];
            used[ans[idx]-'a'] = 1;
        }
    }
    ans[++idx] = '\0';
    return ans;
}