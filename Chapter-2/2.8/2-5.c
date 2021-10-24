#include <stdio.h>

/* Found any characters given by s2 in s1 and return the first location,
 * otherwise return -1.
 */
int any(const char s1[], const char s2[])
{
    for (int i = 0; s1[i] != '\0'; ++i) {
        for (int j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) /* found match */
                return i;
        }
    }

    return -1;  /* no match */
}

int main()
{
    char s1[100], s2[50];

    printf("Input search string(no more than 99 charcters): ");
    scanf("%s", s1);
    printf("Input match character string(no more than 49 characters): ");
    scanf("%s", s2);

    int rtn = any(s1, s2);
    if (rtn == -1) {
        printf("No match found\n");
    } else {
        printf("Found %c at %d\n", s1[rtn], rtn);
    }

    return 0;
}
