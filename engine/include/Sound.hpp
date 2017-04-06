#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>

namespace engine{

    class Sound{

    public:
        //constructor
        Sound();
        //destructor
        ~Sound();
        //
        bool loadSound(std::string);

        void playSound();



    private:
        //The music that will be played
        Mix_Chunk *gSound;

    };

}