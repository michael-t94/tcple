#include <stdio.h>

int _getline(char line[], int lim)
{
    int c;
    int len = 0;    /* len records how many characters have been read until reach '\n' in for loop */
    int i = 0;      /* i records how many characters have been copied in for loop */

    for (; (c = getchar()) != EOF && c != '\n'; ++len) {
        if (len < lim - 2) {    /* line[lim - 2] is for '\n', characters beyond the limit are simply ignored */
            line[i] = c;
            ++i;
        }
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
        ++len;
    }
    line[i] = '\0';

    return len;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}

void reverse(char str[])
{
    /* find length of string src */
    int len = 0;
    while (str[len] != '\0')
        ++len;

    /* if the end character is a '\n', reduce len by 1 since we don't want
     * to move it to the begining of a line
     */
    if (str[len - 1] == '\n')
        --len;

    /* reverse str in place */
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}
