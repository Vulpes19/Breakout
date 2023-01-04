#include "GameObject.hpp"

void    GameObject::loadTexture( int x, int y, int width, int height, std::string ID )
{
    this->x = x;
    this->y = y;
    this->w = width;
    this->h = height;
    this->texture = ID;
    frame = 1;
    row = 1;
}

void    GameObject::draw( SDL_Renderer *renderer )
{
    Texture::getInstance().draw( texture, x, y, w, h, renderer );
}


