#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // Sleep()を使うため

// 判定関数
void ShowResult(int roll, int userGuess) {
    printf("出目は %d でした。\n", roll);
    int result = roll % 2; // 奇数=1, 偶数=0

    if (result == userGuess) {
        printf("正解\n");
    } else {
        printf("不正解\n");
    }
}

// 遅延実行関数
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
    printf("サイコロを振っています...\n");
    Sleep(delayMs);
    fn(roll, userGuess);
}

// メイン関数
int main(void) {
    srand((unsigned)time(NULL));

    int userGuess;
    printf("奇数（半）=1, 偶数（丁）=0 を入力してください: ");
    scanf_s("%d", &userGuess);

    int roll = rand() % 6 + 1;

    DelayReveal(ShowResult, 3000, roll, userGuess);

    return 0;
}
