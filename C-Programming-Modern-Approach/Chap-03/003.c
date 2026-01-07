#include<stdio.h>
int main(void){
    int gs1_prefix, group_id, publisher_code, item_number, check_digit;
    printf("Enter ISBN: ");
    scanf("%3d-%1d-%3d-%5d-%1d", &gs1_prefix, &group_id, &publisher_code, &item_number, &check_digit);
    printf("GS1 Prefix: %3d\n", gs1_prefix);
    printf("Group Identifier: %1d\n", group_id);
    printf("Publisher code: %3d\n", publisher_code);
    printf("Item number: %5d\n", item_number);
    printf("Check digit: %1d\n", check_digit);
    return 0;
}