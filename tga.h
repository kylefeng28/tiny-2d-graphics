#ifndef TGA_H
#define TGA_H

#include "./utils.h"
#include <cstdio>
#include <cstdint>

/*
 * Simple struct representing a Truevision TGA file
 *
 * For the full specs, see:
 * https://en.wikipedia.org/wiki/Truevision_TGA#Technical_details
 * http://www.paulbourke.net/dataformats/tga/
 */
// Truevision TGA, version 2.0
// All values are little-endian
/*
  field | size | bytes | name
  ------+------+-------+------------------
   1    | 1    | 0     | id_length
   2    | 1    | 1     | color_map_type
   3    | 1    | 2     | image_type
   4    | 5    | 3-7   | color_map_spec
   5    | 10   | 8-17  | image_spec
   */

struct TGAImage {
	uint16_t width, height;

	uint8_t header[18];
	uint8_t* pixels;

	TGAImage(uint16_t w, uint16_t h);
	~TGAImage();

	int write_to_file(FILE* f);

	int set(size_t x, size_t y, KColor color);

private:
	void make_tga_header();
};

#endif // TGA_H
