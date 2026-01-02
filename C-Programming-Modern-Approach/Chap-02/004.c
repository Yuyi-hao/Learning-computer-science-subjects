#include <stdio.h>
int main(void){
    float amount;
    printf("Enter the amount: ");
    scanf("%f", &amount);
    float taxed_amount = amount + amount*0.05f;
    printf("With taxed added: %0.2f\n", taxed_amount);
    return 0;
}