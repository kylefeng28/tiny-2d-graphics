#include "./tga.h"

TGAImage::TGAImage(uint16_t w, uint16_t h) : width(w), height(h)
{
	pixels = new uint8_t[width * height * 3];
	make_tga_header();
}

TGAImage::~TGAImage() {
	delete[] pixels;
}

int TGAImage::write_to_file(const char* filename) {
	FILE* f = fopen(filename, "w");
	if (f == NULL) {
		printf("Error opening file %s!", filename);
		return 0;
	}
	int ok = (fwrite(header, 18, 1, f) && fwrite(pixels, width * height * 3, 1, f));
	if (ok) {
		printf("Image saved as %s", filename);
		fclose(f);
	} else {
		printf("Error saving as %s!", filename);
	}
	return ok;
}

int TGAImage::set(size_t x, size_t y, KColor color) {
	if (x >= width || y >= height) {
		return 0;
	}

	// Little-endian, blue channel goes first
	pixels[3*(y * width + x)    ] = color.b;
	pixels[3*(y * width + x) + 1] = color.g;
	pixels[3*(y * width + x) + 2] = color.r;

	return 1;
}

void TGAImage::make_tga_header() {
	// Image type (field 3)
	header[2] = 2; // uncompressed true-color image

	// Image spec (field 5)
	// Width
	header[12] = 255 & width;
	header[13] = 255 & (width >> 8);
	// Height
	header[14] = 255 & height;
	header[15] = 255 & (height >> 8);
	// Pixel depth
	header[16] = 24; // 24 = true color
	// Image descriptor
	header[17] = 32; // ???
}
