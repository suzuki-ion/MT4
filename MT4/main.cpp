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

    Quaternion q1(2.0f, 3.0f, 4.0f, 1.0f);
    Quaternion q2(1.0f, 3.0f, 5.0f, 2.0f);
    Quaternion identity = Quaternion::Identity();
	Quaternion conj = q1.Conjugate();
    Quaternion inv = q1.Inverse();
	Quaternion normal = q1.Normalize();
    Quaternion mul1 = q1 * q2;
    Quaternion mul2 = q2 * q1;
	float norm = q1.Norm();

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

        QuaternionScreenPrintf(0, 32 * 0, identity, "Identity");
        QuaternionScreenPrintf(0, 32 * 1, conj, "Conjugate");
        QuaternionScreenPrintf(0, 32 * 2, inv, "Inverse");
		QuaternionScreenPrintf(0, 32 * 3, normal, "Normalize");
		QuaternionScreenPrintf(0, 32 * 4, mul1, "q1 * q2");
		QuaternionScreenPrintf(0, 32 * 5, mul2, "q2 * q1");
        Novice::ScreenPrintf(0, 32 * 6, "Norm: %6.3f", norm);

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
