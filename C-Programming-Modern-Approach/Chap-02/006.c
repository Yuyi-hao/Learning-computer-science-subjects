#include <stdio.h>
int main(void){
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    int value = ((((3*x + 2)*x -5)*x - 1)*x +7)*x  -6;
    printf("The value of formula(3x^5 + 2x^4 - 5x^3 - x^2 + 7x -6): %d \n", value);
    return 0;
}