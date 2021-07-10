#define IN 1            /* inside a word or a string of blanks */
#define OUT 0           /* outside a word or a string of blanks */
#define MAXLINE 1000    /* max size of the array to hold an input line */
#define MAXLENGTH 15    /* max length of a word */
#define LONGLINE 80
#define TABSTOP 8

/* this function makes sure that every line ends with a '\n' */
int _getline(char line[], int lim);
void copy(char to[], char from[]);
void reverse(char str[]);

