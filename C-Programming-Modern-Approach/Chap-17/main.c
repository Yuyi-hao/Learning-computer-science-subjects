#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *s1, const char *s2){
    char *res = (char *)malloc(strlen(s1)+strlen(s2)+1);
    if(!res) return NULL;
    strcpy(res, s1);
    strcpy(res+strlen(s1), s2);
    return res;
}

int main(void){
    char *greet = "Hey, ";
    char *name = "Jean!";
    char *msg = (char *)calloc(10, 4);
    printf("%d\n", sizeof(msg));
    return 0;
}