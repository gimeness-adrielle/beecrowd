#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char c;
    struct node *next;
} Node;

typedef struct stack{
    Node *top;
    int count;
} Stack;

Node *create_node (char c){
    Node *new = (Node*) malloc (sizeof(Node));
    if (!new)
        exit (1);
    new->next = NULL;
    new->c = c;
    return new;
}

Stack *create_stack (){
    Stack *s = (Stack*) malloc (sizeof(Stack));
    s->top = NULL;
    s->count = 0;
    return s;
}

int isEmpty (Stack *s){
    return (s->top == NULL);
}

void push (Stack **s, char c){
    Node *new = create_node(c);
    new->next = (*s)->top;
    (*s)->top = new;
    (*s)->count++;
}

void pop (Stack **s){
    if (!isEmpty(*s)){
        Node *aux = (*s)->top;
        (*s)->top = (*s)->top->next;
        (*s)->count--;
        free(aux);
    }
}

void free_stack (Stack **s){
    Node *aux;
    while ((*s)->top){
        aux = (*s)->top;
        (*s)->top = (*s)->top->next;
        free (aux);
    }
}

void string_div (Stack **s, char string[1001], int *diamonds){
    int i = 0;
    while (string[i] != '\0'){
        if (string[i] == '<')
            push (s, string[i]);
        else if (string[i] == '>'){
            if ((*s)->count > 0){
                pop (s);
                (*diamonds)++;
            }
        }
        i++;
    }
}

int main (){
    Stack *s = create_stack();
    int n;
    char entrada[1001];

    scanf ("%d", &n);
    for (int i=0; i<n; i++){
        int diamonds = 0;
        scanf ("%s", entrada);
        getchar();
        string_div(&s, entrada, &diamonds);
        printf ("%d\n", diamonds);
        free_stack(&s);
        s->count = 0;
        s->top = NULL;
    }
    
    return 0;
}