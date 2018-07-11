# tiny-2d-graphics

A simple 2D graphics library in C++.

## TODO
### Line algorithms
- Bresenham's algorithm (`lines/bresenham.h`)
  - Very fast line drawing algorithm
  - Optimized to use only integer additions, without multiplication or floating-point arithmetic
- Xiaolin Wu's algorithm (`lines/wu.h`)
  - Fast line algorithm that supports antialiasing
  - Efficient, but slower than Bresenham's algorithm
- Digital differential analyzer (`lines/dda.h`)
  - Slow line drawing algorithm, using floating-point arithmetic
- Gupta-Sproull algorithm??

### Blend modes
12 Porter-Duff blend modes (`porter_duff.h`)

### Helpers
- Fast multiply by 255
- Pack_RGBA
- Premultiply alpha

### Classes
- Matrices
- Vectors

### Pixel-art scaling algorithms
