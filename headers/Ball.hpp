#pragma once

#define HEIGHT 704
#define WIDTH 1088
#include "GameObject.hpp"
#include "Player.hpp"
#include "LevelManager.hpp"

class   Ball : public GameObject
{
    public:
        Ball( void );
        virtual ~Ball( void ) {};
        void    loadTexture( int x, int y, int width, int height, std::string ID );
        void    draw( SDL_Renderer *renderer );
        void    update( Player &player );
        void    wallCollision( Player &player );
        void    bricksCollision( void );
        // void    handleCollision( Player &player );
    private:
        double  radius;
};
