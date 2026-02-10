#include <Novice.h>

// --- 1. コマンド抽象基底クラス ---
class Command {
public:
	virtual ~Command() {}
	virtual void Execute(float& x) = 0;
};

// --- 2. 具体的なコマンドの実装 ---
class MoveLeftCommand : public Command {
public:
	void Execute(float& x) override { x -= 5.0f; }
};

class MoveRightCommand : public Command {
public:
	void Execute(float& x) override { x += 5.0f; }
};

// --- 3. インプットハンドラー ---
class InputHandler {
public:
	Command* HandleInput() {
		if (Novice::CheckHitKey(DIK_A)) return buttonA_;
		if (Novice::CheckHitKey(DIK_D)) return buttonD_;
		return nullptr;
	}

	// コンストラクタでコマンドを割り当て
	InputHandler() {
		buttonA_ = new MoveLeftCommand();
		buttonD_ = new MoveRightCommand();
	}
	~InputHandler() {
		delete buttonA_;
		delete buttonD_;
	}

private:
	Command* buttonA_;
	Command* buttonD_;
};

const char kWindowTitle[] = "LE2B_16_タカムラ_シュン";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// プレイヤーの初期設定
	float playerX = 100.0f;
	float playerY = 100.0f;
	float size = 30.0f;

	InputHandler* inputHandler = new InputHandler();

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

		// 1. 入力を受け取ってコマンドを取得
		Command* command = inputHandler->HandleInput();

		// 2. コマンドがあれば実行
		if (command) {
			command->Execute(playerX);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// プレイヤーの描画
		Novice::DrawBox((int)playerX, (int)playerY, (int)size, (int)size, 0.0f, WHITE, kFillModeSolid);

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
