#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define LENGTH 50

typedef struct {
    int top;
    int qtd;
    int numberCurrent;
    char data[LENGTH];
} stack;

stack *newStack();
void push(stack *s, char caracter);
char pop(stack *s);
char top(stack *s);

int numberElementsInserted(stack *s);
int numberElementsCurrent(stack *s);

int stackEmpty(stack *s);
int stackFull(stack *s);

int main() {
    setlocale(LC_ALL, "");

    stack *s = newStack();
    push(s, 'a');
    push(s, 'b');
    push(s, 'c');

    printf("numberElementsInserted: %d\n", numberElementsInserted(s));
    printf("numberElementsCurrent: %d\n", numberElementsCurrent(s));

    while(!stackEmpty(s)){
        printf("Top -> %c\n", top(s));
        printf("Pop -> %c\n", pop(s));
    }
    printf("numberElementsInserted: %d\n", numberElementsInserted(s));
    printf("numberElementsCurrent: %d\n", numberElementsCurrent(s));

    return 0;
}

int stackEmpty(stack *s) {
    return s->top == 0;
}

int stackFull(stack *s) {
    return s->top == LENGTH;
}

stack *newStack() {
    stack *s = (stack *)malloc(sizeof(stack));

    s->top = 0;
    s->qtd = 0;
    s->numberCurrent = 0;
    return s;
}

void push(stack *s, char caracter) {
    if(stackFull(s)) {
        printf("A pilha est� cheia no momento. Tente novamente!\n"); //Stack Overflow
        exit(1);
    }

    s->data[s->top] = caracter;
    s->top++;
    s->qtd++;
    s->numberCurrent++;
}

char pop(stack *s) {
    if(stackEmpty(s)) {
        printf("A pilha est� vazia no momento. Tente novamente!\n"); //Stack Underflow
        exit(1);
    }

    s->top--;
    s->numberCurrent--;
    return s->data[s->top];
}

char top(stack *s) {
    if(stackEmpty(s)) {
        printf("A pilha est� vazia no momento. Tente novamente!\n"); //Stack Underflow
        return;
    }

    return s->data[s->top - 1];
}

int numberElementsInserted(stack *s) {
    return s->qtd;
}

int numberElementsCurrent(stack *s) {
    return s->numberCurrent;
}
