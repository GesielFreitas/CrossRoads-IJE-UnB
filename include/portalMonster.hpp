/**
    \file porta.hpp
    This file declares the porta class
*/
#ifndef _PORTAL_MONSTER_HPP_
#define _PORTAL_MOSNTER_HPP_

#include <iostream>
#include <vector>

#include "game.hpp"
#include "gameobject.hpp"
#include "components/component.hpp"
#include "components/image.hpp"
#include "cameraposition.hpp"

using namespace engine;


/**
    \class portal
    This class is responsible for create a portal for monsters appear in the game
*/

class PortalMonster : public Component{

public:
    PortalMonster( GameObject &main_game_object, std::string id, 
            ImageComponent *background, CameraPosition *portal_pos):
        
        Component( main_game_object, id), 
        interator( 0 ), 
        m_background( background ), 
        m_portal_pos( portal_pos ){}
        ~PortalMonster();

        bool init();
    
        void update();
        void add_monster(GameObject* monster);

private:
    std::vector <GameObject*> m_monsters;

/** 
    
    controls the time of the previous scene.

*/        
    unsigned int timestep;

/**
    number monster of passed in portal

*/
    unsigned int interator;

/**

    number monster of scene
*/
    unsigned int monster_number;

/**
    
    image of the backgrount in portal of monster

*/
    ImageComponent *m_background;

/**
    
    is position of the portal in camera

*/    
    CameraPosition *m_portal_pos;
  
};

#endif  // _PORTAL_HPP_