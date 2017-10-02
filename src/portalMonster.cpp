/**
    \file portal.cpp
    This file implements the portal class
*/
#include <portalMonster.hpp>

PortalMonster::~PortalMonster(){}

/**
    This method initiates the portal in the game scene
    \return return a true value that make the portal active
*/

bool PortalMonster::init() {

    /*
        _main_game_object->main_positionX = 00;
        _main_game_object->main_positionY = 00;
    */

    interator = 0;
    timestep = 0;
    monster_number = 0;

    return true;

}

/**
    This method is responsible for updating portal positions in the game for 
    monsters to appear
*/

void PortalMonster::update() {

    if( timestep < Game::instance.timer->getTicks() &&
        m_monsters[interator]->state() == GameObject::State::disabled &&
        _main_game_object->main_positionX > 0 && 
        _main_game_object->main_positionX + _main_game_object->main_width < 800
      ) {

        m_monsters[interator]->main_positionX = _main_game_object->main_positionX;
        m_monsters[interator]->main_positionY = _main_game_object->main_positionY;
        m_monsters[interator]->setState(GameObject::State::enabled);

        monster_number++;
        
        timestep = Game::instance.timer->getTicks() + 3000;
    }else{
        // Do nothing
    }

    interator = (interator + 1) % m_monsters.size();

    if( monster_number <= 5 && m_background->imagePart->x == 0 ) {
        
        m_portal_pos->m_init_posX = 650;
    
    }else{
        // Do nothing
    }

    if( monster_number < 10 && monster_number > 5 ) {
        
        m_portal_pos->m_init_posX = 1200;
    }
    else{
        // Do nothing
    }

    if( monster_number < 20 && monster_number > 10 ) {
        
        m_portal_pos->m_init_posX = 1600;
    
    }else{
        // Do nothing
    }

    if( monster_number > 20 ) {
        
        _main_game_object->setState(GameObject::State::disabled);
    
    }else{
        // Do nothing
    }


}

//so chamar na main

/**
    This method is responsible for add a monster no game through the portal
    @param monster specifies the monster that enters the game 
*/
void PortalMonster::add_monster( GameObject* monster ){
    
    monster->setState( GameObject::State::disabled );
    m_monsters.push_back( monster );
    
}
