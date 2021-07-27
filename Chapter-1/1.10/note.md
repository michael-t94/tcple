The program 1-23.c can remove both C-style comments like /* ... */ or
C++-style comments which begins by two consecutive forward slashes. To achieve
this, I implemented a stack.

# How the program works
When the stack is empty, it means that current input character can be in two
situations.

- it is outside of comments or quotes, then the program will print it as it is
- it is the closing character which makes the stack just empty, then the
  program will print it unless the character is a '/' since it is the end of a
  comment.

The program will only push '/*', '//', a double quote and a single quote into
the stack when the stack is empty and will ignore any characters until reaching
the matching pattern. And only when the stack top is a double
quote or a single quote, the program will print the input character. So it
removes all comments while handling the quotes properly.

Also, the program won't consider a qoute following a backslash '/' as the
terminating quote. Instead, it will be treated as a escape sequence. In other
words, '\'' will be handled properly.

Of course, the input C program shoube be free of syntax errors to make sure
the program can work correctly.

