#include "Matrix4x4.h"
#include "Vector3.h"
#include <cmath>
#include <numbers>

constexpr float Matrix4x4::Matrix2x2::Determinant() const noexcept {
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

constexpr float Matrix4x4::Matrix3x3::Determinant() const noexcept {
    float c00 = Matrix2x2(m[1][1], m[1][2], m[2][1], m[2][2]).Determinant();
    float c01 = -(Matrix2x2(m[1][0], m[1][2], m[2][0], m[2][2]).Determinant());
    float c02 = Matrix2x2(m[1][0], m[1][1], m[2][0], m[2][1]).Determinant();
    return m[0][0] * c00 + m[0][1] * c01 + m[0][2] * c02;
}

Matrix4x4 &Matrix4x4::operator+=(const Matrix4x4 &matrix) noexcept {
    // 少しでも速度を稼ぐためにループではなく展開する
    m[0][0] += matrix.m[0][0];
    m[0][1] += matrix.m[0][1];
    m[0][2] += matrix.m[0][2];
    m[0][3] += matrix.m[0][3];

    m[1][0] += matrix.m[1][0];
    m[1][1] += matrix.m[1][1];
    m[1][2] += matrix.m[1][2];
    m[1][3] += matrix.m[1][3];

    m[2][0] += matrix.m[2][0];
    m[2][1] += matrix.m[2][1];
    m[2][2] += matrix.m[2][2];
    m[2][3] += matrix.m[2][3];

    m[3][0] += matrix.m[3][0];
    m[3][1] += matrix.m[3][1];
    m[3][2] += matrix.m[3][2];
    m[3][3] += matrix.m[3][3];

    return *this;
}

Matrix4x4 &Matrix4x4::operator-=(const Matrix4x4 &matrix) noexcept {
    // 少しでも速度を稼ぐためにループではなく展開する
    m[0][0] -= matrix.m[0][0];
    m[0][1] -= matrix.m[0][1];
    m[0][2] -= matrix.m[0][2];
    m[0][3] -= matrix.m[0][3];

    m[1][0] -= matrix.m[1][0];
    m[1][1] -= matrix.m[1][1];
    m[1][2] -= matrix.m[1][2];
    m[1][3] -= matrix.m[1][3];

    m[2][0] -= matrix.m[2][0];
    m[2][1] -= matrix.m[2][1];
    m[2][2] -= matrix.m[2][2];
    m[2][3] -= matrix.m[2][3];

    m[3][0] -= matrix.m[3][0];
    m[3][1] -= matrix.m[3][1];
    m[3][2] -= matrix.m[3][2];
    m[3][3] -= matrix.m[3][3];

    return *this;
}

Matrix4x4 &Matrix4x4::operator*=(const float scalar) noexcept {
    // 少しでも速度を稼ぐためにループではなく展開する
    m[0][0] *= scalar;
    m[0][1] *= scalar;
    m[0][2] *= scalar;
    m[0][3] *= scalar;

    m[1][0] *= scalar;
    m[1][1] *= scalar;
    m[1][2] *= scalar;
    m[1][3] *= scalar;

    m[2][0] *= scalar;
    m[2][1] *= scalar;
    m[2][2] *= scalar;
    m[2][3] *= scalar;

    m[3][0] *= scalar;
    m[3][1] *= scalar;
    m[3][2] *= scalar;
    m[3][3] *= scalar;

    return *this;
}

Matrix4x4 &Matrix4x4::operator*=(const Matrix4x4 &matrix) noexcept {
    *this = *this * matrix;
    return *this;
}

constexpr const Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &matrix) const noexcept {
    // 少しでも速度を稼ぐためにループではなく展開する
    return Matrix4x4(
        m[0][0] + matrix.m[0][0], m[0][1] + matrix.m[0][1], m[0][2] + matrix.m[0][2], m[0][3] + matrix.m[0][3],
        m[1][0] + matrix.m[1][0], m[1][1] + matrix.m[1][1], m[1][2] + matrix.m[1][2], m[1][3] + matrix.m[1][3],
        m[2][0] + matrix.m[2][0], m[2][1] + matrix.m[2][1], m[2][2] + matrix.m[2][2], m[2][3] + matrix.m[2][3],
        m[3][0] + matrix.m[3][0], m[3][1] + matrix.m[3][1], m[3][2] + matrix.m[3][2], m[3][3] + matrix.m[3][3]
    );
}

