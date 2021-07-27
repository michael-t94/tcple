#define MAXSIZE 10

typedef struct {
    char elements[MAXSIZE];
    char *top;                  /* stack top */
    int size;                   /* stack size */
} Symbols;

int empty(const Symbols *s);
void push(Symbols *s, char e);
int pop(Symbols *s);
