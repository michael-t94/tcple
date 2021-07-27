#include <stdio.h>
#include <stdlib.h>
#include "include/stack.h"

int empty(const Symbols *s)
{
    if (s->size == 0)  /* if empty */
        return 1;
    else
        return 0;
}

void push(Symbols *s, char e)
{
    /* check if stack out of bounds */
    if ((s->top - s->elements + 1) > MAXSIZE) {
        fprintf(stderr, "Fatal: stack out of bound!\n");
        exit(1);
    }

    *(++s->top) = e;
    ++s->size;
}

int pop(Symbols *s)
{
    if (empty(s)) {
        fprintf(stderr, "Error: stack already empty\n");
        return -1;
    } else {
        --s->top;
        --s->size;
        return *(s->top + 1);
    }
}
