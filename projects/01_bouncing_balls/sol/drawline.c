#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

/* 
 * Read color of pixel (x, y) from the surface
 */
Uint32 get_pixel(SDL_Surface *surface, int x, int y)
{
    Uint32 *pixels = surface->pixels,
           idx = x + y*surface->w;

    if (x >= surface->w || x < 0 ||
        y >= surface->h || y < 0) {
         fprintf(stderr, "Accessing pixel outside of surface, check translation or scale\n");
         return 0;
    }

    /* Get pixel */
    return pixels[idx];
}

/* 
 * Set pixel (x, y) on the surface to the given color
 */
void set_pixel(SDL_Surface *surface, int x, int y, Uint32 color)
{
    Uint32 *pixels = surface->pixels,
           idx = x + y*surface->w;

    /* Verify that pixel is inside of screen */
    if (x >= surface->w || x < 0 ||
        y >= surface->h || y < 0) {
         fprintf(stderr, "Plotting pixel outside of surface, check translation or scale\n");
         return;
    }

    /* Set pixel */
    pixels[idx] = color;
}

/*
 * Draw a line on the surface from point (x1, y1) to point (x2, y2) using color
 */
void draw_line(SDL_Surface *surface, int x1, int y1, int x2, int y2, Uint32 color)
{
    int fraction;
    int x, dx, stepx;
    int y, dy, stepy;
    
    
    /* The below code implements the classic Bresenham algorithm */
    
    dx = x2 - x1;
    dy  = y2 - y1;
    	
    if (dy < 0) {
        dy = -dy;
        stepy = -1;
    } else {
        stepy = 1;	
    }
    
    if (dx < 0) {
        dx = -dx;
        stepx = -1;	
    } else {
        stepx = 1;
    }
    
    dy = dy*2;
    dx = dx*2;
    x = x1;
    y = y1;
    set_pixel(surface, x, y, color);
    if (dx > dy) {
        fraction = dy - (dx/2);
        while (x != x2) {
            if (fraction >= 0) {
                y = y + stepy;
                fraction = fraction - dx;	
            }
            x = x + stepx;
            fraction = fraction + dy;
            set_pixel(surface, x, y, color);
        }	
    } else {
        fraction = dx - (dy/2);
        while (y != y2) {
            if (fraction >= 0) {
                x = x + stepx;
                fraction = fraction - dy;	
            }
            y = y + stepy;
            fraction = fraction + dx;
            set_pixel(surface, x, y, color);
        }	
    }
}
