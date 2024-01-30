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

int main() {
	char texto[] = "Socorram-me subi no onibus em Marrocos";
	stack *p = newStack();
	int i;
	for (i=0;i<strlen(texto);i++) {
		push(p, texto[i]);
	}
	while(!isStackEmpty(p)) {
		printf("%c", pop(p));
	}
	printf("\nTotal de elementos: %d\n", total(p));
	
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
