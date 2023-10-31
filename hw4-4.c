#include <stdio.h>

    int main() {
    int n;
    scanf("%d", &n);
    int number[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &number[i][j]);
        }
    }
    int last_max_i = -1; // 上一輪的max_i
    int last_max_j = -1; // 上一輪的max_j

    for (int k = 0; k < n; k++) {
        int max = number[0][0];
        int max_i = 0;
        int max_j = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (number[i][j] > max) {
                    max = number[i][j];
                    max_i = i + 1;
                    max_j = j + 1;
                }
            }
        }
        if ((last_max_i == max_i) || (last_max_j == max_j)) {
            printf("boy %d pair with girl %d\n", max_i, max_j);
        }
        else {
            printf("boy %d pair with girl %d\n", max_i, max_j);
        }
        last_max_i = max_i;
        last_max_j = max_j;

        number[max_i - 1][max_j - 1] = -1; // 將最大值設為-1，以便下一輪尋找第二大的值
    }
    return 0;
}
