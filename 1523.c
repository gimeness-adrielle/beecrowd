#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
} Node;

Node *create_node (int value){
    Node *new = (Node*) malloc (sizeof(Node));
    if (!new)
        exit (1);
    new->value = value;
    new->next = NULL;
    return new;
}

typedef struct stack{
    Node *top;
    int size;
} Stack;

Stack *create_stack (){
    Stack *s = (Stack*) malloc (sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push (Stack *s, int value){
    Node *new = create_node(value);
    new->next = s->top;
    s->top = new;
    s->size++;
}

void pop (Stack *s){
    if (s->top){
        Node *aux = s->top;
        s->top = s->top->next;
        free(aux);
        s->size--;
    }
}

int top(Stack *s) {
    if (s->top)
        return s->top->value;
    return -1;
}

void free_stack(Stack *s) {
    while (s->top) {
        pop(s);
    }
    free(s);
}

int main (){
    int N, K;
    while (1){
        scanf ("%d %d", &N, &K);
        if (N == 0 && K == 0)
            break;

        Stack *s = create_stack();
        int pode_estacionar = 1;

        for (int i = 0; i<N; i++){
            int C, S;
            scanf("%d %d", &C, &S);

            while (s->top && top(s) <= C)
                pop(s);

            if (s->size >= K)
                pode_estacionar = 0;
            else {
                if (s->top == NULL)
                    push(s, S);
                else 
                    if (top(s) > S)
                        push (s, S);
                    else
                        pode_estacionar = 0;
            }
        }
        if (pode_estacionar == 1)
            printf ("Sim\n");
        else
            printf("Nao\n");

        free_stack(s);
    }
    
    return 0;
}