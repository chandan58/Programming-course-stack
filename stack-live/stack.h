// Creating and initializing a new stack
struct stack* new_stack();

// Push the element i on the stack st
void push(struct stack* st, int i);

// Pop the top element from the stack st
int pop(struct stack* st);

// Access the top element of stack st
int top(struct stack* st);

// Returns the size of stack st
int size(struct stack* st);

// Checks if the stack st is empty
int is_empty(struct stack* st);

// Removes all elements from the stack st
void empty(struct stack* st);
