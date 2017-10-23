/**
    \file stage1_scene.cpp
    This file define methods content of the Stage1Scene class
*/

#include "stage1_scene.hpp"
#include "assert.h"

/// Initializes and keeps the scene of the first stage

const int MAX_SCREEN_WIDTH = 800;
const int BULLET_PSOTION_ITERATOR = 20;
const int TIME_STEP_ITERATOR = 500;
const int BACKGROUND_IMAGE_MAX = 2190;

void Stage1Scene::setTimeStep(unsigned int timeStep) {
    timestep = timeStep;
}

unsigned int Stage1Scene::getTimeStep() {
    return timestep;
}

/**
    Initializes the scene of the first stage and assigns behavior in his
    execution
*/
void Stage1Scene::game_logic() {


    background = &get_game_object("backgroundForest");

    bullet1 = &get_game_object("bullet");

    player = &get_game_object("player");
    player_controller = (dynamic_cast<Player*>(
                         player->get_component("player_logic")));


    ground_stage1 = &get_game_object("ground");
    back_img = (dynamic_cast<ImageComponent*>(
        background->get_component("backgroundForest")));
    go_arrow = &get_game_object("go_arrow");
    portal = &get_game_object("portal");

    monster1 = &get_game_object("monster1");
    monster2 = &get_game_object("monster2");
    monster3 = &get_game_object("monster3");
    monster4 = &get_game_object("monster4");

    assert(ground_stage1 != NULL);

    ground_stage1->main_positionY = 552;
    ground_stage1->main_positionX = 0;
    ground_stage1->main_width = 800;
    ground_stage1->main_height = 200;

    fire_ball = &get_game_object("fireball");

    assert(back_img != NULL);
    assert(fire_ball != NULL);


    if( back_img->imagePart->x > BACKGROUND_IMAGE_MAX ) {
        back_img->enable_camera = false;
    }
    else {
        fire_ball->setState(GameObject::State::disabled);
    }

    assert(portal != NULL);
    assert(go_arrow != NULL);

    if( ( portal->state() == GameObject::State::enabled &&
        portal->main_positionX + portal->main_width < MAX_SCREEN_WIDTH ) ||
        back_img->image_measures->x > BACKGROUND_IMAGE_MAX ||
        is_inside(monster1) ||
        is_inside(monster2) ||
        is_inside(monster3) ||
        is_inside(monster4) ) {
        back_img->enable_camera = false;
        go_arrow->setState(GameObject::State::disabled);
    }
    else {
        back_img->enable_camera = true;
        go_arrow->setState(GameObject::State::enabled);
    }

    bullet();

}

/**
    Is responsible for starting the bullet attack
*/
void Stage1Scene::bulletAttack() {

    if( bullet1->state() == GameObject::State::disabled ) {
        bulletDir1 = player_controller->get_direction_boby_side();
        bullet1->main_positionX = player->main_positionX +
                                  player->main_width;
        bullet1->main_positionY = player->main_positionY;
    }
    else {
        // Do nothing
    }

    setTimeStep(Game::instance.timer->getTicks() + TIME_STEP_ITERATOR);
    bullet1->setState(GameObject::State::enabled);
}

/**
    Moves the bullet in the direction selected
*/
void Stage1Scene::increaseBulletPosition() {
    if( bullet1->state() == GameObject::State::enabled ) {
        if( bulletDir1 ) {
            bullet1->main_positionX += BULLET_PSOTION_ITERATOR;
        }
        else {
            bullet1->main_positionX -= BULLET_PSOTION_ITERATOR;
        }
    }
    else {
        // Do nothing
    }

}

/**
    Disable bullet attack
*/
void Stage1Scene::disableBullet() {
    if( bullet1->main_positionX > MAX_SCREEN_WIDTH || bullet1->main_positionX < 0 ) {
        bullet1->setState(GameObject::State::disabled);
    }
    else {
        // Do nothing
    }
}

/**
    Detects and define the position of the player's bullet(ranged attack)
    on the scene
*/
void Stage1Scene::bullet() {

    assert(player_controller != NULL);

    if( player_controller->is_attacking_ranged &&
        getTimeStep() < Game::instance.timer->getTicks() ) {

        bulletAttack();
    }
    else {
        // Do nothing
    }

    increaseBulletPosition();

    disableBullet();

}

/**
    Check if a object is inside the scene
    \param object
    \parblock
        Is a input parameter that represents an object of the game(!=NULL)
    \endparblock
    \return true is inside
    \return false isn't inside
*/
bool Stage1Scene::is_inside( GameObject* object ) {

    assert(object != NULL);

    if( object->state() == GameObject::State::enabled &&
      ( object->main_positionX > 0 || object->main_positionX +
                                      object->main_width < MAX_SCREEN_WIDTH ) ) {

        return true;

    }
    else {
        return false;
    }
}

Stage1Scene::~Stage1Scene(){

}
