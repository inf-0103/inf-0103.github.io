#include <SDL2/SDL.h>

int main() {
    int result = SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *win = SDL_CreateWindow("Painting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, 0);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

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
                SDL_Rect where_to_draw = {.x = event.motion.x, .y = event.motion.y, .w = 5, .h = 5};
                SDL_FillRect(surf, &where_to_draw, 0xff0000ff);
            }
        }
        SDL_UpdateWindowSurface(win);
    }
    SDL_Quit();
}
