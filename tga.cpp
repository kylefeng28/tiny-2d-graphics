#include "./tga.h"

TGAImage::TGAImage(const uint16_t w, const uint16_t h) : width(w), height(h)
{
	pixels = new uint8_t[width * height * 4];
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
	int ok = (fwrite(header, 18, 1, f) && fwrite(pixels, width * height * 4, 1, f));
	if (ok) {
		printf("Image written to %s", filename);
		fclose(f);
	} else {
		printf("Error writing to %s!", filename);
	}
	return ok;
}

int TGAImage::set(const size_t x, const size_t y, const KColor color) {
	if (x >= width || y >= height) {
		return 0;
	}

	// Little-endian, blue channel goes first
	pixels[4*(y * width + x)    ] = color.b;
	pixels[4*(y * width + x) + 1] = color.g;
	pixels[4*(y * width + x) + 2] = color.r;
	pixels[4*(y * width + x) + 3] = color.a;

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
	header[16] = 32; // true color, 8 bits for each RGBA channel
	// Image descriptor
	header[17] = 32; // ???
}
