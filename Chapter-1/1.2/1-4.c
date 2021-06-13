#include <stdio.h>
#include <stdlib.h>

/* print Celsius-Fahrenheit table based on given input */
int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: ./a.out <lower> <upper> <step>\n");
        exit(1);
    }

    double lower = atof(argv[1]);
    double upper = atof(argv[2]);
    int step = atoi(argv[3]);

    printf("Celsius-Fahrenheit Conversion Table\n");
    double fahr, celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * 9.0 / 5.0 + 32.0;
        printf("%6.1f %6.1f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}
