#include "Enemy.h"
#include <iostream>

void Enemy::NextPhase(){
    int next = static_cast<int>(phase_) + 1;
    if (next >= static_cast<int>(Phase::Max)) {
        next = 0;
    }
    phase_ = static_cast<Phase>(next);
}

void Enemy::Approach() { std::cout << "接近\n"; }
void Enemy::Attack() { std::cout << "射撃\n"; }
void Enemy::Escape() { std::cout << "離脱\n"; }

void Enemy::Update() {
    // テーブルから呼び出し
    (this->*spFuncTable[static_cast<size_t>(phase_)])();

    NextPhase();
}

// メンバ関数ポインタテーブルの実体定義
void (Enemy::* Enemy::spFuncTable[])() = {
    &Enemy::Approach,
    &Enemy::Attack,
    &Enemy::Escape
};
