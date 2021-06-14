/* copy input to output and replace each tab by \t, each backspace by \b,
 * and each backslash by \\.
 */

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if ( c != '\t' && c != '\b' && c != '\\') {
            putchar(c);
        }else {
            switch (c) {
                case '\t':
                    printf("\\t");
                    break;
                case '\b':
                    printf("\\b");
                    break;
                case '\\':
                    printf("\\\\");
                    break;
            }
        }
    }

    return 0;
}
