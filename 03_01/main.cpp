#include "Enemy.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    Enemy enemy;

    // 敵の状態を何回か更新してみる
    for (int i = 0; i < 6; ++i) {
        enemy.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}