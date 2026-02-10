#pragma once
#include "Scene.h"
#include <Novice.h>

class StageScene :public Scene
{
    int enemyHp = 1;
public:
    void Initialize() override { isFinished_ = false; enemyHp = 1; }
    void Update(char* keys, char* preKeys) override {
        // 敵を倒す（簡素化のため、SPACEキーで即撃破）
        if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
            enemyHp = 0;
        }
        if (enemyHp <= 0) {
            isFinished_ = true;
            nextScene_ = CLEAR;
        }
    }
    void Draw() override {
        Novice::ScreenPrintf(560, 340, "STAGE SCENE: PRESS SPACE TO KILL ENEMY");
        if (enemyHp > 0) Novice::DrawBox(600, 200, 40, 40, 0.0f, RED, kFillModeSolid);
    }
};

