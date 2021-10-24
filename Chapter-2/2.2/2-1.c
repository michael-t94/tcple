#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    /* printing values from standard headers: i386/_limits.h */
    printf("Unsigned char: [0, %u], %ld byte.\n", UCHAR_MAX, sizeof(unsigned char));
    printf("Signed char: [%d, %d], %ld byte.\n", SCHAR_MIN, SCHAR_MAX, sizeof(char));

    printf("Unsigned short: [0, %u], %ld bytes.\n", USHRT_MAX, sizeof(unsigned short));
    printf("Signed short: [%d, %d], %ld bytes.\n", SHRT_MIN, SHRT_MAX, sizeof(short));

    printf("Unsigned int: [0, %u], %ld bytes.\n", UINT_MAX, sizeof(unsigned int));
    printf("Signed int: [%d, %d], %ld bytes.\n", INT_MIN, INT_MAX, sizeof(int));

    printf("Unsigned long: [0, %lu], %ld bytes.\n", ULONG_MAX, sizeof(unsigned long));
    printf("Signed long: [%ld, %ld], %ld bytes.\n", LONG_MIN, LONG_MAX, sizeof(long));

    /* from float.h
     * macros in this file are defined using CPP predefined macros
     * using cpp -dM to check these predefined macros
     */
    printf("float: [%e, %e], %ld bytes.\n", FLT_MIN, FLT_MAX, sizeof(float));
    printf("Double: [%e, %e], %ld bytes.\n", DBL_MIN, DBL_MAX, sizeof(double));
    printf("Long double: [%Le, %Le], %ld bytes.\n", LDBL_MIN, LDBL_MAX, sizeof(long double));

    return 0;
}
