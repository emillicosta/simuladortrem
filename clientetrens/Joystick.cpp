#ifndef _JOYSTICK_ 
#define _JOYSTICK_

#include <iostream>

#include "GPIO.cpp"

#define ANGULO_MIN 18
#define ANGULO_MAX 82

using namespace std;

class Joystick{
    private:
        
    public:
        
        Joystick(){
            
    	    GPIO::setup(PORTNUMBER::P9_39);			        //Porta analógica do potenciômetro
    	    GPIO::setup(PORTNUMBER::P9_14,DIRECTION::IN); 	//Porta digital do botão 1 (ACTION)
            GPIO::setup(PORTNUMBER::P9_41,DIRECTION::IN);   //Porta digital do botão 2 (UP)
            GPIO::setup(PORTNUMBER::P9_16,DIRECTION::IN);   //Porta digital do botão 3 (DOWN)
        }
        
        int valorBotaoAction(){
            return GPIO::input(PORTNUMBER::P9_14);
        }
        
        int valorBotaoUp(){
            return GPIO::input(PORTNUMBER::P9_41);
        }

        int valorBotaoDown(){
            return GPIO::input(PORTNUMBER::P9_16);
        }
   
        int escolherVelocidade(){

    	    return GPIO::input(PORTNUMBER::P9_39)/32; 
        }
        
};
#endif
