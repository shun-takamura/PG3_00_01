#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

// 遅延実行関数（関数ポインタではなく、汎用ラムダ対応のテンプレート）
template<typename Func>
void DelayReveal(Func fn, unsigned int delayMs, int roll, int userGuess) {
    cout << "サイコロを振っています..." << endl;
    this_thread::sleep_for(chrono::milliseconds(delayMs));
    fn(roll, userGuess);
}

int main() {
    srand((unsigned)time(NULL));

    int userGuess;
    cout << "奇数（半）=1, 偶数（丁）=0 を入力してください: ";
    cin >> userGuess;

    int roll = rand() % 6 + 1;

    // ラムダ式を使用して処理
    // []ラムダキャプチャ
    // ()パラメーター定義節 引数みたいなやつ
    // {}複合ステートメント 関数定義部分
    // ()関数呼び出し式
    auto showResult = [](int roll, int userGuess) {
        cout << "出目は " << roll << " でした。" << endl;
        int result = roll % 2; // 奇数=1, 偶数=0
        if (result == userGuess)
            cout << "正解です！" << endl;
        else
            cout << "不正解です。" << endl;
        };

    // ラムダを引数に渡して実行（3秒後に結果表示）
    DelayReveal(showResult, 3000, roll, userGuess);

    return 0;
}