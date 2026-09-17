#include <stdlib.h>
#include <stdio.h>
#include <SDL3/SDL.h>
#include "triangle.h"
#include "drawline.h"

#define TRIANGLE_PENCOLOR   0xBBBB0000

// helper functions for calculate_triangle_bounding_box()
int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int min(int a, int b) {
  if (a < b) return a;
  return b;
}

/* 
 * Print triangle coordinates along with a message
 */
void print_triangle(triangle_t *triangle, char *msg)
{
    printf("%s: %d,%d - %d,%d - %d,%d\n",
        msg,
        triangle->x1, triangle->y1, 
        triangle->x2, triangle->y2, 
        triangle->x3, triangle->y3);
}

/*
 * Return 0 if triangle coordinates are outside the surface boundary. 1 otherwise.
 */
int sanity_check_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    if (triangle->sx1 < 0 || triangle->sx1 >= surface->w ||
        triangle->sx2 < 0 || triangle->sx2 >= surface->w ||
        triangle->sx3 < 0 || triangle->sx3 >= surface->w ||
        triangle->sy1 < 0 || triangle->sy1 >= surface->h ||
        triangle->sy2 < 0 || triangle->sy2 >= surface->h ||
        triangle->sy3 < 0 || triangle->sy3 >= surface->h) {
        return 0;
    } else {
        return 1;
    }
}

/*
 * Scale triangle, altering the on-screen coordinates(e.g. triangle->sx1)
 */
void scale_triangle(triangle_t *triangle)
{
    // scaling is just to multiply by the scale parameter
    triangle->sx1 = triangle->scale*triangle->x1;
    triangle->sx2 = triangle->scale*triangle->x2;
    triangle->sx3 = triangle->scale*triangle->x3;

    triangle->sy1 = triangle->scale*triangle->y1;
    triangle->sy2 = triangle->scale*triangle->y2;
    triangle->sy3 = triangle->scale*triangle->y3;
}

/*
 * Move the triangle to the center of the surface,
 * altering the on-screen coordinates(e.g. triangle->sx1)
 */
void translate_triangle(triangle_t *triangle)
{
    // translates on screen, after scale_triangle. what would happen if we used
    // eg (x1, y1) instead of (sx1, sy1)?
    triangle->sx1 = triangle->sx1 + triangle->tx;
    triangle->sx2 = triangle->sx2 + triangle->tx;
    triangle->sx3 = triangle->sx3 + triangle->tx;

    triangle->sy1 = triangle->sy1 + triangle->ty;
    triangle->sy2 = triangle->sy2 + triangle->ty;
    triangle->sy3 = triangle->sy3 + triangle->ty;
}

/*
 * Calculate the triangle bounding box,
 * altering fields of the triangle's rect(e.g. triangle->rect.x)
 */
void calculate_triangle_bounding_box(triangle_t *triangle)
{
    int minx = min(min(triangle->x1, triangle->x2), triangle->x3);
    int miny = min(min(triangle->y1, triangle->y2), triangle->y3);

    int maxx = max(max(triangle->x1, triangle->x2), triangle->x3);
    int maxy = max(max(triangle->y1, triangle->y2), triangle->y3);

    triangle->rect.x = minx;
    triangle->rect.y = miny;
    triangle->rect.w = maxx - minx;
    triangle->rect.h = maxy - miny;
}

/*
 * Fill the triangle on the surface with the triangle's color
 */
void fill_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    // TODO: Insert code that fills the triangle with the color specified in triangle->fillcolor.
    // Hint: Draw the triangle with color TRIANGLE_PENCOLOR (this color can not
    // occur in e.g. the teapot or the example triangles).  Thus, if your 
    // approach to filling the triangle relies on looking for the edges of
    // the triangle on the surface (via the GetPixel function), you will find those
    // edges even if the triangle overlaps with a triangle that has already
    // been drawn on the surface.
}

/*
 * Draw a filled triangle on the given surface
 */
void draw_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    int isOK;

    /* Scale. */
    scale_triangle(triangle);
    
    /* Translate. */
    translate_triangle(triangle);
    
    /* Determine bounding box */
    calculate_triangle_bounding_box(triangle);

    /* Sanity check that triangle is within surface boundaries. */
    isOK = sanity_check_triangle(surface, triangle);
    if (!isOK) {
        print_triangle(triangle, "Triangle outside surface boundaries");
        return;
    }

    // remember that what we want is to draw the ON SCREEN triangle (scaled,
    // translated)
    draw_line(surface, triangle->sx1, triangle->sy1, triangle->sx2,
        triangle->sy2, TRIANGLE_PENCOLOR);
    draw_line(surface, triangle->sx3, triangle->sy3, triangle->sx2,
        triangle->sy2, TRIANGLE_PENCOLOR);
    draw_line(surface, triangle->sx1, triangle->sy1, triangle->sx3,
        triangle->sy3, TRIANGLE_PENCOLOR);

    /* Fill triangle */
    fill_triangle(surface, triangle);
}