constexpr const Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &matrix) const noexcept {
    // 少しでも速度を稼ぐためにループではなく展開する
    return Matrix4x4(
        m[0][0] - matrix.m[0][0], m[0][1] - matrix.m[0][1], m[0][2] - matrix.m[0][2], m[0][3] - matrix.m[0][3],
        m[1][0] - matrix.m[1][0], m[1][1] - matrix.m[1][1], m[1][2] - matrix.m[1][2], m[1][3] - matrix.m[1][3],
        m[2][0] - matrix.m[2][0], m[2][1] - matrix.m[2][1], m[2][2] - matrix.m[2][2], m[2][3] - matrix.m[2][3],
        m[3][0] - matrix.m[3][0], m[3][1] - matrix.m[3][1], m[3][2] - matrix.m[3][2], m[3][3] - matrix.m[3][3]
    );
}

constexpr const Matrix4x4 Matrix4x4::operator*(const float scalar) const noexcept {
    // 少しでも速度を稼ぐためにループではなく展開する
    return Matrix4x4(
        m[0][0] * scalar, m[0][1] * scalar, m[0][2] * scalar, m[0][3] * scalar,
        m[1][0] * scalar, m[1][1] * scalar, m[1][2] * scalar, m[1][3] * scalar,
        m[2][0] * scalar, m[2][1] * scalar, m[2][2] * scalar, m[2][3] * scalar,
        m[3][0] * scalar, m[3][1] * scalar, m[3][2] * scalar, m[3][3] * scalar
    );
}

constexpr const Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &matrix) const noexcept {
    // 少しでも速度を稼ぐためにループではなく展開する
    return Matrix4x4(
        m[0][0] * matrix.m[0][0] + m[0][1] * matrix.m[1][0] + m[0][2] * matrix.m[2][0] + m[0][3] * matrix.m[3][0],
        m[0][0] * matrix.m[0][1] + m[0][1] * matrix.m[1][1] + m[0][2] * matrix.m[2][1] + m[0][3] * matrix.m[3][1],
        m[0][0] * matrix.m[0][2] + m[0][1] * matrix.m[1][2] + m[0][2] * matrix.m[2][2] + m[0][3] * matrix.m[3][2],
        m[0][0] * matrix.m[0][3] + m[0][1] * matrix.m[1][3] + m[0][2] * matrix.m[2][3] + m[0][3] * matrix.m[3][3],
        m[1][0] * matrix.m[0][0] + m[1][1] * matrix.m[1][0] + m[1][2] * matrix.m[2][0] + m[1][3] * matrix.m[3][0],
        m[1][0] * matrix.m[0][1] + m[1][1] * matrix.m[1][1] + m[1][2] * matrix.m[2][1] + m[1][3] * matrix.m[3][1],
        m[1][0] * matrix.m[0][2] + m[1][1] * matrix.m[1][2] + m[1][2] * matrix.m[2][2] + m[1][3] * matrix.m[3][2],
        m[1][0] * matrix.m[0][3] + m[1][1] * matrix.m[1][3] + m[1][2] * matrix.m[2][3] + m[1][3] * matrix.m[3][3],
        m[2][0] * matrix.m[0][0] + m[2][1] * matrix.m[1][0] + m[2][2] * matrix.m[2][0] + m[2][3] * matrix.m[3][0],
        m[2][0] * matrix.m[0][1] + m[2][1] * matrix.m[1][1] + m[2][2] * matrix.m[2][1] + m[2][3] * matrix.m[3][1],
        m[2][0] * matrix.m[0][2] + m[2][1] * matrix.m[1][2] + m[2][2] * matrix.m[2][2] + m[2][3] * matrix.m[3][2],
        m[2][0] * matrix.m[0][3] + m[2][1] * matrix.m[1][3] + m[2][2] * matrix.m[2][3] + m[2][3] * matrix.m[3][3],
        m[3][0] * matrix.m[0][0] + m[3][1] * matrix.m[1][0] + m[3][2] * matrix.m[2][0] + m[3][3] * matrix.m[3][0],
        m[3][0] * matrix.m[0][1] + m[3][1] * matrix.m[1][1] + m[3][2] * matrix.m[2][1] + m[3][3] * matrix.m[3][1],
        m[3][0] * matrix.m[0][2] + m[3][1] * matrix.m[1][2] + m[3][2] * matrix.m[2][2] + m[3][3] * matrix.m[3][2],
        m[3][0] * matrix.m[0][3] + m[3][1] * matrix.m[1][3] + m[3][2] * matrix.m[2][3] + m[3][3] * matrix.m[3][3]
    );
}

