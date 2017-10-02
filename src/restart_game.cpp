/**
    \file restart.cpp
    This file implements the restart class
*/
#include "restart_game.hpp"

/**
    This method initiates the restart in the game.
    \return return a true value.
*/

bool RestartGame::init(){return true;}


/**
    This method is responsible for updating que restart in game
*/

void RestartGame::update(){

    if(Game::instance.keyboard->isKeyDown("enter")){
        Game::instance.change_scene("Main Menu");
    }
    else{
    	// Do nothing
    }

}

RestartGame::~RestartGame(){}
