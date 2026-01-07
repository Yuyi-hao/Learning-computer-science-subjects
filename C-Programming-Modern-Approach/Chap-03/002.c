#include<stdio.h>
int main(void){
    int item_number;
    float unit_price;
    int date, month, year; /* Purchase date */
    printf("Enter item number: ");
    scanf("%d", &item_number);
    printf("Enter unit price: ");
    scanf("%f", &unit_price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &month, &date, &year);
    printf("Item \t Unit Price \t Purchase\n");
    printf("%-4d \t $%9.2f \t %2d/%2d/%4d\n", item_number, unit_price, month, date, year);
    return 0;
}