inline constexpr const Matrix4x4 operator*(const float scalar, const Matrix4x4 &matrix) noexcept {
    return matrix * scalar;
}

inline constexpr const Matrix4x4 Matrix4x4::Identity() noexcept {
    return Matrix4x4(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );
}

constexpr const Matrix4x4 Matrix4x4::Transpose() noexcept {
    return Matrix4x4(
        m[0][0], m[1][0], m[2][0], m[3][0],
        m[0][1], m[1][1], m[2][1], m[3][1],
        m[0][2], m[1][2], m[2][2], m[3][2],
        m[0][3], m[1][3], m[2][3], m[3][3]
    );
}

constexpr const float Matrix4x4::Determinant() const noexcept {
    float c00 = Matrix3x3(
        m[1][1], m[1][2], m[1][3],
        m[2][1], m[2][2], m[2][3],
        m[3][1], m[3][2], m[3][3]).Determinant();
    float c01 = -(Matrix3x3(
        m[1][0], m[1][2], m[1][3],
        m[2][0], m[2][2], m[2][3],
        m[3][0], m[3][2], m[3][3]).Determinant());
    float c02 = Matrix3x3(
        m[1][0], m[1][1], m[1][3],
        m[2][0], m[2][1], m[2][3],
        m[3][0], m[3][1], m[3][3]).Determinant();
    float c03 = -(Matrix3x3(
        m[1][0], m[1][1], m[1][2],
        m[2][0], m[2][1], m[2][2],
        m[3][0], m[3][1], m[3][2]).Determinant());
    return (m[0][0] * c00) + (m[0][1] * c01) + (m[0][2] * c02) + (m[0][3] * c03);
}

