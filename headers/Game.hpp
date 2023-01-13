#pragma once

#include <SDL.h>
#include "TextureManager.hpp"
#include "Player.hpp"
#include "InputHandling.hpp"
#include "StateControl.hpp"
#include "GameStates.hpp"
#include "MainMenu.hpp"
#include "PlayState.hpp"

class Game
{
    public:
        Game( void );
        ~Game( void );
        bool    init( const char *, int, int, int, int );
        void    render( void );
        void    handleEvents( void );
        void    clean( void );
        bool    getRunning( void ) { return (running); };
        void    update( void );
    private:
        bool running;
        SDL_Event   event;
        SDL_Window  *window;
        SDL_Renderer    *renderer;
        int         currentFrame;
        Player  player;
        StateControl   *states;
};
