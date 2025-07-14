#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char base;
    struct node *next;
} Node;

Node *create_node (char base){
    Node *new = (Node*)malloc(sizeof(Node));
    if (!new)
        exit (1);
    new->next = NULL;
    new->base = base;
    return new;
}

typedef struct stack{
    Node *top;
} Stack;

Stack *create_stack (){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push (Stack *s, char base){
    Node *new = create_node (base);
    new->next = s->top;
    s->top = new;
}

void pop (Stack *s){
    if (!s->top)
        return;
    Node *aux = s->top;
    s->top = s->top->next;
    free (aux);
}

void string_split (Stack *s, char *tira_RNNA, int *count){
    int i = 0;
    while (tira_RNNA[i] != '\0'){
        if (!s->top)
            push (s, tira_RNNA[i]);
        else {
            if (tira_RNNA[i] == 'B' && s->top->base == 'S' || tira_RNNA[i] == 'S' && s->top->base == 'B'){
                pop(s);
                (*count)++;
            }
            else if (tira_RNNA[i] == 'C' && s->top->base == 'F' || tira_RNNA[i] == 'F' && s->top->base == 'C'){
                pop (s);
                (*count)++;
            }
            else 
                push (s, tira_RNNA[i]);
        }
        i++;
    }
}

void free_stack (Stack *s){
    while (s->top){
        pop(s);
    }
}

int main (){
    char tira_RNNA[300];

    while (scanf("%s", tira_RNNA) != EOF){
        int count = 0;
        Stack *s = create_stack();
        string_split (s, tira_RNNA, &count);

        printf ("%d\n", count);
        free_stack(s);
    }

    return 0;
}