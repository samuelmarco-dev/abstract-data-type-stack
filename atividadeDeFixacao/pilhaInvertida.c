#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define LENGTH 50

typedef struct {
    int top;
    int topAux;
    int data[LENGTH];
    int aux[LENGTH];
} stack;

stack *newStack();
void push(stack *s, int value, int type);
int pop(stack *s);
int top(stack *s);
void mostraPilhaInvertida(stack *s);

int isStackEmpty(stack *s);
int isStackFull(stack *s);

int main() {
    setlocale(LC_ALL, "");

    stack *s = newStack();;
    int remove;

    push(s, 10, 1);
    push(s, 20, 1);
    push(s, 30, 1);
    push(s, 40, 1);

    while(!isStackEmpty(s)) {
        printf("Topo pilha: %d\n", top(s));
        remove = pop(s);
        printf("Elemento pop: %d\n", remove);
        push(s, remove, 0);
    }
    mostraPilhaInvertida(s);

    return 0;
}

stack *newStack() {
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = 0;
    s->topAux = 0;

    return s;
}

void push(stack *s, int value, int type) {
    if(isStackFull(s)) {
        printf("A pilha est� cheia no momento. Tente novamente!\n"); //Stack Overflow
        exit(1);
    }

    if(type == 1) {
        s->data[s->top] = value;
        s->top++;
    } else {
        s->aux[s->topAux] = value;
        s->topAux++;
    }
}

int pop(stack *s) {
    if(isStackEmpty(s)) {
        printf("A pilha est� vazia no momento. Tente novamente!\n"); //Stack Underflow
        exit(1);
    }

    s->top--;
    return s->data[s->top];
}

int top(stack *s) {
    if(isStackEmpty(s)) {
        printf("A pilha est� vazia no momento. Tente novamente!\n"); //Stack Underflow
        return;
    }

    return s->data[s->top - 1];
}

void mostraPilhaInvertida(stack *s) {
    if(s->topAux == 0) {
        printf("A pilha invertida est� vazia no momento. Tente novamente!\n"); //Stack Underflow
        return;
    }

    printf("Elementos pilha invertida: \n");
    for(int i = 0; i<s->topAux; i++) {
        printf("%d ", s->aux[i]);
    }
    printf("\n");
}

int isStackEmpty(stack *s) {
    return s->top == 0;
}

int isStackFull(stack *s) {
    return s->top == LENGTH;
}
