#include <stdio.h>

int main (){
    // Using the idea of hashing
    int mark_exits[100010] = {0}; // double the maximum value (50000)
    int N, M;

    scanf ("%d", &N);
    int queue[N];

    for (int i=0; i<N; i++)
        scanf ("%d", &queue[i]);
    
    // Mark the exits in a hash map
    scanf ("%d", &M);
    for (int i=0; i<M; i++){
        int id;
        scanf ("%d", &id);
        mark_exits[id] = 1;
    }

    // If the id hasn´t exit in the array 'mark_exits', print it
    int first = 1; // just to get the right answer (presentation error)
    for (int i = 0; i < N; i++) {
        if (!mark_exits[queue[i]]) {
            if (!first) {
                printf(" ");
            }
            printf("%d", queue[i]);
            first = 0;
        }
    }
    printf("\n");

    return 0;
}