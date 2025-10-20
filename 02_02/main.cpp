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
    while (true) {
        int h;
        cout << "\n働いた時間を入力（終了するには 0 を入力）: ";
        cin >> h;

        if (h <= 0) {
            cout << "終了\n";
            break;
        }

        int normal = normalPay(h);
        int recursive = recursiveTotal(h);

        cout << "【一般的な賃金体系】 " << normal << "円\n";
        cout << "【再帰的な賃金体系】 " << recursive << "円\n";

        if (recursive > normal)
            cout << "再帰的な賃金体系のほうが得\n";
        else if (recursive < normal)
            cout << "一般的な賃金体系のほうが得\n";
        else
            cout << "どちらも同じ\n";
    }

    return 0;
}