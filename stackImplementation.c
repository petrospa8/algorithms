#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

void CreateStack(STACK *S){
  S->top = -1;
}

int EmptyStack(stack S){
  return (S.top == -1);
}

void Push(ElementType) x, stack *S){
  if(++S->top == MaxStackSize){
    printf("error: Full stack\n");
    exit(EXIT_FAILURE);
  }
  s->array[S->top] = x;
}

ElementType Top(stack S){
  if (EmptyStack(S)){
    printf("error: Full stack\n");
    exit(EXIT_FAILURE);
  }
  return S.array[S.top];
}

void Pop(stack *S){
  if (EmptyStack(S)){
    printf("error: Full stack\n");
    exit(EXIT_FAILURE);
  }
  S->top--;
}
