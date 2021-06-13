# Old-style main function
The program 1-1.c is the source code given in the book. Note that the definition 
of main function in 1-1.c neither has a return type nor a return statement as we would 
usually find at function definitions in C programs nowadays. That's because this book
describes C as defined by the ANSI C standard, in which the `int` return type is implied
if not specified explicitly and later standards changed this behavior. So if you compile
the program with the command `cc 1-1.c`, you would probably get a warning like this
```
1-1.c:3:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]
main()
^
1 warning generated.
```

To get rid of this warning, set the option `-std` to one of these values:
c89, c90 or iso9899:1990. For example, `cc -std=c89 1-1.c`.

# Little bit of history of C standards
The first C standard is the ANSI C which came out in 1989, that's why it is also referred 
as c89. It was originally developed by American National Standards Institute, and later on
adopted by International Organization for Standardization(ISO) in 1990 as International
Standard ISO/IEC 9899:1990, also referred as c90. So c89, c90 and iso9899:1990 are just
three different names of one standard.

# Unknown escape sequence
The program 1-2.c printed out `chello, world!` on my computer. It appears that the compiler
will drop the backslash character '\\' if it encounters escape sequences which can't be 
recoginized.
