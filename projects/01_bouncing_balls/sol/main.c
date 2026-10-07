#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include "drawline.h"
#include "triangle.h"
#include "list.h"
#include "teapot_data.h"
#include "sphere_data.h"
#include "object.h"

#define LEFT -1
#define RIGHT 1

/* Two macro's that find the lesser or greater of two values */
#define min(x,y) (x < y ? x : y)
#define max(x,y) (x > y ? x : y)


/*
 * Clear the surface by filling it with 0x00000000(black).
 */
void clear_screen(SDL_Surface *surface)
{
    if(SDL_FillRect(surface, NULL, 0x00000000) < 0){
        fprintf(stderr, "Unable to clear the surface. Error returned: %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

/*
 * Accelerate the object; altering its speed based on the boost given.
 */
void accelerate_object(object_t *a, float boost, float maxspeed)
{
    float s;
    float news;
    
    /* Calculate length of speed vector */
    s = sqrtf(a->speedx * a->speedx + a->speedy * a->speedy);

    /* Boost speed */
    news = s * boost;
    if (news < 0.0)
        news = 0.0;
    if (news > maxspeed)
        news = maxspeed;    
    a->speedx *= news/s;
    a->speedy *= news/s;
}

/*
 * Animate bouncing balls on the screen.
 */
void bouncing_balls(SDL_Window *window)
{
    int rotation_way, maxballs;
    int done;
    float screenfloor, screenroof, screenright, screenleft;
    unsigned int ctime;
    float rotation, rotationstep;
    float updatespersec, numsteps, rtime;
    float gravity, maxspeed, bounce;
    float objectscale, objectradius;
    SDL_Event event;
    SDL_Surface *surface;
    list_iterator_t *iter;
    object_t *object, *nextobject;
    list_t *objectlist;

    /* Initialize */
    done = 0;
    iter = NULL;
    objectlist = NULL;
    object = NULL;
    surface = SDL_GetWindowSurface(window);
    
    /* Create new object list */
    objectlist = list_create();
    if (objectlist == NULL) {
        printf("Unable to create object list\n");
        goto done;
    }

    /* Create list iterator */
    iter = list_createiterator(objectlist);
    if (iter == NULL) {
        printf("Unable to create objectlist iterator\n");
        goto done;
    }

    /* Animation variables */
    rotation = 0.0;             /* Rotation degree in radians 0..2*pi (continuously updated) */
    rotationstep = 5.0;         /* Rotation increment (less is more smooth) */
    rotation_way = RIGHT;       /* Define the way the balls are to rotate */
    updatespersec = 50.0;       /* # of updates of scale and rotate we wish to perform per second */
    bounce = 0.8;               /* Speed lost when bumping into screen edges */
    numsteps = 1.0;             /* # of animation updates to perform per frame (continuously updated) */
    maxspeed = 20.0;            /* Maximum object speed */
    gravity = 0.4;              /* Gravity pulling on objects */
    maxballs = 10;              /* Maximum number of balls at any given time */
    objectscale = 0.1;
    objectradius = (int)(500.0*objectscale);
    screenfloor = (float)surface->h - objectradius;
    screenroof = objectradius;
    screenright = (float)surface->w - objectradius;
    screenleft = objectradius;
    while (!done) {
        
        /* Get current time */
        ctime = (float)SDL_GetTicks();

        surface = SDL_GetWindowSurface(window);
        
        /* Clear screen */
        clear_screen(surface);

        /* Randomly generate a new object */
        if ((rand() % 100) > 50 && list_size(objectlist) < maxballs) {
            object = create_object(surface, sphere_model, SPHERE_NUMTRIANGLES);
            object->tx = (float)100.0;
            object->ty = (float)50.0;
            object->scale = objectscale;
            object->speedx = (float)((rand() % 10) + 5);
            object->rotation_way = rotation_way;
            list_addfirst(objectlist, object);
            object = NULL;
        }
    
        /* Update object position and handle collisions */
        list_resetiterator(iter);
        object = list_next(iter);
        while (object != NULL) {
            /* Check for screen edge collisions */
            if (object->ty <= screenroof) {
                object->speedy = -object->speedy;
                object->ty = screenroof;
                accelerate_object(object, bounce, maxspeed);
            }
            if (object->tx >= screenright) {
                object->speedx = -object->speedx;
                object->tx = screenright;
                object->rotation_way = LEFT;
                accelerate_object(object, bounce, maxspeed);
            }
            if (object->tx <= screenleft) {
                object->speedx = -object->speedx;
                object->tx = screenleft;
                object->rotation_way = RIGHT;
                accelerate_object(object, bounce, maxspeed);
            }
            if (object->ty >= screenfloor) {
                object->speedy = -object->speedy;
                object->ty = screenfloor;
                accelerate_object(object, bounce, maxspeed);
            }

            /* Check if object has come to a rest */
            if (object->ttl != 0 ||
               (object->ty == screenfloor && (int)object->speedy == 0 && (int)object->speedx == 0)) {
                if (object->ttl == 0) {
                    object->ttl = ctime + 5000;
                } else if (ctime > object->ttl) {
                    nextobject = list_next(iter);
                    
                    /* Remove object from object-list */
                    list_remove(objectlist, object);
                    
                    /* Free object */
                    destroy_object(object);
                    
                    /* Continue processing objects */
                    object = nextobject;
                    continue;
                }
            } else {
                /* Update object position */
                object->speedy += gravity*numsteps;
                object->ty += object->speedy*numsteps;
                object->tx += object->speedx*numsteps;
            }
            
            /* Keep object within screen boundary */
            object->tx = min(screenright, object->tx);
            object->tx = max(screenleft, object->tx);
            object->ty = min(screenfloor, object->ty);
            object->ty = max(screenroof, object->ty);

            /* Next object */
            object = list_next(iter);
        }        
        
        /* Draw objects */
        list_resetiterator(iter);
        object = list_next(iter);
        while (object != NULL) {
            object->rotation = object->rotation_way * rotation * 0.9;
            draw_object(object);
            object = list_next(iter);
        }
        
        /* Update the window surface */
        SDL_UpdateWindowSurface(window);
        
        /* Calculate # of milliseconds it took to render */
        rtime = (float)SDL_GetTicks() - ctime;
        
        /* Calculate # steps we should perform to ensure a fixed rate of animation updates */
        numsteps = (rtime*updatespersec)/1000.0;
        
        /* Update rotation */
        rotation += rotationstep*numsteps;

        /* Detect that the user tries to quit the application */
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    done = 1;
                    break;
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_SHOWN)
                        SDL_SetWindowPosition(window, 50, 50);
                    break;
            }
        }
    }
    
done:
    /* Free objects */
    if (iter != NULL) {
        list_resetiterator(iter);
        object = list_next(iter);
        while (object != NULL) {
            destroy_object(object);
            object = list_next(iter);        
        }
        list_destroyiterator(iter);
    }

    /* Zonk objectlist and object */
    if (objectlist != NULL) 
        list_destroy(objectlist);
    if (object != NULL)
        destroy_object(object);
}

int main(void)
{
    const size_t bufsize = 100;
    
    /* Change the screen width and height to your own liking */
    const int screen_w = 1200;
    const int screen_h = 750;

    char errmsg[bufsize];
    SDL_Window *window;
    
    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < -1) {
        snprintf(errmsg, bufsize, "Unable to initialize SDL.");
        goto error;
    }
    
    /* Create a 1600x900 window */
    window = SDL_CreateWindow("The Amazing Bouncing Balls",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              screen_w, screen_h,
                              0);
    if(!window) {
        snprintf(errmsg, bufsize, "Unable to get video surface.");
        goto error;
    }

    /* Start bouncing some balls */
    bouncing_balls(window);

    /* Shut down SDL */
    SDL_Quit();

    /* Wait a little bit jic something went wrong (so that printfs can be read) */
    SDL_Delay(5000);
    
    return 0;

    /* Upon an error, print message and quit properly */
error:
    fprintf(stderr, "%s Error returned: %s\n", errmsg, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
