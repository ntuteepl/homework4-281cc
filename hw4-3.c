#include <stdio.h>

// 檢查是否需要新的車輛
int checkOverlap(int s[], int d[], int n) {
    int count = 1;
    int currentEnd = d[0];  // 第一筆訂單的返回時間

    // 檢查每一筆訂單
    for (int i = 1; i < n; i++) {
        // 如果下一筆訂單的發車時間早於當前訂單的返回時間，則需要一輛新車
        if (s[i] < currentEnd) {
            count++;
        } else {
            // 更新當前的返回時間
            currentEnd = d[i];
        }
    }
    return count;
}

// 將車輛時間表輸出
void printSchedule(int s[], int d[], int n) {
    int currentEnd = d[0];  // 第一筆訂單的返回時間
    int driverCount = 1;

    // 輸出第一位司機的時間表
    printf("Driver %d's schedule is %d %d", driverCount, s[0], d[0]);

    // 檢查每一筆訂單
    for (int i = 1; i < n; i++) {
        // 如果下一筆訂單的發車時間早於當前訂單的返回時間，則可以再次出發
        if (s[i] > currentEnd) {
            printf("%d %d", s[i], d[i]);
        } else {
            // 輸出新的司機時間表
            driverCount++;
            printf("\nDriver %d's schedule is %d %d", driverCount, s[i], d[i]);
        }
        // 更新當前的返回時間
        if (d[i] > currentEnd) {
            currentEnd = d[i];
        }
    }
    printf("\n");
}

int main() {
    // 初始化陣列
    int s[3];
    int d[3];

    // 輸入訂單數量和訂單資訊
    int n = 3;
    printf("請輸入每筆訂單的出發時間和返回時間：\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &s[i], &d[i]);
    }

    // 呼叫函式計算車輛需求
    int result = checkOverlap(s, d, n);
    printf("%d\n", result);

    // 印出每位司機的時間表
    printSchedule(s, d, n);

    return 0;
}
