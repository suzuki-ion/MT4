#pragma once
#include <cmath>

struct Quaternion {
    static Quaternion Identity() noexcept {
        return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
    }
    static Quaternion Zero() noexcept {
        return Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
    }

    Quaternion() noexcept = default;
    constexpr Quaternion(float x, float y, float z, float w) noexcept
        : x(x), y(y), z(z), w(w)
    {}

    inline Quaternion &operator=(const Quaternion &quaternion) noexcept {
        x = quaternion.x;
        y = quaternion.y;
        z = quaternion.z;
        w = quaternion.w;
        return *this;
    }
    inline Quaternion &operator+=(const Quaternion &quaternion) noexcept {
        x += quaternion.x;
        y += quaternion.y;
        z += quaternion.z;
        w += quaternion.w;
        return *this;
    }
    inline Quaternion &operator-=(const Quaternion &quaternion) noexcept {
        x -= quaternion.x;
        y -= quaternion.y;
        z -= quaternion.z;
        w -= quaternion.w;
        return *this;
    }
    inline Quaternion &operator*=(const Quaternion &quaternion) noexcept {
        float nx = w * quaternion.x + x * quaternion.w + y * quaternion.z -  z *  quaternion.y;
        float ny = w * quaternion.y - x * quaternion.z + y * quaternion.w + z *  quaternion.x;
        float nz = w * quaternion.z + x * quaternion.y - y * quaternion.x + z *  quaternion.w;
        float nw = w * quaternion.w - x * quaternion.x - y * quaternion.y - z * quaternion.z;
        x = nx;
        y = ny;
        z = nz;
        w = nw;
        return *this;
    }
    inline Quaternion &operator*=(float scalar) noexcept {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }
    inline Quaternion &operator/=(float scalar) noexcept {
        float invScalar = 1.0f / scalar;
        x *= invScalar;
        y *= invScalar;
        z *= invScalar;
        w *= invScalar;
        return *this;
    }

    inline Quaternion operator+(const Quaternion &quaternion) const noexcept {
        return Quaternion(*this) += quaternion;
    }
    inline Quaternion operator-(const Quaternion &quaternion) const noexcept {
        return Quaternion(*this) -= quaternion;
    }
    inline Quaternion operator*(const Quaternion &quaternion) const noexcept {
        return Quaternion(*this) *= quaternion;
    }
    inline Quaternion operator*(float scalar) const noexcept {
        return Quaternion(*this) *= scalar;
    }
    inline Quaternion operator/(float scalar) const noexcept {
        return Quaternion(*this) /= scalar;
    }

    Quaternion Conjugate() const noexcept {
        return Quaternion(-x, -y, -z, w);
    }
    float NormSquared() const noexcept {
        return x * x + y * y + z * z + w * w;
    }
    float Norm() const noexcept {
        return std::sqrt(NormSquared());
    }
    Quaternion Normalize() const noexcept {
        float norm = Norm();
        if (norm == 0.0f) {
            return Quaternion::Zero();
        }
        return *this / norm;
    }
    Quaternion Inverse() const noexcept {
        float normSq = NormSquared();
        if (normSq == 0.0f) {
            return Quaternion::Zero();
        }
        return Conjugate() / normSq;
    }

    float x;
    float y;
    float z;
    float w;
};