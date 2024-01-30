#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Conceito Pilha:
    O último a entrar é o primeiro a sair
    O primeiro a entrar é o último a sair

Pilha dinâmica:
    O primeiro a entrar vai apontar para null
    E todos os seguintes vão apontar para o topo anterior
*/

typedef struct nodeitem {
    int information;
    struct nodeitem *next;
} node;

typedef struct {
    node *top;
} stack;

stack *newStack();
node *newNode(int information);
void push(stack *s, int value);
int pop(stack *s);

int top(stack *s);
int stackEmpty(stack *s);

int main() {
    setlocale(LC_ALL, "");

    stack *stackPtr = newStack();
    push(stackPtr, 10); //n->next = NULL; s->top = n
    push(stackPtr, 20); //n->next = n; s->top = n1
    push(stackPtr, 30); //n->next = n1; s->top = n2
    /*É como se estivéssemos inserindo elementos (nós) apenas no início da pilha*/

    while(!stackEmpty(stackPtr)) {
        printf("Top: %d\n", top(stackPtr)); //s->top = n: information, next; return s->top->information
        printf("-> %d\n", pop(stackPtr)); //n = s->top; s->top = n->next; return s->top->information
    }

    return 0;
}

stack *newStack() {
    stack *s = (stack *)malloc(sizeof(stack));

    s->top = NULL;
    return s;
}

node *newNode(int information) {
    node *n = (node *)malloc(sizeof(node));

    n->information = information;
    n->next = NULL;
    return n;
}

/*
    1. Criar um novo nó e colocar o valor do valor no campo de informação do nó criado
            a. Como este nó está sendo instanciado, inicialmente aponta para NULL
    2. Fazer com que o campo próximo do nó criado, aponte para o topo
    3. Fazer com que o topo receba uma atribuição para o nó criado
*/
void push(stack *s, int value) {
    node *n = newNode(value);
    n->next = s->top;
    s->top = n;
}

/*
    1. Criar um nó para guardar o que está no topo, o topo será acessado de forma direta
    2. Guardar a informação atribuiada a este nó em uma nova variável auxiliar do tipo de dado acessado
    3. Vou acessar o valor do próximo que está atribuido ao no, e vou atribui-lo ao topo
        a. O topo atualizado vai apontar para o topo anterior que está em n->next
*/
int pop(stack *s) {
    if(stackEmpty(s)) {
        printf("A pilha está vazia no momento. Tente novamente!\n"); //Stack Underflow
        exit(1);
    }

    node *n;
    int aux;
    n = s->top;
    aux = n->information;
    s->top = n->next;
    free(n);

    return aux;
}

int stackEmpty(stack *s) {
    return s->top == NULL;
}

int top(stack *s) {
    if(stackEmpty(s)) {
        printf("A pilha está vazia no momento. Tente novamente!\n"); //Stack Underflow
        return;
    }

    return s->top->information;
}
