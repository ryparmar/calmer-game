#include "Game.hpp"

int main(int argc, char *args[])
{
    Game *game = new Game();

    //Start up SDL and create window
    if (!game->init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!game->loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            while (!quit)
            {
                //Handle events on queue
                while (SDL_PollEvent(&e) != 0)
                {
                    //User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }

                // game->applyPicture();
                game->playMusic();
                game->generateFood();
            }

            //Stop the music
            // Mix_HaltMusic();
        }
    }

    //Free resources and close SDL
    game->close();

    return 0;
}