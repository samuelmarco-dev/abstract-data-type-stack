#include <stdio.h>
#include <stdlib.h>

#define N 30

typedef struct {
  int top;
  int data[N];
} stack;

stack *newStack();
void push(stack *s, int value);
int pop(stack *s);
int top(stack *s);
int isStackEmpty(stack *s);
int isStackFull(stack *s);

int main() {
  stack *p;
  p = newStack();
  push(p, 15);
  push(p, 25);
  printf("Topo: %d\n", pop(p));
  if (isStackEmpty(p)) {
    printf("Pilha se encontra vazia!\n");
  }
  if (!isStackFull(p)) {
    printf("Pilha nao se encontra cheia!\n");
  }

}

stack *newStack() {
  stack *p = (stack *)malloc(sizeof(stack));
  p->top = 0;
  return p;
}

void push(stack *s, int value) {
  if (isStackFull(s)) {
    printf("Stack overflow!!!\n");
    return;
  }
  s->data[s->top] = value;
  s->top++;
}

int pop(stack *s) {
  if (isStackEmpty(s)) {
    printf("Stack underflow!!!\n");
    return -1;
  }
  s->top = s->top - 1;
  return s->data[s->top];
}

int top(stack *s) {
  if (isStackEmpty(s)) {
    printf("Stack underflow!!!\n");
    return -1;
  }
  return s->data[s->top - 1];
}

int isStackEmpty(stack *s) {
  return s->top == 0;
}

int isStackFull(stack *s) {
  return s->top == N;
}
