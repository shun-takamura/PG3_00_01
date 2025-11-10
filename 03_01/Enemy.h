#pragma once
#include <iostream>
using namespace std;

// Enemy.h（ヘッダ側）
class Enemy {
public:
    void Update();

private:
    enum class Phase { Approach, Attack, Escape, Max };
    Phase phase_ = Phase::Approach;

    void NextPhase();

    void Approach();
    void Attack();
    void Escape();

    // メンバ関数ポインタテーブルの宣言
    static void (Enemy::* spFuncTable[])();
};