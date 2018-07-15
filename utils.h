#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <cmath>

// Avoid `call to 'abs' is ambiguous` error on macOS
#if __APPLE__
#include <cstdlib>
#endif

struct KColor {
	uint8_t r, g, b, a;
	inline KColor operator*(float s) const {
		KColor result = { r, g, b, (uint8_t)(a * s) };
		return result;
	}
};

template <class T>
inline void swap(T& a, T& b) {
	T c(a); a = b; b = c;
}

inline int ipart(float x) {
	return (int)x;
}

inline float fpart(float x) {
	return x - floor(x);
}

inline float rfpart(float x) {
	return 1 - fpart(x);
}

// https://en.wikipedia.org/wiki/Linear_interpolation
// Precise method, which guarantees v = v1 when t = 1.
inline float lerp(float v0, float v1, float t) {
	  return (1 - t) * v0 + t * v1;
}

#endif // UTILS_H
