#include<stdio.h>
int main(void){
    int amount;
    printf("Enter amount: ");
    scanf("%d", &amount);
    int bill20 = amount/20;
    int bill10 = (amount%20)/10;
    int bill5 = ((amount%20)%10)/5;
    int bill1 = ((amount%20)%10)%5;
    printf("$20 bills: %d\n", bill20);
    printf("$10 bills: %d\n", bill10);
    printf("$5 bills: %d\n", bill5);
    printf("$1 bills: %d\n", bill1);
    return 0;
}