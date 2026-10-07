#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include "triangle.h"
#include "drawline.h"

#define MIN(x,y)    (x < y ? x : y)
#define MIN3(x,y,z) MIN(MIN(x,y), MIN(x,z))
#define MAX(x,y)    (x > y ? x : y)
#define MAX3(x,y,z) MAX(MAX(x,y), MAX(x,z))

#define TRIANGLE_PENCOLOR   0xBBBB0000

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
    /* Scale triangle */
    triangle->sx1 = (int)((float)triangle->x1*triangle->scale);
    triangle->sx2 = (int)((float)triangle->x2*triangle->scale);
    triangle->sx3 = (int)((float)triangle->x3*triangle->scale);
    triangle->sy1 = (int)((float)triangle->y1*triangle->scale);
    triangle->sy2 = (int)((float)triangle->y2*triangle->scale);
    triangle->sy3 = (int)((float)triangle->y3*triangle->scale);
}

/*
 * Move the triangle to the center of the surface,
 * altering the on-screen coordinates(e.g. triangle->sx1)
 */
void translate_triangle(triangle_t *triangle)
{
    triangle->sx1 += triangle->tx;
    triangle->sx2 += triangle->tx;
    triangle->sx3 += triangle->tx;
    
    triangle->sy1 += triangle->ty;
    triangle->sy2 += triangle->ty;
    triangle->sy3 += triangle->ty;
}

/*
 * Calculate the triangle bounding box,
 * altering fields of the triangle's rect(e.g. triangle->rect.x)
 */
void calculate_triangle_bounding_box(triangle_t *triangle)
{
    /* Calculate upper left corner of bounding box */
    triangle->rect.x = MIN3(triangle->sx1, triangle->sx2, triangle->sx3);
    triangle->rect.y = MIN3(triangle->sy1, triangle->sy2, triangle->sy3);
    
    /* Calculate width and height of bounding box */
    triangle->rect.w = MAX3(triangle->sx1, triangle->sx2, triangle->sx3) - triangle->rect.x + 1;
    triangle->rect.h = MAX3(triangle->sy1, triangle->sy2, triangle->sy3) - triangle->rect.y + 1;
}

/*
 * Fill the triangle on the surface with the triangle's color
 */
void fill_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    int x, y;
    int startfill, stopfill;

    /*
     * Scan triangle bounding box line by line, starting from upper left corner.
     * For each line, set pixels in between first and last pixel set.
     */
    for (y = 0; y < triangle->rect.h; y++) {
        /* Determine first and last pixel set on line. */
        /* Only consider pixels drawn with TRIANGLE_DRAW_PEN color */
        startfill = stopfill = -1;
        for (x = 0; x < triangle->rect.w; x++) {
              if (get_pixel(surface, triangle->rect.x + x, triangle->rect.y + y)== TRIANGLE_PENCOLOR) {
                if (startfill == -1)
                    startfill = x;
                else
                    stopfill = x;
            }            
        }
       
        /* Set pixels between startfill and stopfill. */
        if (startfill != -1) {
            if (stopfill == -1)             /* might be only a single pixel set */
                stopfill = startfill;
            while (startfill <= stopfill) {
                set_pixel(surface, triangle->rect.x + startfill, triangle->rect.y + y, triangle->fillcolor);
                startfill++;
            }
        }
    }
}

/*
 * Rotate the triangle given based on it's rotation field
 */
void rotate_triangle(triangle_t *triangle)
{
    static float rotation = 0;
    static float sinr = 0, cosr = 1;
    float sx1, sx2, sx3;
    float sy1, sy2, sy3;

    /* 
     * Cache sin and cos calculations to reduce overhead
     * INFO: Local variables that are declared static persist across function calls.
     */
    if (triangle->rotation != rotation) {
        rotation = triangle->rotation;
        sinr = sinf(rotation*M_PI/180.0);
        cosr = cosf(rotation*M_PI/180.0);
    }


    /* Copy original coordinates */
    sx1 = (float)triangle->sx1;
    sx2 = (float)triangle->sx2;
    sx3 = (float)triangle->sx3;
    sy1 = (float)triangle->sy1;
    sy2 = (float)triangle->sy2;
    sy3 = (float)triangle->sy3;

    /* Rotate */
    triangle->sx1 = (int)(sx1*cosr - sy1*sinr);
    triangle->sx2 = (int)(sx2*cosr - sy2*sinr);
    triangle->sx3 = (int)(sx3*cosr - sy3*sinr);
    triangle->sy1 = (int)(sx1*sinr + sy1*cosr);
    triangle->sy2 = (int)(sx2*sinr + sy2*cosr);
    triangle->sy3 = (int)(sx3*sinr + sy3*cosr);
}

/*
 * Draw a filled triangle on the given surface
 */
void draw_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    int isOK;
    
    /* Scale. */
    scale_triangle(triangle);

    /* Rotate triangle */
    rotate_triangle(triangle);
    
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

    /* Draw triangle */
    draw_line(surface, 
             triangle->sx1, triangle->sy1,
             triangle->sx2, triangle->sy2,
             TRIANGLE_PENCOLOR);
    draw_line(surface, 
             triangle->sx2, triangle->sy2,
             triangle->sx3, triangle->sy3,
             TRIANGLE_PENCOLOR);
    draw_line(surface, 
             triangle->sx3, triangle->sy3,
             triangle->sx1, triangle->sy1,
             TRIANGLE_PENCOLOR);

    /* Fill triangle */
    fill_triangle(surface, triangle);
}
