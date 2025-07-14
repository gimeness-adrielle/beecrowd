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

typedef struct queue{
    Node *first, *last;
    int sum;
} Queue;

Queue* create_queue (){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->first = q->last = NULL;
    q->sum = 0;
    return q;
}

void push (Queue *q, int value){
    Node *new = create_node(value);
    if (q->last == NULL){
        q->first = new;
        q->last = new;
    } else{
        q->last->next = new;
        q->last = new;
    }
    q->sum += value;
}

void pop (Queue *q){
    if (!q->first)
        return;
    Node *aux = q->first;
    q->first = q->first->next;
    q->sum -= aux->value;
    free(aux);
}

int main (){
    Queue *q = create_queue ();
    int N, M, D, days = 0;
    scanf ("%d %d", &N, &M);

    for (int i = 0; i<30; i++){
        scanf ("%d", &D);
        push (q, D);
    }
    while (N < M){
        int media = (q->sum + 29) / 30;
        N += media;
        pop (q);
        push(q, media);
        days++;
    }
    printf ("%d\n", days);

    return 0;
}