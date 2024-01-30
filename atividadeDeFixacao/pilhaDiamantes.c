#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

typedef struct {
	int topo;
	char dados[N];
} stack;

stack *newStack();
void push(stack *s, char value);
char pop(stack *s);
char top(stack *s);

int diamantes(char texto[], stack *s);
int isStackEmpty(stack *s);
int isStackFull(stack *s);

int main() {
	char mina[] = "<<<..<......<<<<....>>";
	stack *s = newStack();
	printf("%s: %d diamante(s)\n", mina, diamantes(mina, s));

    return 0;
}

int diamantes(char texto[], stack *s) {
	int i, qtd = 0;
	char remove;

	for (i=0; i<strlen(texto); i++) {
		if (texto[i] == '<') {
			push(s, texto[i]);
		} else if (texto[i] == '>') {
			if (!isStackEmpty(s)) {
				remove = pop(s);
				if(remove != '<') return 0;
				else qtd++;
			}
		}
	}

	return qtd;
}

stack *newStack() {
	stack *s = (stack *) malloc(sizeof(stack));
	s->topo = 0;

	return s;
}

void push(stack *s, char value) {
	if (isStackFull(s)) {
		printf("Pilha cheia - Stack Overflow");
		exit(1);
	}

	s->dados[s->topo] = value;
	s->topo++;
}

char pop(stack *s) {
	if (isStackEmpty(s)) {
		printf("Pilha vazia - Stack Underflow");
		exit(1);
	}

	s->topo--;
	return s->dados[s->topo];
}

char top(stack *s) {
	if (isStackEmpty(s)) {
		printf("Pilha vazia - Stack Underflow");
		return;
	}
	
	return s->dados[s->topo - 1];
}

int isStackEmpty(stack *s) {
	return s->topo == 0;
}

int isStackFull(stack *s) {
	return s->topo == N;
}
