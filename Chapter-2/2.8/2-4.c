#include <stdio.h>

/* delete characters given by s2 in s1 */
void squeeze(char s1[], const char s2[])
{
    int i = 0;      /* index in s2 */

    /* TODO
     * This piece of code may be implemented using multithreaded programming.
     * Using one thread to handle each character in s2.
     */
    while (s2[i] != '\0') {
        /* k indexing writting position, j indexing reading position */
        int k = 0;
        for (int j = 0; s1[j] != '\0'; ++j) {
            if (s1[j] != s2[i])
                s1[k++] = s1[j];
        }
        s1[k] = '\0';
        ++i;
    }
}

int main()
{
    char s1[] = "saa123bbbtring";
    char s2[] = "ab";

    printf("squeeze %s using characters in %s\n", s1, s2);
    squeeze(s1, s2);
    printf("s1: %s\n", s1);

    return 0;
}
