#include <stdio.h>

typedef struct time{
    int hour, min;
}Time;

int main (){
    Time start, end;
    int min=0, hrs;

    scanf ("%d %d %d %d", &start.hour, &start.min, &end.hour, &end.min);
    int start_total = start.hour * 60 + start.min;
    int end_total = end.hour * 60 + end.min;

    min = end_total - start_total;
    if(end_total <= start_total)
        min += (24 * 60);
    
    hrs = min / 60;
    min %= 60;

    printf ("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hrs, min);
    return 0;
}