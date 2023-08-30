#include <stdio.h>

/* symbolic constants (macro sub) */
#define LOWER 0
#define UPPER 300
#define STEP 20

/* fareinheint calculator
 * calculate farhenheint to celsius table */
int main() {
    float farh, celsius;

    printf("fahrenheint\tcelsius\n");
    while(farh <= UPPER) {
        celsius = (9/5) * (farh - 32);
        printf("%3.0f\t\t%6.1f\n", farh, celsius);
        farh = farh + STEP;
    }
}
