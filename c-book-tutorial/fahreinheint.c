#include <stdio.h>

/* fareinheint calculator
 * calculate farhenheint to celsius table */
int main() {
    int upper, lower, step;
    float farh, celsius;
    lower = 10;
    upper = 300;
    step = 10;


    printf("fahrenheint\tcelsius\n");
    while(farh <= upper) {
        celsius = (9/5) * (farh - 32);
        printf("%3.0f\t\t%6.1f\n", farh, celsius);
        farh = farh + step;
    }
}
