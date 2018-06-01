#include "stack.h"

#define STEP 5
#define LIMIT 50

struct Stack {
    int top;
    unsigned capacity;
    double *data;
};

struct Stack *createStack() {

    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));

    stack->top = -1;
    stack->capacity = STEP;

    stack->data = (double *) malloc(stack->capacity * sizeof(double));

    return stack;
}

void destruct(struct Stack *stack) {
    for (int i = stack->capacity; i >= 0; i--)
        stack->data[i] = 0;

    stack->data = (double *) malloc(STEP * sizeof(double));
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int push(struct Stack *stack, double value) {
    if (stack->top - 1 == LIMIT) return 1;
    if (stack->top == (stack->capacity) - 1) {
        stack->data = (double *) realloc(stack->data, (stack->capacity + STEP) * sizeof(double));
        stack->capacity += STEP;
    }
    stack->data[++(stack->top)] = value;
    return 0;
}

double pop(struct Stack *stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->data[stack->top--];
}
