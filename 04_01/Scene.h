#pragma once

enum SceneType { TITLE, STAGE, CLEAR };

class Scene {
public:
    virtual ~Scene() {}
    virtual void Initialize() = 0;
    virtual void Update(char* keys, char* preKeys) = 0;
    virtual void Draw() = 0;

    // 次のシーンへ行くためのゲッター
    virtual bool IsFinished() const { return isFinished_; }
    virtual SceneType GetNextScene() const { return nextScene_; }

protected:
    bool isFinished_ = false;
    SceneType nextScene_ = TITLE;
};