// NOTE: must include this header first
#include <rlutil.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, rez;
    int *v;

    printf("n: ");
    rez = scanf("%d", &n);
    if(rez != 1) {
        puts("Eroare citire n");
        return 1;
    }

    v = malloc(sizeof(*v) * n);
    if(v == NULL) {
        puts("Eroare malloc");
        return 1;
    }

    printf("Citire v: ");
    for(int i = 0; i < n; i++) {
        rez = scanf("%d", &v[i]);
        if(rez != 1) {
            printf("Eroare citire v[%d]\n", i);
            free(v);
            return 1;
        }
    }

    puts("Am citit:");
    for(int i = 0; i < n; i++)
        printf("v[%d]: %d\n", i, v[i]);

    free(v);
    cls();

    return 0;
}
