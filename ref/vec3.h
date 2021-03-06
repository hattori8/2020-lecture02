#ifndef _VEC3_H
#define _VEC3_H
#include <cmath>
#include <iostream>

template <typename T>
struct Vec3 {
  T v[3];

  Vec3() { v[0] = v[1] = v[2] = 0; }
  Vec3(T x) { v[0] = v[1] = v[2] = x; }
  Vec3(T x, T y, T z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
  }

  T operator[](unsigned int i) const { return v[i]; }
  T& operator[](unsigned int i) { return v[i]; }
};

// ベクトル同士の加算
template <typename T>
inline Vec3<T> operator+(const Vec3<T>& v1, const Vec3<T>& v2) {
  Vec3<T> ret;
  for (int i = 0; i < 3; ++i) {
    ret[i] = v1[i] + v2[i];
  }
  return ret;
}

// ベクトル同士の減算
template <typename T>
inline Vec3<T> operator-(const Vec3<T>& v1, const Vec3<T>& v2) {
  Vec3<T> ret;
  for (int i = 0; i < 3; ++i) {
    ret[i] = v1[i] - v2[i];
  }
  return ret;
}

// スカラー倍
template <typename T>
inline Vec3<T> operator*(const Vec3<T>& v1, const T& k) {
  Vec3<T> ret;
  for (int i = 0; i < 3; ++i) {
    ret[i] = v1[i] * k;
  }
  return ret;
}
template <typename T>
inline Vec3<T> operator*(const T& k, const Vec3<T>& v2) {
  Vec3<T> ret;
  for (int i = 0; i < 3; ++i) {
    ret[i] = k * v2[i];
  }
  return ret;
}
template <typename T>
inline Vec3<T> operator/(const Vec3<T>& v1, const T& k) {
  Vec3<T> ret;
  for (int i = 0; i < 3; ++i) {
    ret[i] = v1[i] / k;
  }
  return ret;
}
template <typename T>
inline Vec3<T> operator/(const T& k, const Vec3<T>& v2) {
  Vec3<T> ret;
  for (int i = 0; i < 3; ++i) {
    ret[i] = k / v2[i];
  }
  return ret;
}

// アダマール積
template <typename T>
inline Vec3<T> operator*(const Vec3<T>& v1, const Vec3<T>& v2) {
  Vec3<T> ret;
  for (int i = 0; i < 3; ++i) {
    ret[i] = v1[i] * v2[i];
  }
  return ret;
}
template <typename T>
inline Vec3<T> operator/(const Vec3<T>& v1, const Vec3<T>& v2) {
  Vec3<T> ret;
  for (int i = 0; i < 3; ++i) {
    ret[i] = v1[i] / v2[i];
  }
  return ret;
}

// ベクトルの長さ
template <typename T>
inline float length(const Vec3<T>& v) {
  float sum = 0;
  for (int i = 0; i < 3; ++i) {
    sum += v[i] * v[i];
  }
  return std::sqrt(sum);
}

// 正規化
template <typename T>
inline Vec3<T> normalize(const Vec3<T>& v) {
  return v / length(v);
}

// 内積
template <typename T>
inline T dot(const Vec3<T>& v1, const Vec3<T>& v2) {
  T ret = 0;
  for (int i = 0; i < 3; ++i) {
    ret += v1[i] * v2[i];
  }
  return ret;
}

// 外積
template <typename T>
inline Vec3<T> cross(const Vec3<T>& v1, const Vec3<T>& v2) {
  Vec3<T> ret;
  ret[0] = v1[1] * v2[2] - v1[2] * v2[1];
  ret[1] = v1[2] * v2[0] - v1[0] * v2[2];
  ret[2] = v1[0] * v2[1] - v1[1] * v2[0];
  return ret;
}

// print
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Vec3<T>& v) {
  stream << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
  return stream;
}

using Vec3u = Vec3<unsigned int>;
using Vec3i = Vec3<int>;
using Vec3f = Vec3<float>;

#endif