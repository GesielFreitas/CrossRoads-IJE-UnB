#include "scene.hpp"

using namespace engine;

//Definição de game object inválido
GameObject INVALID_GAME_OBJECT;

bool Scene::add_game_object(GameObject &obj){
    auto id = obj.name();
    Log::instance.info("Adding GameObject '"+ id +"' to scene '" + scene_name +"'.");

    //Iterando mapa para ver se aquele game object já existe nela
    if (scene_objects.find(id) != scene_objects.end()){
        Log::instance.warning("Game object já existe!");
        return false;
    }

    scene_objects[id] = &obj;
    return true;
}

GameObject &Scene::get_game_object(const std::string &id){

    if(scene_objects.find(id) == scene_objects.end()){
        Log::instance.warning("Não foi possível encontrar o GameObject '" + id +"'.");
        return INVALID_GAME_OBJECT;
    }

    return *scene_objects[id];
}

bool Scene::remove_game_object(const std::string &id){

    Log::instance.info("Removendo GameObject '" + id +"' da Scene.");

    if(scene_objects.find(id) == scene_objects.end()){
        Log::instance.warning("Não foi possível encontrar o GameObject '" + id +"'.");
        return false;
    }

    scene_objects.erase(id);
    return true;
}

bool Scene::init(){
    Log::instance.info("Inicializando cena '" + scene_name +"'.");

    //Iterando o mapa e inicilizando cada um dos game objects.
    for(auto id_obj: scene_objects){
        auto obj = id_obj.second;
        if(obj->state() == GameObject::State::enabled && obj->init() == false)
            return false;
    }

    return true;
}

bool Scene::shutdown(){
    Log::instance.info("Destruindo cena '" + scene_name +"'.");

    //Iterando o mapa e inicilizando cada um dos game objects.
    for(auto id_obj: scene_objects){
        auto obj = id_obj.second;
        if(obj->state() == GameObject::State::enabled && obj->shutdown() == false)
            return false;
    }

    return true;
}

void Scene::update()
{
    for (auto id_obj: scene_objects)
    {
        auto obj = id_obj.second;
        if (obj->state() == GameObject::State::enabled) obj->update();
    }
}

bool Scene::draw(){
  GameObject::Layer layers[] ={GameObject::Layer::background,
			       GameObject::Layer::layer1,
			       GameObject::Layer::layer2,
			       GameObject::Layer::layer3};
  
  //Iterando o mapa e inicilizando cada um dos game objects.
  for(int cont = 0; cont<4;cont++){
    for(auto id_obj: scene_objects){
      auto obj = id_obj.second;
      if(obj->m_layer == layers[cont] && obj->state() == GameObject::State::enabled && obj->draw() == false)
	return false;
    }
  }

    return true;
}

std::list <GameObject *> * Scene::get_collide_objects(){
    //Iterando o mapa e inicilizando cada um dos game objects.
    for(auto id_obj: scene_objects){
        auto obj = id_obj.second;
       if(obj->state() == GameObject::State::enabled && obj->m_collision == true)
	 collide_objects.push_back(obj);
    }

    return &collide_objects; 
}

void Scene::clear_collide_objects(){
  collide_objects.clear();
}

void Scene::game_logic(){}
