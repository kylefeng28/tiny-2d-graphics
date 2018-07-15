#ifndef DDA_H
#define DDA_H

#include "../tga.h"
#include "../utils.h"

/* Digital differential analyzer
 * https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)
 */
void dda(TGAImage* img, int x0, int y0, int x1, int y1, const KColor c) {
	int step;
	float x = x0;
	float y = y0;

	float dx = (x1 - x0);
	float dy = (y1 - y0);
	if (abs(dx) >= abs(dy)) {
		step = abs(dx); }
	else {
		step = abs(dy); }
	dx = (float)dx / step;
	dy = (float)dy / step;

	int i = 1;
	while(i <= step) {
		img->set(x, y, c);
		x = x + dx;
		y = y + dy;
		i += 1;
	}
}

#endif // DDA_H
