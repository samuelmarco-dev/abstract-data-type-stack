#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define LENGTH 50

typedef struct{
    int top;
    char data[LENGTH];
} stack;

stack *newStack();
void push(stack *s, char element);
char pop(stack *s);

int ehBemFormado(char texto[], stack *s);
int isStackFull(stack *s);
int isStackEmpty(stack *s);

int main() {
    setlocale(LC_ALL, "");

    char texto[] = "([])[]";
    stack *s = newStack();

	if (ehBemFormado(texto, s) == 1) {
		printf("Sequencia é bem formada!\n");
	} else {
		printf("Sequencia não é bem formada!\n");
	}

    return 0;
}

stack *newStack() {
    stack *ptr = (stack *)malloc(sizeof(stack));
    ptr->top = 0;

    return ptr;
}

void push(stack *s, char element) {
    if(isStackFull(s)) {
        printf("A pilha está cheia no momento. Tente novamente!\n"); //Stack Overflow
        exit(1);
    }

    s->data[s->top] = element;
    s->top++;
}

char pop(stack *s) {
    if(isStackEmpty(s)) {
        printf("A pilha está vazia no momento. Tente novamente!\n"); //Stack Underflow
        exit(1);
    }

    s->top--;
    return s->data[s->top];
}

int ehBemFormado(char texto[], stack *s) {
	int i;
	char atual;

	for (i=0; i<strlen(texto); i++) {
		if (texto[i] == '(' || texto[i] == '[') {
			push(s, texto[i]);
		} else if (texto[i] == ')' || texto[i] == ']') {
			if (isStackEmpty(s)) {
				return 0;
			}
			atual = pop(s);
			if (texto[i] == ')' && atual != '(') {
				return 0;
			} else if (texto[i] == ']' && atual != '[') {
				return 0;
			}
		} else {
			return 0;
		}
	}

	if (isStackEmpty(s)) {
		return 1;
	} else {
		return 0;
	}
}

int isStackFull(stack *s) {
    return s->top == LENGTH;
}

int isStackEmpty(stack *s) {
    return s->top == 0;
}
