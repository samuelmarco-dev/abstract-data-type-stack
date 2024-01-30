#include <stdio.h>
#include <stdlib.h>

typedef struct nodei {
    char info;
    struct nodei *prox;
} node;

typedef struct {
    node *top;
    int total;
    int atual;
} stack;

stack *newStack();
node *newNode(char v);
int isStackEmpty(stack *s);
void push(stack *s, char value);
char pop(stack *s);
char top(stack *s);

int main() {
    stack *nome = newStack();
    push(nome, 'A');
    push(nome, 'D');
    push(nome, 'R');
    push(nome, 'I');
    push(nome, 'A');
    push(nome, 'N');
    push(nome, 'O');
    printf("Atual: %d | Total: %d\n",
           atual(nome), total(nome));
    while(!isStackEmpty(nome)) {
        printf("%c", pop(nome));
    }
    printf("Atual: %d | Total: %d\n",
           atual(nome), total(nome));

}


stack *newStack() {
 stack *s = (stack *)malloc(sizeof(stack));
 s->top = NULL;
 s->atual = 0;
 s->total = 0;
 return s;
}

node *newNode(char v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    return n;
}

int isStackEmpty(stack *s) {
    if (s->top == NULL) return 1;
    else return 0;
}

void push(stack *s, char value) {
    node *n = newNode(value);
    n->prox = s->top;
    s->top = n;
    s->total++;
    s->atual++;
}

char pop(stack *s) {
    node *n;
    char v;

    if (isStackEmpty(s)) {
        printf("Pilha vazia!!!\n");
        return '\0';
    }

    n = s->top;
    s->top = n->prox;
    v = n->info;
    free(n);

    s->atual--;

    return v;
}

char top(stack *s) {
    node *n;

    if (isStackEmpty(s)) {
        printf("Pilha vazia!!!\n");
        return '\0';
    }

    return s->top->info;
}


int total(stack *s) {
    return s->total;
}

int atual(stack *s) {
    return s->atual;
}
