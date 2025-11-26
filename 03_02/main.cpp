#include"MinClass.h"

int main() {

    // 3種類の型 → 組み合わせで6つ作成
    MinClass<int, int>        m1(10, 20);
    MinClass<int, float>      m2(10, 3.5f);
    MinClass<int, double>     m3(10, 2.2);

    MinClass<float, int>      m4(1.5f, 2);
    MinClass<float, double>   m5(1.5f, 0.5);
    MinClass<double, float>   m6(2.8, 3.1f);

    // 出力
    cout << m1.Min() << endl;
    cout << m2.Min() << endl;
    cout << m3.Min() << endl;
    cout << m4.Min() << endl;
    cout << m5.Min() << endl;
    cout << m6.Min() << endl;

    return 0;
}