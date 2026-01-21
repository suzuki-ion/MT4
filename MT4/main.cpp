#include <Novice.h>

//--------- ベクトル・行列 ---------//
#include "MathFunctions/Vector3.h"
#include "MathFunctions/Matrix4x4.h"
#include "MathFunctions/AffineMatrix.h"
#include "MathFunctions/Quaternion.h"

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

	Quaternion rotation0 = Quaternion().MakeRotateAxisAngle({ 0.71f, 0.71f, 0.0f }, 0.3f);
	Quaternion rotation1 = Quaternion().MakeRotateAxisAngle({ 0.71f, 0.0f, 0.71f }, 3.141592f);

    Quaternion interpolate0 = Quaternion::Slerp(rotation0, rotation1, 0.0f);
    Quaternion interpolate1 = Quaternion::Slerp(rotation0, rotation1, 0.3f);
    Quaternion interpolate2 = Quaternion::Slerp(rotation0, rotation1, 0.5f);
    Quaternion interpolate3 = Quaternion::Slerp(rotation0, rotation1, 0.7f);
    Quaternion interpolate4 = Quaternion::Slerp(rotation0, rotation1, 1.0f);

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

        QuaternionScreenPrintf(0, 32 * 0, interpolate0, "interpolate0, Slerp(q0, q1, 0.0f)");
        QuaternionScreenPrintf(0, 32 * 1, interpolate1, "interpolate1, Slerp(q0, q1, 0.3f)");
        QuaternionScreenPrintf(0, 32 * 2, interpolate2, "interpolate2, Slerp(q0, q1, 0.5f)");
        QuaternionScreenPrintf(0, 32 * 3, interpolate3, "interpolate3, Slerp(q0, q1, 0.7f)");
        QuaternionScreenPrintf(0, 32 * 4, interpolate4, "interpolate4, Slerp(q0, q1, 1.0f)");

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
