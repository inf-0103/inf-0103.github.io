#include <SDL2/SDL.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    SDL_Point *points;
    int capacity;
    int len;
} points_t;

points_t *create_points() {
    points_t *ret = malloc(sizeof(points_t));
    ret->capacity = 100;
    ret->len = 0;
    ret->points = malloc(sizeof(SDL_Point) * 100);
}

void add_point(points_t *p, SDL_Point to_add) {
    if(p->capacity == p->len) {
        SDL_Point *new_data = malloc(sizeof(SDL_Point) * p->len * 1.5);
        memcpy(new_data, p->points, p->len * sizeof(SDL_Point));
        free(p->points);
        p->points = new_data;
        p->capacity = p->len * 1.5;
    }
    p->points[p->len] = to_add;
    p->len++;
}

points_t *load_file() {
    FILE *fd = fopen("BILDE", "r");
    int antall;
    fread(&antall, sizeof(int), 1, fd);
    points_t *ret = malloc(sizeof(points_t));
    ret->points = malloc(sizeof(SDL_Point) * antall);
    ret->len = antall;
    ret->capacity = antall;
    fread(ret->points, sizeof(SDL_Point), antall, fd);
    fclose(fd);
    return ret;
}

void save_file(points_t *points) {
    FILE *fd = fopen("BILDE", "w");
    fwrite(&(points->len), sizeof(int), 1, fd);
    fwrite(points->points, sizeof(SDL_Point), points->len, fd);
    fclose(fd);
}

int main() {
    int result = SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *win = SDL_CreateWindow("Painting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, 0);
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, 0);
    points_t *points = create_points();

    int running = 1;
    int drawing = 0;

    while(running) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = 0;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN) drawing = 1;
            if(event.type == SDL_MOUSEBUTTONUP) drawing = 0;
            if(event.type == SDL_MOUSEMOTION && drawing) {
                SDL_Point new_p = {.x = event.motion.x, .y = event.motion.y};
                add_point(points, new_p);
            }
            if(event.type == SDL_KEYDOWN) {
                if(event.key.keysym.sym == SDLK_s) {
                    printf("Saving!\n");
                    save_file(points);
                }
                if(event.key.keysym.sym == SDLK_l) {
                    points = load_file();
                }
            }
        }
        SDL_SetRenderDrawColor(rend, 0x00, 0x00, 0x00, 0xff);
        SDL_RenderClear(rend);
        SDL_SetRenderDrawColor(rend, 0xff, 0x00, 0x00, 0xff);
        SDL_RenderDrawLines(rend, points->points, points->len);
        SDL_RenderPresent(rend);
    }
    SDL_Quit();
}
