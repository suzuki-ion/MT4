#include <Novice.h>

//--------- ベクトル・行列 ---------//
#include "MathFunctions/Vector3.h"
#include "MathFunctions/Matrix4x4.h"
#include "MathFunctions/AffineMatrix.h"

//--------- 描画関数 ---------//
#include "MathFunctions/ScreenPrintf.h"
#include "MathFunctions/DrawGrid.h"
#include "MathFunctions/Bezier.h"

//--------- 図形 ---------//
#include "MathFunctions/Sphere.h"
#include "MathFunctions/Lines.h"
#include "MathFunctions/Plane.h"
#include "MathFunctions/Triangle.h"
#include "MathFunctions/AABB.h"

//--------- カメラ ---------//
#include "MathFunctions/Camera.h"

//--------- 物理 ---------//
#include "Physics/Ball.h"
#include "Physics/Spring.h"
#include "Physics/Pendulum.h"
#include "Physics/ConicalPendulum.h"

extern const float kWinWidth = 1280.0f;
extern const float kWinHeight = 720.0f;
const char kWindowTitle[] = "LE2A_09_スズキ_イオン";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
    Novice::Initialize(kWindowTitle, static_cast<int>(kWinWidth), static_cast<int>(kWinHeight));

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

    Vector3 from0 = Vector3(1.0f, 0.7f, 0.5f).Normalize();
	Vector3 to0 = -from0;
    Vector3 from1 = Vector3(-0.6f, 0.9f, 0.2f).Normalize();
    Vector3 to1 = Vector3(0.4f, 0.7f, -0.5f).Normalize();
	Matrix4x4 rotationMatrix0;
    rotationMatrix0.MakeDirectionToDirection(Vector3(1.0f, 0.0f, 0.0f).Normalize(), Vector3(-1.0f, 0.0f, 0.0f).Normalize());
	Matrix4x4 rotationMatrix1;
	rotationMatrix1.MakeDirectionToDirection(from0, to0);
    Matrix4x4 rotationMatrix2;
    rotationMatrix2.MakeDirectionToDirection(from1, to1);

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

        MatrixScreenPrintf(0, 0, rotationMatrix0, "rotationMatrix0");
        MatrixScreenPrintf(0, 128, rotationMatrix1, "rotationMatrix1");
        MatrixScreenPrintf(0, 256, rotationMatrix2, "rotationMatrix2");

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
