#ifndef WU_H
#define WU_H

#include "../tga.h"
#include "../utils.h"

/*
 * https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
 * https://www.geeksforgeeks.org/anti-aliased-line-xiaolin-wus-algorithm/
 */

void wu(TGAImage* img, int x0, int y0, int x1, int y1, const KColor c) {
	int steep = abs(y1 - y0) > abs(x1 - x0) ;

	// swap the co-ordinates if slope > 1 or we
	// draw backwards
	if (steep) {
		swap(x0 , y0);
		swap(x1 , y1);
	}

	if (x0 > x1) {
		swap(x0 ,x1);
		swap(y0 ,y1);
	}

	//compute the slope
	float dx = x1-x0;
	float dy = y1-y0;
	float gradient = dy/dx;
	if (dx == 0.0) {
		gradient = 1;
	}

	int xpxl1 = x0;
	int xpxl2 = x1;
	float intersectY = y0;

	// main loop
	if (steep) {
		int x;
		for (x = xpxl1 ; x <=xpxl2 ; x++) {
			// pixel coverage is determined by fractional
			// part of y co-ordinate
			img->set(ipart(intersectY), x,
					c * rfpart(intersectY));
			img->set(ipart(intersectY)-1, x,
					c * fpart(intersectY));
			intersectY += gradient;
		}
	}
	else {
		int x;
		for (x = xpxl1 ; x <=xpxl2 ; x++) {
			// pixel coverage is determined by fractional
			// part of y co-ordinate
			img->set(x, ipart(intersectY),
					c * rfpart(intersectY));
			img->set(x, ipart(intersectY)-1,
					c * fpart(intersectY));
			intersectY += gradient;
		}
	}

}

#endif // WU_H
