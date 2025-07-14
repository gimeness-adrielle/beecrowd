#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Node
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

// Stack
typedef struct stack{
    Node *top;
} Stack;

Stack* create_stack (){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push_stack (Stack *s, int value){
    Node *new = create_node(value);
    new->next = s->top;
    s->top = new;
}

bool pop_stack(Stack* s, int x) {
    Node* aux = s->top;
    if (!s->top || aux->value != x) 
        return false;
    
    s->top = s->top->next;
    free(aux);
    return true;
}

void free_stack(Stack *s) {
    Node *tmp;
    while (s->top != NULL) {
        tmp = s->top;
        s->top = s->top->next;
        free(tmp);
    }
}

// Queue
typedef struct queue{
    Node *first;
    Node *last;
} Queue;

Queue* create_queue (){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->first = q->last = NULL;
    return q;
}

void push_queue (Queue *q, int value){
    Node *new = create_node(value);
    if (q->last == NULL){
        q->first = new;
        q->last = new;
    } else{
        q->last->next = new;
        q->last = new;
    }
}

bool pop_queue(Queue* q, int x) {
    Node* aux = q->first;
    if (!q->first || aux->value != x) 
        return false;
    
    q->first = q->first->next;
    if (!q->first) 
        q->last = NULL;
    free(aux);
    return true;
}

void free_queue(Queue *q) {
    Node *tmp;
    while (q->first != NULL) {
        tmp = q->first;
        q->first = q->first->next;
        free(tmp);
    }
    q->last = NULL;
}

// Priority Queue
int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main (){
    int n;
    while (scanf ("%d", &n) != EOF){
        Stack *s = create_stack ();
        Queue *q = create_queue ();
        int priority_queue[1001];
        int pq_size = 0;

        bool is_stack = true, is_queue = true, is_pq = true;

        for (int i = 0; i<n; i++){
            int cmd, x;
            scanf ("%d %d", &cmd, &x); 
            if (cmd == 1){
                if (is_stack) 
                    push_stack(s, x);
                if (is_queue) 
                    push_queue(q, x);
                if (is_pq){
                    priority_queue[pq_size++] = x;
                    qsort(priority_queue, pq_size, sizeof(int), cmp);
                }
            } else{
                if (is_stack && !pop_stack(s, x)) 
                    is_stack = false;
                if (is_queue && !pop_queue(q, x)) 
                    is_queue = false;
                if (is_pq) {
                    if (pq_size == 0 || priority_queue[0] != x) {
                        is_pq = false;
                    } else {
                        for (int j = 1; j < pq_size; j++) {
                            priority_queue[j - 1] = priority_queue[j];
                        }
                        pq_size--;
                    }
                }
            }
        }
        if (is_stack + is_queue + is_pq > 1)
            printf("not sure\n");
        else if (is_stack)
            printf("stack\n");
        else if (is_queue)
            printf("queue\n");
        else if (is_pq)
            printf("priority queue\n");
        else
            printf("impossible\n");
        
        free_stack (s);
        free_queue (q);
    }

    return 0;
}