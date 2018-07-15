#include <cstdio>
#include "./utils.h"
#include "./tga.h"
// #include "./line/dda.h"
// #include "./line/bresenham.h"
#include "./line/wu.h"

int main(int argc, const char *argv[]) {

	printf("Hello, world!\n");

	int width = 800, height = 600;
	TGAImage img(width, height);

	// Draw gradient
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			uint8_t r, g, b;
			r = 255 * ((float)y / height);
			g = 255 * ((float)x / width);
			b = 255 * ((float)y / height);
			KColor color = {r, g, b, 255};
			img.set(x, y, color);
		}
	}

	// Draw line pattern
	// for (int ang = 0; ang < 90; ang += 15) {
		KColor c = { 255, 0, 255, 255 };
		// dda(&img, 10, 10, width - 10, height - 10, c);
		// bresenham(&img, 10, 10, width - 10, height - 10, c);
		wu(&img, 10, 10, width - 10, height - 10, c);
	// }

	img.write_to_file("gradient.tga");
	
	return 0;
}
