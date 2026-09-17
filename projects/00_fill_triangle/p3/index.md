# Project 1.3: fill triangle, draw teapot
## Main task
Building either on your own code from last or the 
[provided precode](../pre_fill.zip),
implement the `fill_triangle` function. Once the test triangles are done,
draw the teapot.

## Bonus tasks
1. implement a different fill algorithm. If you did a line scan, now do flood
   fill. Can you find/think of other fill algorithms?
2. (more challenging) assume there is a light source at the point (0, 0). Fill
   the triangles in such a way that the further they are from (0, 0), the
   darker they get.

## Tips/resources
On filling in shapes:

* [Computer graphigs from scratch: filled triangles](https://gabrielgambetta.com/computer-graphics-from-scratch/07-filled-triangles.html)
* [Efficient Polygon-Filling Algorithms for Raster Displays](https://dl.acm.org/doi/10.1145/245.248)
* [Point in triangle test](https://blackpawn.com/texts/pointinpoly/)

The teapot is stored in a big
[array](https://beej.us/guide/bgc/html/split/arrays.html#arrays) 
of `triangle_t` structs.
