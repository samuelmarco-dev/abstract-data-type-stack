#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Conceito Pilha:
    O �ltimo a entrar � o primeiro a sair
    O primeiro a entrar � o �ltimo a sair

Pilha din�mica:
    O primeiro a entrar vai apontar para null
    E todos os seguintes v�o apontar para o topo anterior
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
    /*� como se estiv�ssemos inserindo elementos (n�s) apenas no in�cio da pilha*/

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
    1. Criar um novo n� e colocar o valor do valor no campo de informa��o do n� criado
            a. Como este n� est� sendo instanciado, inicialmente aponta para NULL
    2. Fazer com que o campo pr�ximo do n� criado, aponte para o topo
    3. Fazer com que o topo receba uma atribui��o para o n� criado
*/
void push(stack *s, int value) {
    node *n = newNode(value);
    n->next = s->top;
    s->top = n;
}

/*
    1. Criar um n� para guardar o que est� no topo, o topo ser� acessado de forma direta
    2. Guardar a informa��o atribuiada a este n� em uma nova vari�vel auxiliar do tipo de dado acessado
    3. Vou acessar o valor do pr�ximo que est� atribuido ao no, e vou atribui-lo ao topo
        a. O topo atualizado vai apontar para o topo anterior que est� em n->next
*/
int pop(stack *s) {
    if(stackEmpty(s)) {
        printf("A pilha est� vazia no momento. Tente novamente!\n"); //Stack Underflow
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
        printf("A pilha est� vazia no momento. Tente novamente!\n"); //Stack Underflow
        return;
    }

    return s->top->information;
}
