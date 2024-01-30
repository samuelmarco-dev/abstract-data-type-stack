#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct {
	int topo;
	char dados[N];
} stack;

stack *newStack();
void push(stack *s, char value);
char pop(stack *s);
char top(stack *s);
int isStackEmpty(stack *s);
int isStackFull(stack *s);

int valida(char texto[]);

int main() {
	char sequencia[] = ")()[()])";
	char mina[] = "<<<..<......<<<<....>";
	
	if (valida(sequencia)) {
		printf("%s - Sequencia bem formada\n", sequencia);
	} else {
		printf("%s - Sequencia mal formada!\n", sequencia);
	}
	
	printf("\n%s - %d diamantes\n", mina, diamantes(mina));
	
}

int diamantes(char texto[]) {
	int i, qtd = 0;
	stack *s = newStack();
	
	for (i=0; i<strlen(texto); i++) {
		if (texto[i] == '<') {
			push(s, texto[i]);
		} else if (texto[i] == '>') {
			if (!isStackEmpty(s)) {
				pop(s);
				qtd++;
			}
		}
	}
	
	return qtd;
}

int valida(char texto[]) {
	int i;
	stack *s = newStack();
	
	for (i=0; i<strlen(texto); i++) {
		if (texto[i] == '[' || texto[i] == '(') {
			push(s, texto[i]);
		} else if (texto[i] == ')') {
			if (isStackEmpty(s) || pop(s) != '(') return 0;
		} else if (texto[i] == ']') {
			if (isStackEmpty(s) || pop(s) != '[') return 0;
		} else {
			return 0;
		}
	}
	
	if (isStackEmpty(s)) return 1;
	else return 0;
}

stack *newStack() {
	stack *s = (stack *) malloc(sizeof(stack));
	s->topo = 0;
	return s;
}

void push(stack *s, char value) {
	//Testar se a pilha esta cheia
	if (isStackFull(s)) {
		printf("PILHA CHEIA - Stack Overflow");
		return;
	}
	s->dados[s->topo] = value;
	s->topo++;
}

char pop(stack *s) {
	// Testar se a pilha esta vazia
	if (isStackEmpty(s)) {
		printf("Pilha vazi! Stack Underflow");
		return '\0';
	}
	s->topo--;
	return s->dados[s->topo];
}

char top(stack *s) {
	//Testar se a pilha esta vazia
	if (isStackEmpty(s)) {
		printf("Pilha vazi! Stack Underflow");
		return '\0';
	}
	return s->dados[s->topo - 1];
}

int isStackEmpty(stack *s) {
	return s->topo == 0;
}

int isStackFull(stack *s) {
	return s->topo == N;
}
