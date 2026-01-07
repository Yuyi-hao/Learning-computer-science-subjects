#include<stdio.h>
int main(void){
    int first_part, middle_part, last_part;
    printf("Enter phone number[(xxx) xxx-xxxx]: ");
    scanf("(%3d) %3d-%4d", &first_part, &middle_part, &last_part);
    printf("You Entered: %3d.%3d.%4d\n", first_part, middle_part, last_part);
    return 0;
}