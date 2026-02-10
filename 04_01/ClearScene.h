#pragma once
#include "Scene.h"
#include <Novice.h>

class ClearScene :public Scene
{
public:
    void Initialize() override { isFinished_ = false; }
    void Update(char* keys, char* preKeys) override {
        if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
            isFinished_ = true;
            nextScene_ = TITLE;
        }
    }
    void Draw() override {
        Novice::ScreenPrintf(560, 340, "CLEAR!! PRESS SPACE TO TITLE");
    }
};

