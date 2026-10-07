#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <SDL.h>
#include "drawline.h"
#include "triangle.h"
#include "object.h"


/*
 * Return a newly created object based on the arguments provided.
 */
object_t *create_object(SDL_Surface *surface, triangle_t *model, int numtriangles)
{
    /* Allocate memory for object and model */
    object_t *object = calloc(1, sizeof(object_t));
    triangle_t *copy = malloc(sizeof(triangle_t) * numtriangles);
    if(!object || !copy) {
        if(object)
            free(object);
        return NULL;
    }

    memcpy(copy, model, sizeof(triangle_t) * numtriangles);

    /* Initialize object values, and copy model data */
    object->model = copy;
    object->surface = surface;
    object->numtriangles = numtriangles;

    return object;
}

/*
 * Destroy the object, freeing the memory.
 */
void destroy_object(object_t *object)
{
    free(object->model);
    free(object);
}

/*
 * Draw the object on its surface.
 */
void draw_object(object_t *object)
{
    for(int i = 0; i < object->numtriangles; i++) {
        object->model[i].rotation = object->rotation;
        object->model[i].scale = object->scale;
        object->model[i].tx = (int)object->tx;
        object->model[i].ty = (int)object->ty;

        draw_triangle(object->surface, &object->model[i]);
    }
} 
