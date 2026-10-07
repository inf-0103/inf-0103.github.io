#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <SDL.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

typedef struct triangle triangle_t;

struct triangle {
    /* Model coordinates, where each pair resemble a corner  */
    int x1, y1;
    int x2, y2;
    int x3, y3;

    /* The color the triangle is to be filled with */
    unsigned int fillcolor;
    
    /* Scale factor, meaning 0.5 should half the size, 1 keep, and 2.0 double */
    float scale;

    /* The point (tx, ty) where the center of the teapot should be placed on-screen */
    int tx, ty;

    /* The degrees the triangle is supposed to be rotated at the current frame */
    float rotation;
    
    /* 
     * Bounding box of on-screen coordinates:
     * rect.x - x-coordinate of the bounding box' top left corner
     * rect.y - y-coordinate of the bounding box' top left corner
     * rect.w - width of the bounding box
     * rect.h - height of the bounding box
     */
    SDL_Rect rect;

    /* On-screen coordinates, where each pair resemble a corner */
    int sx1, sy1;
    int sx2, sy2;
    int sx3, sy3;
};

/*
 * Draw a filled triangle on the given surface
 */
void draw_triangle(SDL_Surface *surface, triangle_t *triangle);

#endif /*TRIANGLE_H_*/
