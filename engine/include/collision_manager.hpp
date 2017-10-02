/**
    \file collision_manager.hpp
    This file declares the CollisionManager class
*/
#ifndef COLLISION_MANAGER_HPP_
#define COLLISION_MANAGER_HPP_

#include <iostream>
#include <list>
#include <iterator>

#include "sdl2core.hpp"
#include "gameobject.hpp"

namespace engine {

    /// Class to control object collisions
    /**
        \class CollisionManager
        This class is responsible for managing collision of objects in the game   
    */
    class CollisionManager {

    public:
        CollisionManager();
        ~CollisionManager();
      
        void getCollisions( std::list <GameObject*> *objects );

        GameObject* checkCollision( GameObject* game_object, std::string type );

    private:
        bool collide( GameObject* obj1, GameObject* obj2 );

        std::list <GameObject*>* collision_list;

        SDL_Rect rectangle_one;
        SDL_Rect rectangle_two;
        SDL_Rect result;

    };

}

#endif  // COLLISION_MANAGER_HPP_
