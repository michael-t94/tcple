#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
int main()
{
    double fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Fahrenheit-Celsius Conversion Table\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = 5.0 * (fahr-32.0) / 9.0;
        /* format specifier:
         * %[flag][width][.precision][length]specifier
         *
         * Note: [width] specifies minimal number of characters to be printed,
         * if the value to be printed is shorter than [width], it will be packed
         * with blank spaces. If the value is longer than [width], it will be
         * printed out as it is.
         */
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
