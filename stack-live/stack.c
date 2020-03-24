#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

// Structure defining a stack
struct stack
{
  int elements[100];
  int top;
  int size;
};

// Creating and initializing a new stack
struct stack* new_stack()
{
  struct stack* st = (struct stack*) malloc(sizeof(struct stack));
  st->top = -1;
  st->size = 0;
  return st;
}

// Push the element i on the stack st
void push(struct stack* st, int i)
{
  st->top++;
  st->size++;
  st->elements[st->top] = i;
}

// Pop the top element from the stack
int pop(struct stack* st)
{
  int element = top(st);
  st->top--;
  st->size--;
  return element;
}

// Access the top element of stack st
int top(struct stack* st)
{
  if(is_empty(st))
  {
    printf("Error: stack is empty\n");
    exit(EXIT_FAILURE);
  }
  return st->elements[st->top];
}

// Returns the size of stack st
int size(struct stack* st)
{
  return st->size;
}

// Checks if the stack st is empty
int is_empty(struct stack* st)
{
  return size(st) == 0;
}

// Removes all elements from the stack st
void empty(struct stack* st)
{
  while(!is_empty(st))
  {
    pop(st);
  }
}

int main()
{
  struct stack* st = new_stack();

  int i;
  for (i=0; i<=10; i++)
  {
    push(st, i);
  }

  int size_stack = size(st);
  int top_stack = top(st);

  printf("Top stack = %d\n", top_stack);
  printf("Size stack = %d\n", size_stack);

  while(!is_empty(st))
  {
    int element = pop(st);
    printf("Pop: %d\n", element);
  }

  printf("Is stack empty? %d\n", is_empty(st));

}
