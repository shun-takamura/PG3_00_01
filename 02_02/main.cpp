#include <iostream>
using namespace std;

// 一般的な賃金体系
int normalPay(int hours) {
    const int hourly = 1226;
    return hourly * hours;
}

// 再帰的な賃金体系（再帰関数）
int recursiveWage(int hour) {
    if (hour == 1) return 100;               // 最初の1時間は100円
    return recursiveWage(hour - 1) * 2 - 50; // 「前の時給 × 2 - 50」
}

// 再帰的な賃金体系の合計額（累積）
int recursiveTotal(int hours) {
    if (hours == 1) return 100; // 1時間分の給料
    return recursiveTotal(hours - 1) + recursiveWage(hours);
}

int main() {

    int crossoverHour = -1; // 逆転した時間
    for (int h = 1; h <= 20; ++h) { // 20時間まで計算
        int normal = normalPay(h);
        int recursive = recursiveTotal(h);
        cout << h << "時間\t" << normal << "円\t\t" << recursive << "円\n";

        if (recursive > normal && crossoverHour == -1) {
            crossoverHour = h;
        }
    }

    return 0;
}