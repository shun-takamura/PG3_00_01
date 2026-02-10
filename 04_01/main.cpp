#include <Novice.h>
#include "Scene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

const char kWindowTitle[] = "LE2B_16_タカムラ_シュン";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// シーンのインスタンス生成
	Scene* currentScene = new TitleScene();
	currentScene->Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// --- シーン更新 ---
		currentScene->Update(keys, preKeys);

		// --- シーン切り替え判定 ---
		if (currentScene->IsFinished()) {
			SceneType next = currentScene->GetNextScene();
			delete currentScene; // 古いシーンを破棄

			switch (next) {
			case TITLE: currentScene = new TitleScene(); break;
			case STAGE: currentScene = new StageScene(); break;
			case CLEAR: currentScene = new ClearScene(); break;
			}
			currentScene->Initialize();
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		currentScene->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
