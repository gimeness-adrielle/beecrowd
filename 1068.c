#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char c;
    struct node *next;
} Node;

Node *create_node (char c){
    Node *new = (Node*)malloc(sizeof(Node));
    if (!new)
        exit (1);
    new->next = NULL;
    new->c = c;
    return new;
}

typedef struct stack {
    Node *top;
    int count;
} Stack;

Stack *create_stack (){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    s->count = 0;
    return s;
}

int isEmpty (Stack *s){
    return (s->top == NULL);
}

void push (Stack *s, char c){
    Node *new = create_node(c);
    new->next = s->top;
    s->top = new;
    s->count++;
}

void pop (Stack *s, int *correct){
    if (isEmpty(s)){
        *correct = 0;
        return;
    }
    
    Node *aux = s->top;
    s->top = s->top->next;
    s->count--;
    free(aux);
}

void free_stack (Stack *s){
    Node *aux;
    while (s->top){
        aux = s->top;
        s->top = s->top->next;
        free (aux);
    }
}

void string_div (Stack *s, char *expression, int *correct){
    int i = 0;
    while (expression[i] != '\0'){
        if (expression[i] == '(')
            push (s, expression[i]);
        else if (expression[i] == ')'){
            pop (s, correct);
        }
        i++;
    }
}

int main (){
    char expression [1001];

    while (scanf("%1001s", expression) != EOF){
        int correct = 1;
        Stack *s = create_stack();
        string_div (s, expression, &correct);
        if (s->count > 0 || correct == 0) 
            printf ("incorrect\n");
        else
            printf ("correct\n");
        free_stack (s);
    }

    return 0;
}