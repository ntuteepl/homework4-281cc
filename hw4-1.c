#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int i, j, n, k;
int l;

int is_prime(int);

int main(int argc, char *argv[]) {
    scanf("%d", &l);
    int number[l];

    for (j = 0; j < l; j++) {
        scanf("%d", &number[j]);
    }

    for (k = 0; k < l; k++) {
        n = number[k];

        if (is_prime(n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

int is_prime(int n) {
    if (n == 1 || n == 0) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        for (i = 2; i < n; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
    }
    return 1;
}
