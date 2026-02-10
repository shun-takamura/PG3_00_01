#include <Novice.h>
#include <vector> // 履歴管理用

const char kWindowTitle[] = "Step Undo System";

const int kTileSize = 64;
const int kMapCols = 20;
const int kMapRows = 12;

struct Vector2Int {
    int x;
    int y;
};

const int kMaxUnits = 5;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    Novice::Initialize(kWindowTitle, 1280, 720);

    Vector2Int cursor = { 0, 0 };

    Vector2Int units[kMaxUnits] = {
        {2, 4}, {8, 2}, {10, 6}, {12, 10}, {6, 8}
    };

    bool isUnitSelected = false;
    int selectedUnitIndex = -1;

    // --- NEW: 移動経路の履歴（足跡） ---
    // ユニットを掴んでいる間の移動履歴を保存するリスト
    std::vector<Vector2Int> stepHistory;

    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    while (Novice::ProcessMessage() == 0) {
        Novice::BeginFrame();

        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        // --- 移動入力の検知 ---
        int moveX = 0;
        int moveY = 0;

        // トリガー入力（押した瞬間）
        if (keys[DIK_W] && !preKeys[DIK_W] || keys[DIK_UP] && !preKeys[DIK_UP]) { moveY = -1; }
        if (keys[DIK_S] && !preKeys[DIK_S] || keys[DIK_DOWN] && !preKeys[DIK_DOWN]) { moveY = 1; }
        if (keys[DIK_A] && !preKeys[DIK_A] || keys[DIK_LEFT] && !preKeys[DIK_LEFT]) { moveX = -1; }
        if (keys[DIK_D] && !preKeys[DIK_D] || keys[DIK_RIGHT] && !preKeys[DIK_RIGHT]) { moveX = 1; }

        // --- NEW: 移動処理と履歴保存 ---

        // 移動入力があった場合
        if (moveX != 0 || moveY != 0) {

            // ユニットを掴んでいるなら、移動する前の場所を履歴に残す
            if (isUnitSelected) {
                stepHistory.push_back(cursor);
            }

            // カーソル移動実行
            cursor.x += moveX;
            cursor.y += moveY;

            // 画面外に出ないように制限
            if (cursor.x < 0) cursor.x = 0;
            if (cursor.x >= kMapCols) cursor.x = kMapCols - 1;
            if (cursor.y < 0) cursor.y = 0;
            if (cursor.y >= kMapRows) cursor.y = kMapRows - 1;

            // ユニット座標の同期
            if (isUnitSelected && selectedUnitIndex != -1) {
                units[selectedUnitIndex].x = cursor.x;
                units[selectedUnitIndex].y = cursor.y;
            }
        }

        // --- NEW: Undo処理 (Ctrl + Z) ---
        // ユニットを掴んでいる最中に、1歩戻る
        bool isCtrlPressed = keys[DIK_LCONTROL] || keys[DIK_RCONTROL];

        if (isUnitSelected && isCtrlPressed && keys[DIK_Z] && !preKeys[DIK_Z]) {
            // 履歴（戻れる場所）があるか確認
            if (!stepHistory.empty()) {
                // 1. 一つ前の座標を取得
                Vector2Int prevPos = stepHistory.back();

                // 2. カーソルとユニットをそこに戻す
                cursor = prevPos;
                units[selectedUnitIndex].x = prevPos.x;
                units[selectedUnitIndex].y = prevPos.y;

                // 3. 履歴から削除（戻ったので）
                stepHistory.pop_back();
            }
        }

        // --- ユニット選択・配置（スペースキー） ---
        if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
            if (!isUnitSelected) {
                // [つかむ]
                for (int i = 0; i < kMaxUnits; i++) {
                    if (units[i].x == cursor.x && units[i].y == cursor.y) {
                        isUnitSelected = true;
                        selectedUnitIndex = i;

                        // つかみ始めたときは履歴をクリア（新しい移動の開始）
                        stepHistory.clear();
                        break;
                    }
                }
            } else {
                // [置く]
                isUnitSelected = false;
                selectedUnitIndex = -1;
                stepHistory.clear(); // 置き終わったら履歴は消す
            }
        }

        // --- 描画処理 ---

        // グリッド線
        for (int x = 0; x <= kMapCols; x++) {
            Novice::DrawLine(x * kTileSize, 0, x * kTileSize, kMapRows * kTileSize, 0xFFFFFF50);
        }
        for (int y = 0; y <= kMapRows; y++) {
            Novice::DrawLine(0, y * kTileSize, kMapCols * kTileSize, y * kTileSize, 0xFFFFFF50);
        }

        // ユニット
        for (int i = 0; i < kMaxUnits; i++) {
            unsigned int color = 0xFFFFFFFF;
            if (isUnitSelected && i == selectedUnitIndex) {
                color = 0x00FF00FF; // 緑
            }
            int margin = 4;
            Novice::DrawBox(
                units[i].x * kTileSize + margin,
                units[i].y * kTileSize + margin,
                kTileSize - margin * 2,
                kTileSize - margin * 2,
                0.0f, color, kFillModeSolid
            );
        }

        // カーソル
        Novice::DrawBox(cursor.x * kTileSize, cursor.y * kTileSize, kTileSize, kTileSize, 0.0f, 0xFF0000FF, kFillModeWireFrame);

        // UI表示
        Novice::ScreenPrintf(10, 680, "WASD: Move | Space: Grab/Drop | Ctrl+Z: Step Back");
        if (isUnitSelected) {
            Novice::ScreenPrintf(10, 700, "Moving Unit... History Steps: %d", (int)stepHistory.size());
        } else {
            Novice::ScreenPrintf(10, 700, "Select a unit.");
        }

        Novice::EndFrame();

        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    Novice::Finalize();
    return 0;
}