#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    // テキストファイルを読み込む
    ifstream file("PG3_2025_01_02.txt");
    if (!file) {
        cerr << "ファイルを開けませんでした。" << endl;
        return 1;
    }

    string line;
    getline(file, line);  // 1行読み込み
    file.close();

    vector<string> addresses;
    stringstream ss(line);
    string temp;

    // カンマ区切りで分割
    while (getline(ss, temp, ',')) {
        if (!temp.empty()) addresses.push_back(temp);
    }

    // algorithmライブラリを使ってソート
    sort(addresses.begin(), addresses.end());

    // 出力
    for (const auto& addr : addresses) {
        cout << addr << endl;
    }

    return 0;
}

// ↓GPTにやってもらったけどよくわからん
//#include <iostream>   // 標準入出力 (cout, cerr)
//#include <fstream>    // ファイル操作 (ifstream)
//#include <vector>     // 動的配列 vector
//#include <string>     // 文字列操作 string
//#include <algorithm>  // sort などのアルゴリズム
//
//using namespace std;
//
//int main() {
//	// テキストファイル（ASCIIファイル）を読み込みモードで開く
//	ifstream file("PG3_2025_01_02.txt");
//	if (!file) {
//		cerr << "ファイルを開けませんでした。" << endl;
//		return 1;
//	}
//
//	vector<string> addresses; // メールアドレスを格納する配列
//	string current;                // 1件分を一時的にためておく文字列
//	char c;                             // 1文字ずつ読むための変数
//
//	// ファイルの終わりまで1文字ずつ読み取る
//	while (file.get(c)) {
//		if (c == ',') {
//			// カンマが来たら、1件の区切りとしてvectorに追加
//			if (!current.empty()) {
//				addresses.push_back(current);
//				current.clear(); // 次のアドレス用にリセット
//			}
//		} else if (c != '\n' && c != '\r') {
//			// 改行コードは無視して、文字をどんどん追加
//			current += c;
//		}
//	}
//
//	// 最後の要素（末尾にカンマが無い場合）も忘れずに追加
//	if (!current.empty()) {
//		addresses.push_back(current);
//	}
//
//	// algorithmライブラリを使って昇順ソート（文字列の辞書順）
//	sort(addresses.begin(), addresses.end());
//
//	// 結果を出力
//	for (const auto& addr : addresses) {
//		cout << addr << endl;
//	}
//
//	return 0;
//}