Matrix4x4 Matrix4x4::Inverse() const {
    float c00 = Matrix3x3(
        m[1][1], m[1][2], m[1][3],
        m[2][1], m[2][2], m[2][3],
        m[3][1], m[3][2], m[3][3]).Determinant();
    float c01 = -(Matrix3x3(
        m[1][0], m[1][2], m[1][3],
        m[2][0], m[2][2], m[2][3],
        m[3][0], m[3][2], m[3][3]).Determinant());
    float c02 = Matrix3x3(
        m[1][0], m[1][1], m[1][3],
        m[2][0], m[2][1], m[2][3],
        m[3][0], m[3][1], m[3][3]).Determinant();
    float c03 = -(Matrix3x3(
        m[1][0], m[1][1], m[1][2],
        m[2][0], m[2][1], m[2][2],
        m[3][0], m[3][1], m[3][2]).Determinant());

    float c10 = -(Matrix3x3(
        m[0][1], m[0][2], m[0][3],
        m[2][1], m[2][2], m[2][3],
        m[3][1], m[3][2], m[3][3]).Determinant());
    float c11 = Matrix3x3(
        m[0][0], m[0][2], m[0][3],
        m[2][0], m[2][2], m[2][3],
        m[3][0], m[3][2], m[3][3]).Determinant();
    float c12 = -(Matrix3x3(
        m[0][0], m[0][1], m[0][3],
        m[2][0], m[2][1], m[2][3],
        m[3][0], m[3][1], m[3][3]).Determinant());
    float c13 = Matrix3x3(
        m[0][0], m[0][1], m[0][2],
        m[2][0], m[2][1], m[2][2],
        m[3][0], m[3][1], m[3][2]).Determinant();

    float c20 = Matrix3x3(
        m[0][1], m[0][2], m[0][3],
        m[1][1], m[1][2], m[1][3],
        m[3][1], m[3][2], m[3][3]).Determinant();
    float c21 = -(Matrix3x3(
        m[0][0], m[0][2], m[0][3],
        m[1][0], m[1][2], m[1][3],
        m[3][0], m[3][2], m[3][3]).Determinant());
    float c22 = Matrix3x3(
        m[0][0], m[0][1], m[0][3],
        m[1][0], m[1][1], m[1][3],
        m[3][0], m[3][1], m[3][3]).Determinant();
    float c23 = -(Matrix3x3(
        m[0][0], m[0][1], m[0][2],
        m[1][0], m[1][1], m[1][2],
        m[3][0], m[3][1], m[3][2]).Determinant());

    float c30 = -(Matrix3x3(
        m[0][1], m[0][2], m[0][3],
        m[1][1], m[1][2], m[1][3],
        m[2][1], m[2][2], m[2][3]).Determinant());
    float c31 = Matrix3x3(
        m[0][0], m[0][2], m[0][3],
        m[1][0], m[1][2], m[1][3],
        m[2][0], m[2][2], m[2][3]).Determinant();
    float c32 = -(Matrix3x3(
        m[0][0], m[0][1], m[0][3],
        m[1][0], m[1][1], m[1][3],
        m[2][0], m[2][1], m[2][3]).Determinant());
    float c33 = Matrix3x3(
        m[0][0], m[0][1], m[0][2],
        m[1][0], m[1][1], m[1][2],
        m[2][0], m[2][1], m[2][2]).Determinant();

    float det = 1.0f / (m[0][0] * c00 + m[0][1] * c01 + m[0][2] * c02 + m[0][3] * c03);

    return Matrix4x4(
        c00 * det, c10 * det, c20 * det, c30 * det,
        c01 * det, c11 * det, c21 * det, c31 * det,
        c02 * det, c12 * det, c22 * det, c32 * det,
        c03 * det, c13 * det, c23 * det, c33 * det
    );
}

void Matrix4x4::MakeTranslate(const Vector3 &translate) noexcept {
    m[0][0] = 1.0f;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = 1.0f;
    m[1][2] = 0.0f;
    m[1][3] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 1.0f;
    m[2][3] = 0.0f;
    m[3][0] = translate.x;
    m[3][1] = translate.y;
    m[3][2] = translate.z;
    m[3][3] = 1.0f;
}

void Matrix4x4::MakeScale(const Vector3 &scale) noexcept {
    m[0][0] = scale.x;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = scale.y;
    m[1][2] = 0.0f;
    m[1][3] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = scale.z;
    m[2][3] = 0.0f;
    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}

void Matrix4x4::MakeRotate(const Vector3 &rotate) noexcept {
    Matrix4x4 mX;
    Matrix4x4 mY;
    Matrix4x4 mZ;
    mX.MakeRotateX(rotate.x);
    mY.MakeRotateY(rotate.y);
    mZ.MakeRotateZ(rotate.z);
    *this = mX * mY * mZ;
}

void Matrix4x4::MakeRotate(const float radianX, const float radianY, const float radianZ) noexcept {
    Matrix4x4 mX;
    Matrix4x4 mY;
    Matrix4x4 mZ;
    mX.MakeRotateX(radianX);
    mY.MakeRotateY(radianY);
    mZ.MakeRotateZ(radianZ);
    *this = mX * mY * mZ;
}

