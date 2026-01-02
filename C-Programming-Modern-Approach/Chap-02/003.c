#include <stdio.h>
int main(void){
    float radius;
    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);
    float volume = (4.0f/3.0f)*(3.14f)*(radius*radius*radius);
    printf("The Volume of %0.2fm radius is: %0.2f m^3\n", radius, volume);
    return 0;
}