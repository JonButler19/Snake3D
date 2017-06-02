#include "Music.h"


Mix_Music* loadMusic(string path)
{
	Mix_Music* pMusic = NULL;

	// Load music from supplied audio file path
	pMusic = Mix_LoadMUS(path.c_str());

	// Loading failed
	if (NULL == pMusic)
	{
		cout << "Failed to load music file: " << path << "! SDL_mixer Error: " << Mix_GetError() << endl;;
	}

	return pMusic;
}

Mix_Chunk* loadChunk(string path)
{
	Mix_Chunk* pChunk = NULL;

	// Load audio chunk from supplied audio file path
	pChunk = Mix_LoadWAV(path.c_str());

	// Loading failed
	if (NULL == pChunk)
	{
		cout << "Failed to load audio file: " << path << "! SDL_mixer Error: " << Mix_GetError() << endl;;
	}

	return pChunk;
}