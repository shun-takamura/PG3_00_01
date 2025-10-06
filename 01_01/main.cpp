#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <list>
#include <Windows.h>
using namespace std;

void printList(const list<const char*>& lst, const char* title) {
    cout << "\n=== " << title << " ===\n";
    for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
        cout << *itr << "\n";
    }
}

int main() {
    // 1970年（西日暮里,高輪ゲートウェイなし）
    list<const char*> y1970 = {
        "Tokyo","Kanda","Akihabara","Okachimachi","Ueno","Uguisudani",
        "Nippori",
        "Tabata","Komagome","Sugamo","Otsuka","Ikebukuro",
        "Mejiro","Takadanobaba","Shin-Okubo","Shinjuku","Yoyogi","Harajuku",
        "Shibuya","Ebisu","Meguro","Gotanda","Osaki","Shinagawa",
        "Tamachi","Hamamatsucho","Shimbashi","Yurakucho"
    };

    printList(y1970, "1970年の山手線駅一覧");

    // 1971年：西日暮里を追加
    list<const char*> y1971 = y1970;
    for (auto itr = y1971.begin(); itr != y1971.end(); ++itr) {
        if (strcmp(*itr, "Tabata") == 0) {
            y1971.insert(itr, "Nishi-Nippori");
            break;
        }
    }

    // 2019年：1971年と同じ
    list<const char*> y2019 = y1971;
    printList(y2019, "2019年の山手線駅一覧");

    // 2022年：高輪ゲートウェイを追加
    list<const char*> y2022 = y2019;
    for (auto itr = y2022.begin(); itr != y2022.end(); ++itr) {
        if (strcmp(*itr, "Shinagawa") == 0) {
            y2022.insert(itr, "Takanawa Gateway");
            break;
        }
    }

    printList(y2022, "2022年の山手線駅一覧");

    return 0;
}
