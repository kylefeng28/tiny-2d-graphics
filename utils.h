#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <cmath>

struct KColor {
	uint8_t r, g, b, a;
};

template <class T>
inline void swap(T& a, T& b) {
	T c(a); a = b; b = c;
}

// https://en.wikipedia.org/wiki/Linear_interpolation
// Precise method, which guarantees v = v1 when t = 1.
inline float lerp(float v0, float v1, float t) {
	  return (1 - t) * v0 + t * v1;
}

#endif // UTILS_H
