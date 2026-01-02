#include <stdio.h>
int main(void){
    float radius = 10.0f;
    float volume = (4.0f/3.0f)*(3.14f)*(radius*radius*radius);
    printf("The Volume of %dm radius is: %0.2f m^3\n", radius, volume);
    return 0;
}