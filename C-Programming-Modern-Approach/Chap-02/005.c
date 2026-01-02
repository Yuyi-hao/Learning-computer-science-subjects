#include <stdio.h>
int main(void){
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    int value = 3*x*x*x*x*x + 2*x*x*x*x -5*x*x*x -x*x+7*x-6;
    printf("The value of formula(3x^5 + 2x^4 - 5x^3 - x^2 + 7x -6): %d \n", value);
    return 0;
}