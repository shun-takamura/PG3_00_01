#include <Novice.h>
#include <thread>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

// マップデータの構造
std::vector<std::vector<int>> mapData;
bool isLoaded = false;

// 【1】CSV読み込み関数（バックグラウンド用）
void LoadMapCSV(const std::string& filePath) {
	std::ifstream file(filePath);
	std::string line;
	while (std::getline(file, line)) {
		std::vector<int> row;
		std::stringstream ss(line);
		std::string value;
		while (std::getline(ss, value, ',')) {
			row.push_back(std::stoi(value));
		}
		mapData.push_back(row);
	}
	// 読み込みが終わったらフラグを立てる
	isLoaded = true;
}

const char kWindowTitle[] = "LE2B_16_タカムラ_シュン";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// 【2】スレッドを起動して読み込み開始
	// メインループに入る前に別スレッドを切り離す
	std::thread loaderThread(LoadMapCSV, "Resources/map.csv");
	loaderThread.detach(); // detachするとjoinを待たずにメインが進む

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

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		if (!isLoaded) {
			// 【3】ロード中の表示
			Novice::ScreenPrintf(10, 10, "Loading CSV in background...");
		} else {
			// 【4】ロード完了後のマップチップ表示
			Novice::ScreenPrintf(10, 10, "Load Complete!");

			for (int y = 0; y < mapData.size(); y++) {
				for (int x = 0; x < mapData[y].size(); x++) {
					int chipId = mapData[y][x];
					// チップの数値に応じて矩形を描画（簡易マップチップ表示）
					if (chipId == 1) {
						Novice::DrawBox(x * 32, y * 32 + 40, 32, 32, 0.0f, WHITE, kFillModeSolid);
					}
				}
			}
		}

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
