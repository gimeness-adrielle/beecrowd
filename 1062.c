#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top, size;
    int *vagoes;
} Stack;

Stack* create_stack(int size) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = 0;
    stack->vagoes = (int*)malloc(size * sizeof(int));
    return stack;
}

int isEmpty(Stack *stack) {
    return stack->top == 0;
}

int isFull(Stack *stack) {
    return stack->top == stack->size;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) 
        return;
    stack->vagoes[stack->top++] = value;
}

void pop(Stack *stack) {
    if (isEmpty(stack)) 
        return;
    stack->top--;
}

int top(Stack *stack) {
    return stack->vagoes[stack->top - 1];
}

void freeStack(Stack *stack) {
    free(stack->vagoes);
    free(stack);
}

void compare(Stack *stack_A, Stack *estacao, int *saida, int n) {
    int index = 0;

    while (!isEmpty(stack_A) || !isEmpty(estacao)) {
        if (!isEmpty(estacao) && top(estacao) == saida[index]) {
            pop(estacao);
            index++;
        } else if (!isEmpty(stack_A) && top(stack_A) == saida[index]) {
            pop(stack_A);
            index++;
        } else if (!isEmpty(stack_A)) {
            push(estacao, top(stack_A));
            pop(stack_A);
        } else 
            break;
    }

    if (index == n)
        printf("Yes\n");
    else
        printf("No\n");
}

void init(Stack *stack_A, int size) {
    for (int i = size; i > 0; i--)
        push(stack_A, i);
}

int main() {
    int size;

    while (scanf("%d", &size) && size != 0) {
        while (1) {
            Stack *stack_A = create_stack(size);
            Stack *estacao = create_stack(size);
            int *saida = (int*)malloc(size * sizeof(int));

            init(stack_A, size);

            int first;
            scanf("%d", &first);
            if (first == 0) {
                freeStack(stack_A);
                freeStack(estacao);
                free(saida);
                break;
            }
            saida[0] = first;

            for (int i = 1; i < size; i++) {
                scanf("%d", &saida[i]);
            }

            compare(stack_A, estacao, saida, size);

            freeStack(stack_A);
            freeStack(estacao);
            free(saida);
        }

        printf("\n");
    }

    return 0;
}
