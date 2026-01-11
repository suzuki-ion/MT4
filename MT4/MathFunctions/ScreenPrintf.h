#pragma once
#include "Vector3.h"
#include "Matrix4x4.h"
#include "Quaternion.h"

/// @brief Vector3の値を描画する
/// @param x 表示位置 X
/// @param y 表示位置 Y
/// @param vec 表示するVector3
/// @param str 表示する文字列
void VectorScreenPrintf(int x, int y, const Vector3 &vector, const char *str);

/// @brief Matrix4x4の値を描画する
/// @param x 表示位置 X
/// @param y 表示位置 Y
/// @param mat 表示するMatrix4x4
/// @param str 表示する文字列
void MatrixScreenPrintf(int x, int y, const Matrix4x4 &matrix, const char *str);

/// @brief Quaternionの値を描画する
/// @param x 表示位置 X
/// @param y 表示位置 Y
/// @param quat 表示するQuaternion
/// @param str 表示する文字列
void QuaternionScreenPrintf(int x, int y, const Quaternion &quaternion, const char *str);