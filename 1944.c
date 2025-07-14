#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sequence {
    char *string;
    struct sequence *next;
} Sequence;

Sequence *create_sequence(char *string) {
    Sequence *new_sequence = (Sequence*)malloc(sizeof(Sequence));
    if (!new_sequence)
        exit(1);

    new_sequence->string = strdup(string);
    new_sequence->next = NULL;
    return new_sequence;
}

typedef struct stack {
    Sequence *top;
    int count;
} Stack;

Stack *create_stack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    s->count = 0;
    return s;
}

void push(Stack *s, char *string) {
    Sequence *new_sequence = create_sequence(string);
    new_sequence->next = s->top;
    s->top = new_sequence;
    s->count++;
}

void pop(Stack *s) {
    if (!s->top)
        return;
    Sequence *aux = s->top;
    s->top = s->top->next;
    s->count--;
    free(aux->string);
    free(aux);
}

void free_stack(Stack *s) {
    while (s->top)
        pop(s);
    free(s);
}

int is_reverse(char *str1, char *str2) {
    for (int i = 0; i < 4; i++) {
        if (str1[i] != str2[3 - i])
            return 0;
    }
    return 1;
}

int main() {
    int N, gifts = 0;
    char string[5];
    Stack *s = create_stack();

    push(s, "FACE");

    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        scanf("%c %c %c %c", &string[0], &string[1], &string[2], &string[3]);
        getchar();

        string[4] = '\0';

        if (s->count > 0 && is_reverse(string, s->top->string)) {
            pop(s);
            gifts++;

            if (s->count == 0)
                push(s, "FACE");
        } else {
            push(s, string);
        }
    }

    printf("%d\n", gifts);
    free_stack(s);

    return 0;
}
