#include <cstdio>
#include "./tga.h"

int main(int argc, const char *argv[]) {

	printf("Hello, world!\n");

	int width = 800, height = 600;
	TGAImage img(width, height);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			uint8_t r, g, b;
			r = 255 * ((float)y / height);
			g = 255 * ((float)x / width);
			b = 255 * ((float)y / height);
			KColor color = {r, g, b};
			img.set(x, y, color);
		}
	}

	img.write_to_file("gradient.tga");
	
	return 0;
}
