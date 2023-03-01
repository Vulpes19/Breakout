/*
 * =========================================================
 *____   ____     ___   ____  __  _   ___   __ __  ______  
 *|    \ |    \   /  _] /    ||  |/ ] /   \ |  |  ||      |
 *|  o  )|  D  ) /  [_ |  o  ||  ' / |     ||  |  ||      |
 *|     ||    / |    _]|     ||    \ |  O  ||  |  ||_|  |_|
 *|  O  ||    \ |   [_ |  _  ||     \|     ||  :  |  |  |  
 *|     ||  .  \|     ||  |  ||  .  ||     ||     |  |  |  
 *|_____||__|\_||_____||__|__||__|\_| \___/  \__,_|  |__|  
 * 
 * Game.hpp: 
 * 
 * =========================================================
 */

#pragma once

#define HEIGHT 704
#define WIDTH 1088
#define REPLAY_BUTTON 3
#define QUIT_BUTTON 4
#define NO_BUTTON 5
#define MODE_BUTTON 6
#define STANDARD 7
#define LEET 8
#define PYRAMID 9
#define CRAZY 10
#include <SDL.h>
#include <vector>
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#include "InputHandling.hpp"
#include "StateControl.hpp"
#include "GameStates.hpp"
#include "MainMenu.hpp"
#include "PlayState.hpp"
#include "PauseMenu.hpp"
#include "GameOver.hpp"
#include "LevelManager.hpp"
#include "ParticleSystem.hpp"
#include "AudioManager.hpp"
#include "LevelMenu.hpp"
#include "HighScore.hpp"


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
		int score;
		int lives;
		bool    hit;
		Player  player;
		Ball    ball;
		HighScore highScore;
		StateControl   *states;
		std::vector<Particles> particles;
};
