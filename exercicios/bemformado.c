#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct {
	int qtd;
	int top;
	char lista[N];
} stack;

stack *newStack();
int isStackEmpty(stack *s);
int isStackFull(stack *s);
void push(stack *s, char value);
char pop(stack *s);
char top(stack *s);
int total(stack *s);

int ehBemFormado(char texto[]);

int main() {
	char texto[] = "([])[]";
	if (ehBemFormado(texto) == 1) {
		printf("Sequencia eh bem formada!\n");
	} else {
		printf("Sequencia nao eh bem formada!\n");
	}
}

int ehBemFormado(char texto[]) {
	int i;
	char atual;
	stack *s = newStack();
	
	for (i = 0; i<strlen(texto); i++) {
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

stack *newStack() {
	stack *s = (stack *)malloc(sizeof(stack));
	s->top = 0;
	s->qtd = 0;
	return s;
}

int isStackEmpty(stack *s) {
	if (s->top == 0)
	    return 1;
	return 0;
}

int isStackFull(stack *s) {
	if (s->top == N)
	    return 1; 
	else
		return 0;
}

void push(stack *s, char value) {
	if (isStackFull(s) == 1) {
		printf("Pilha cheia!\n");
	} else {
		s->lista[s->top] = value;
		s->top++;
		s->qtd++;
	}
}

char pop(stack *s) {
	if (isStackEmpty(s) == 1) {
		printf("Pilha vazia!\n");
		return '\0';
	} else {
		s->top--;
		return s->lista[s->top];
	}
}

char top(stack *s) {
	if (isStackEmpty(s) == 1) {
		printf("Pilha vazia!\n");
		return '\0';
	} else {
		return s->lista[s->top - 1];
	}
}

int total(stack *s) {
	return s->qtd;
}
