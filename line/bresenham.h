#ifndef BRESENHAM_H
#define BRESENHAM_H

#include "../tga.h"
#include "../utils.h"

/* Bresenham's line algorithm
 * https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 */
// TODO this is only for octant 0
// TODO swap x, y and transpose if steep
void bresenham(TGAImage* img, int x0, int y0, int x1, int y1, const KColor c) {
	int dx = x1 - x0;
	int dy = y1 - y0;
	int D = (dy << 1) - dx; // 2dy - dx

	int y = y0;
	for (int x = x0; x <= x1; x++) {
		img->set(x, y, c);

		D += (dy << 1); // D += 2dy
		if (D > 0) {
			D -= (dx << 1); // D -= 2dx
			y++;
		}
	}
}

#endif // BRESENHAM_H
