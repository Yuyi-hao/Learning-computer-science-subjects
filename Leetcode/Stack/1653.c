// 1653. Minimum Deletions to Make String Balanced

int minimumDeletions(char* s) {
    int total_a=0, total_b=0, curr_a=0, curr_b=0;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == 'a') total_a++;
        else total_b++;
    }
    int ans=total_a;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == 'a') curr_a++;
        else curr_b++;
        ans = fmin(ans, (curr_b)+(total_a-curr_a));
    }
    return ans;
}