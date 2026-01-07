#include <stdio.h>
int main(void){
    int date, month, year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &date, &year);
    printf("you entered the date: %02d%02d%2d\n", month, date, year);
    return 0;
}