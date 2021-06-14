#include <stdio.h>

/* print Fahrenheit-Celsius table in reverse order */
int main()
{
    for (int fahr = 300; fahr >= 0; fahr -= 20) {
        printf("%3d %6.1f\n", fahr, 5.0 * (fahr - 32) / 9.0);
    }

    return 0;
}

