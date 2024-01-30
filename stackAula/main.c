#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 10

typedef struct {
    int top; //index
    int data[N]; //array static
} stack;

stack *newStack();
void push(stack *p, int number);
int pop(stack *p);

int readAndSend();
int top(stack *p);
int stackEmpty(stack *p);
int stackFull(stack *p);

int main() {
    setlocale(LC_ALL, "");

    stack *stackPtr = newStack();
    push(stackPtr, 10);
    push(stackPtr, 20);
    push(stackPtr, 30);
    push(stackPtr, readAndSend());

    while(!stackEmpty(stackPtr)) {
        printf("Top: %d\n", top(stackPtr));
        printf("-> %d\n", pop(stackPtr));
    }

    return 0;
}

int readAndSend() {
    int value;
    printf("Informe o valor a ser inserido na pilha: ");
    scanf("%d", &value);
    printf("\n");

    return value;
}

stack *newStack() {
    stack *stackPtr = (stack *)malloc(sizeof(stack));

    stackPtr->top = 0;
    return stackPtr;
}

void push(stack *p, int number) {
    if(stackFull(p)) {
        printf("A pilha está cheia no momento. Tente novamente!\n"); //Stack Overflow
        exit(1);
    }

    p->data[p->top] = number;
    p->top++;
}

int pop(stack *p) {
    if(stackEmpty(p)) {
        printf("A pilha está vazia no momento. Tente novamente!\n"); //Stack Underflow
        exit(1);
    }

    p->top--;
    //s->data[top] = 0;
    return p->data[p->top];
}

int stackFull(stack *p) {
    return p->top == N;
}

int stackEmpty(stack *p) {
    return p->top == 0;
}

int top(stack *s) {
    if(stackEmpty(s)) {
        printf("A pilha está vazia no momento. Tente novamente!\n"); //Stack Underflow
        return;
    }

    return s->data[s->top - 1];
}
