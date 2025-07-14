#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int element;
    struct node *next;
} Node;

typedef struct queue{
    Node *first;
    Node *last;
} Queue;

Node* create_node (int element){
    Node *new = (Node*) malloc (sizeof(Node));
    if (!new)
        exit (1);
    new->element = element;
    new->next = NULL;
    return new;
}

void push (Queue *q, int element){
    Node *new = create_node (element);
    if (!(q->first)){
        q->first = new;
        q->last = new;
    }else{
        q->last->next = new;
        q->last = new;
    }
}

int discard_cards (Queue *q){
    int remaining;
    int discarded;

    if ((q->first) && q->first == q->last){
        remaining = q->first->element;
        return remaining;
    }else{
        Node *aux = q->first;
        q->first = q->first->next;
        discarded = aux->element;

        aux = q->first;
        q->last->next = q->first;
        q->last = q->first;
        aux = q->first->next;
        q->first = aux;
        q->last->next = NULL;
    }
    return discarded;
}

void init (Queue *q, int N){
    q->first = q->last = NULL;
    for (int i = 0; i<N; i++){
        push (q, i+1);
    }
}

void freeQueue (Queue *q){
    Node *aux;
    while (q->first){
        aux = q->first;
        q->first = q->first->next;
        free (aux);
    }
}

int main (){
    int N, index=1;
    while (scanf ("%d", &N) && N > 0 && N <= 50){
        Queue q;
        init (&q, N);

        printf ("Discarded cards: ");
        for (int i = 0; i<N-2; i++){
            int discarded = discard_cards (&q);
            printf ("%d, ", discarded);
        }
        int discarded = discard_cards (&q);
        printf ("%d\n", discarded);

        int remaining =  discard_cards(&q);
        printf ("Remaining card: %d\n", remaining);

        freeQueue (&q);
    }
    
    return 0;
}