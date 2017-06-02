//SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>


using namespace std;

Mix_Music* loadMusic(string path);
Mix_Chunk* loadChunk(string path);