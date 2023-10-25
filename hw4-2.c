#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    int n[6][3] = {{123, 456, 9000}, {456, 789, 5000}, {789, 888, 6000}, {336, 558, 10000}, {775, 666, 12000}, {566, 221, 7000}};
    int l,i,j,k,a;
    scanf("%d", &l);
    int number[l][2];

    for (j = 0; j < l; j++) {
        for (i = 0; i < 2; i++) {
            scanf("%d", &number[j][i]);
        }
    }

    for (int j = 0; j < l; j++) {
        int found = 0;
        for (int k = 0; k < 6; k++) {
            if (number[j][0] == n[k][0] && number[j][1] == n[k][1]) {
                printf("%d\n", n[k][2]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("error\n");
        }
    }

    return 0;
}
