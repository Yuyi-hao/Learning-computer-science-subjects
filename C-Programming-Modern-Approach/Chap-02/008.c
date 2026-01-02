#include <stdio.h>
int main(void){
    float amount, interest_rate, monthly_payment;
    printf("Enter amount: ");
    scanf("%f", &amount);
    printf("Enter Interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter Monthly Payment: ");
    scanf("%f", &monthly_payment);
    float balance = amount;
    float monthly_interest_rate = (interest_rate/100.0f)/12.0f;
    balance += (balance*monthly_interest_rate - monthly_payment);
    printf("Balance remaining after first payment: %0.2f\n", balance);
    balance += (balance*monthly_interest_rate - monthly_payment);
    printf("Balance remaining after second payment: %0.2f\n", balance);
    balance += (balance*monthly_interest_rate - monthly_payment);
    printf("Balance remaining after third payment: %0.2f\n", balance);
    return 0;
}