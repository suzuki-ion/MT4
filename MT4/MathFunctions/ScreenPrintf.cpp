#include "ScreenPrintf.h"
#include <Novice.h>

void VectorScreenPrintf(int x, int y, const Vector3 &vector, const char *str) {
    Novice::ScreenPrintf(x, y, str);
    Novice::ScreenPrintf(x, y + 16, "%6.3f %6.3f %6.3f", vector.x, vector.y, vector.z);
}

void MatrixScreenPrintf(int x, int y, const Matrix4x4 &matrix, const char *str) {
    Novice::ScreenPrintf(x, y, str);
    Novice::ScreenPrintf(x, y + 16, "%6.3f %6.3f %6.3f %6.3f", matrix.m[0][0], matrix.m[0][1], matrix.m[0][2], matrix.m[0][3]);
    Novice::ScreenPrintf(x, y + 32, "%6.3f %6.3f %6.3f %6.3f", matrix.m[1][0], matrix.m[1][1], matrix.m[1][2], matrix.m[1][3]);
    Novice::ScreenPrintf(x, y + 48, "%6.3f %6.3f %6.3f %6.3f", matrix.m[2][0], matrix.m[2][1], matrix.m[2][2], matrix.m[2][3]);
    Novice::ScreenPrintf(x, y + 64, "%6.3f %6.3f %6.3f %6.3f", matrix.m[3][0], matrix.m[3][1], matrix.m[3][2], matrix.m[3][3]);
}

void QuaternionScreenPrintf(int x, int y, const Quaternion &quaternion, const char *str) {
    Novice::ScreenPrintf(x, y, str);
    Novice::ScreenPrintf(x, y + 16, "%6.3f %6.3f %6.3f %6.3f", quaternion.x, quaternion.y, quaternion.z, quaternion.w);
}
