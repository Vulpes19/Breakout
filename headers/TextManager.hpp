#pragma once

#include <iostream>
#include <map>
#include <SDL.h>
#include <SDL_ttf.h>

class Text
{
    public:
        static Text &getInstance( void );
        bool    loadFont( const char *fontPath, std::string ID );
        void    writeText( std::string ID, int x, int y, int width,
            int height, SDL_Renderer *renderer, const char *toDisplay, SDL_Color color );
    private:
        Text( void );
        ~Text( void );
        static Text  *instancePtr;
        std::map<std::string, TTF_Font *> fonts;
};
