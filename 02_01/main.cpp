#include <stdio.h>

// 関数テンプレート
// テンプレートの型を定義。これがあとでintとかに置き換えられる
template<typename Type>
Type Min(Type a, Type b) {
	return (a < b) ? a : b;
}

int main() {

	int i0 = 3;
	int i1 = 5;

	float f0 = 10.5f;
	float f1 = 25.25;

	double d0 = 3.14;
	double d1 = 1.414;

	printf("%d\n", Min(i0, i1));
	printf("%f\n", Min(f0, f1));
	printf("%lf\n", Min(d0, d1));

	return 0;

}