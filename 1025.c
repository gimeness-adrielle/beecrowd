#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

void free_queue (Node **priorityQueue){
    Node *aux;
    while (*priorityQueue){
        aux = *priorityQueue;
        *priorityQueue = (*priorityQueue)->next;
        free (aux);
    }
}

Node *create_node (int value){
    Node *new = (Node*)malloc(sizeof(Node));
    if (!new)
        exit (1);
    
    new->value = value;
    return new;
}

void push (Node** priorityQueue, int value){
    Node *new = create_node (value);
    if (!(*priorityQueue) || value < (*priorityQueue)->value){
        new->next = *priorityQueue;
        *priorityQueue = new;
    } else{
        Node *aux = *priorityQueue;
        while (aux->next && aux->next->value <= value)
            aux = aux->next;
        new->next = aux->next;
        aux->next = new;
    }
}

int search (Node *priorityQueue, int seek_value){
    Node *aux = priorityQueue;
    int index = 1;
    while (aux && aux->value != seek_value){
        aux = aux->next;
        index++;
    }
    if (aux && aux->value == seek_value)
        return index;
    
    return 0;
}

int main (){
    Node *priorityQueue = NULL;
    int n, q;
    int count = 1;

    while(1){
        scanf ("%d %d", &n, &q);
        if (n == 0 && q == 0)
            break;
        printf ("CASE# %d:\n", count++);

        for (int i = 0; i<n; i++){
            int marble;
            scanf ("%d", &marble);
            push (&priorityQueue, marble);
        }
        for (int i = 0; i<q; i++){
            int seek_value;
            scanf("%d", &seek_value);

            int index = search (priorityQueue, seek_value);

            if (index == 0){
                printf ("%d not found\n", seek_value);
            }else{
                printf ("%d found at %d\n", seek_value, index);
            }
        }
        priorityQueue = NULL;
    }

    return 0;
}