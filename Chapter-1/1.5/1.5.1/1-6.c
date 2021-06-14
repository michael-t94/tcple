#include <stdio.h>

int main()
{
    /* The precedence of != is higher than that of =, so the assignment is
     * equivalent to int c = (getchar() != EOF). So the value of c is 1
     * when getchar() success, 0 when getchar() reaches end of line or some
     * reading error happens. The return type of getchar() is an int.
     */
    int c = getchar() != EOF;
    printf("The value of the expression getchar() != EOF is %d\n", c);

    return 0;
}
