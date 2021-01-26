#ifndef MaxStackSize
#define MaxStackSize 10
#endif

typedef int ElementType;
typedef struct {
  int top;
  ElementType array[MaxStackSize];
} stack;

  void CreateStack(staxk *);
  int EmptyStack(stack);
