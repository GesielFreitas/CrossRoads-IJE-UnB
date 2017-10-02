/**
    \file restart.hpp
    This file declares the restart class
*/
#ifndef __RESTART_GAME_HPP__
#define __RESTART_GAME_HPP__

#include <iostream>

#include "components/component.hpp"
#include "components/animation_controller.hpp"
#include "game.hpp"
#include "Logger.hpp"

using namespace engine;

/**
    \class Restart
    This class is responsible for restart in the game
*/

class RestartGame : public Component{
public:
    RestartGame( GameObject &main_game_object, std::string id ):
        Component( main_game_object, id ){}

        ~RestartGame();

        bool init();
        void update();

private:

};

#endif  // __RESTART_HPP__