void Matrix4x4::MakeRotateX(const float radian) noexcept {
    float s = std::sin(radian);
    float c = std::cos(radian);
    m[0][0] = 1.0f;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = c;
    m[1][2] = s;
    m[1][3] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = -s;
    m[2][2] = c;
    m[2][3] = 0.0f;
    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}

void Matrix4x4::MakeRotateY(const float radian) noexcept {
    float s = std::sin(radian);
    float c = std::cos(radian);
    m[0][0] = c;
    m[0][1] = 0.0f;
    m[0][2] = -s;
    m[0][3] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = 1.0f;
    m[1][2] = 0.0f;
    m[1][3] = 0.0f;
    m[2][0] = s;
    m[2][1] = 0.0f;
    m[2][2] = c;
    m[2][3] = 0.0f;
    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}

void Matrix4x4::MakeRotateZ(const float radian) noexcept {
    float s = std::sin(radian);
    float c = std::cos(radian);
    m[0][0] = c;
    m[0][1] = s;
    m[0][2] = 0.0f;
    m[0][3] = 0.0f;
    m[1][0] = -s;
    m[1][1] = c;
    m[1][2] = 0.0f;
    m[1][3] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 1.0f;
    m[2][3] = 0.0f;
    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}

void Matrix4x4::MakeAffine(const Vector3 &scale, const Vector3 &rotate, const Vector3 &translate) noexcept {
    Matrix4x4 mX;
    Matrix4x4 mY;
    Matrix4x4 mZ;
    Matrix4x4 mT;
    Matrix4x4 mS;
    mX.MakeRotateX(rotate.x);
    mY.MakeRotateY(rotate.y);
    mZ.MakeRotateZ(rotate.z);
    mT.MakeTranslate(translate);
    mS.MakeScale(scale);
    *this =  mS * (mX * mY * mZ) * mT;
}

void Matrix4x4::MakeRotateAxisAngle(const Vector3 &axis, const float angle) noexcept {
    float c = std::cos(angle);
    float s = std::sin(angle);
    float t = 1.0f - c;
    m[0][0] = c + axis.x * axis.x * t;
    m[0][1] = axis.x * axis.y * t + axis.z * s;
    m[0][2] = axis.x * axis.z * t - axis.y * s;
    m[0][3] = 0.0f;
    m[1][0] = axis.y * axis.x * t - axis.z * s;
    m[1][1] = c + axis.y * axis.y * t;
    m[1][2] = axis.y * axis.z * t + axis.x * s;
    m[1][3] = 0.0f;
    m[2][0] = axis.z * axis.x * t + axis.y * s;
    m[2][1] = axis.z * axis.y * t - axis.x * s;
    m[2][2] = c + axis.z * axis.z * t;
    m[2][3] = 0.0f;
    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}

void Matrix4x4::MakeDirectionToDirection(const Vector3 &from, const Vector3 &to) noexcept {
    Vector3 n;
    if (from == -to) {
        if (std::abs(from.x) > std::abs(from.z)) {
            n = Vector3(-from.y, from.x, 0.0f).Normalize();
        } else {
            n = Vector3(0.0f, -from.z, from.y).Normalize();
        }
    } else {
        n = from.Cross(to).Normalize();
    }
    float c = from.Dot(to);
    float s = (from.Cross(to)).Length();
    float t = 1.0f - c;
    m[0][0] = n.x * n.x * t + c;
    m[0][1] = n.x * n.y * t + n.z * s;
    m[0][2] = n.x * n.z * t - n.y * s;
    m[0][3] = 0.0f;
    m[1][0] = n.y * n.x * t - n.z * s;
    m[1][1] = n.y * n.y * t + c;
    m[1][2] = n.y * n.z * t + n.x * s;
    m[1][3] = 0.0f;
    m[2][0] = n.z * n.x * t + n.y * s;
    m[2][1] = n.z * n.y * t - n.x * s;
    m[2][2] = n.z * n.z * t + c;
    m[2][3] = 0.0f;
    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}

