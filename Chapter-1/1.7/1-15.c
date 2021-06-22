#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
void fctable(int lower, int upper, int step);

int main()
{
    int lower = 0;      /* lower limit of temperature scale */
    int upper = 300;    /* upper limit */
    int step = 20;      /* step size */

    fctable(lower, upper, step);

    return 0;
}

void fctable(int lower, int upper, int step)
{
    double fahr, celsius;

    printf("Fahrenheit-Celsius Conversion Table\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = 5.0 * (fahr-32.0) / 9.0;
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
