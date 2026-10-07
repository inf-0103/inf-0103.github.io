#ifndef DRAWLINE_H_
#define DRAWLINE_H_

#include <SDL.h>

/*
 * Draw a line on the surface from point (x1, y1) to point (x2, y2) using color
 */
void draw_line(SDL_Surface *surface, int x1, int y1, int x2, int y2, Uint32 color);

/* 
 * Read color of pixel (x, y) from the surface
 */
Uint32 get_pixel(SDL_Surface *surface, int x, int y);

/* 
 * Set pixel (x, y) on the surface to the given color
 */
void set_pixel(SDL_Surface *surface, int x, int y, Uint32 color);

#endif /* DRAWLINE_H_ */
