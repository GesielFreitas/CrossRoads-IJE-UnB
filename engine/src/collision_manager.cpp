/**
    \file collision_manager.cpp
    This file declares the CollisionManager class
*/
#include "collision_manager.hpp"
#include "game.hpp"

using namespace engine;

CollisionManager::CollisionManager(){}
CollisionManager::~CollisionManager(){}

/**
    This method is responsible for getting collisions from the game objects
    \param *objects
    \parblock
        Is a input parameter that represents objects of the game(!=NULL)
    \endparblock
*/
void CollisionManager::getCollisions( std::list <GameObject*> *objects ) {
    
    collision_list = objects;

}

GameObject* CollisionManager::checkCollision( GameObject* game_object, 
                                             std::string type ) {
  
    for (std::list<GameObject*>::iterator obj = collision_list->begin(); 
         obj != collision_list->end(); ++obj){
        if( ( *obj )->type == type && collide( game_object, *obj ) ) {
            return (*obj);
        }
        else{
          // Do nothing
        }
    }

    return NULL;

}

/**
    This method is responsible for colliding objects and repositioning them
    \param obj1, obj2
    \parblock
        Is a input parameter that represents objects of the game(!=NULL)
    \endparblock
    \return return a true value to result of objects intersection 
*/
bool CollisionManager::collide( GameObject* obj1, GameObject* obj2 ) {
  
  rectangle_one.x = obj1->main_positionX; 
  rectangle_one.y = obj1->main_positionY;
  rectangle_one.h = obj1->main_height;
  rectangle_one.w = obj1->main_width;
  rectangle_two.x = obj2->main_positionX;
  rectangle_two.y = obj2->main_positionY;
  rectangle_two.h = obj2->main_height;
  rectangle_two.w = obj2->main_width;

  return SDL_IntersectRect(&rectangle_one, &rectangle_two, &result);

}
