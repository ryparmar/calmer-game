#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <stdio.h>
#include <string>

class Game
{
protected:
    bool initialized;
    bool finished;

    //Screen dimension constants
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 960;

    //Loads individual image
    SDL_Surface *loadSurface(std::string path);

    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    //The window renderer
    SDL_Renderer *gRenderer = NULL;

    //The surface contained by the window
    SDL_Surface *gScreenSurface = NULL;

    //Current displayed PNG image
    SDL_Surface *gPNGSurface = NULL;

    //The music that will be played
    Mix_Music *gMusic = NULL;

public:
    bool init();
    bool loadMedia();
    void playMusic();
    void applyPicture();
    void generateFood();
    void close();
};