#include "trem.h"

Trem::Trem(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    tempo_parado = 50;
    enable = true;
}

Trem::~Trem()
{
    threadTrem.join();
}

void Trem::setTempoParado(int tempo_parado)
{
    this->tempo_parado = tempo_parado;
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}

void Trem::start()
{
    threadTrem = std::thread(&Trem::run,this);
}

void Trem::run()
{
    while(true){
        switch(id){
        case 1:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x <120)
                    x+=10;
                else if (x == 120 && y < 300)
                    y+=10;
                else if (x > 20 && y == 300)
                    x-=10;
                else
                    y-=10;
            }
            break;
        case 2:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x <280)
                    x+=10;
                else if (x == 280 && y < 180)
                    y+=10;
                else if (x > 120 && y == 180)
                    x-=10;
                else
                    y-=10;
            }
            break;
        case 3:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 240 && x <280)
                    x+=10;
                else if (x == 280 && y < 300)
                    y+=10;
                else if (x > 120 && y == 300)
                    x-=10;
                else
                    y-=10;
            }
            break;
        case 4:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 180 && x <360)
                    x+=10;
                else if (x == 360 && y < 240)
                    y+=10;
                else if (x > 200 && y == 240)
                    x-=10;
                else
                    y-=10;
            }
            break;
        case 5:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x <440)
                    x+=10;
                else if (x == 440 && y < 180)
                    y+=10;
                else if (x > 280 && y == 180)
                    x-=10;
                else
                    y-=10;
            }
            break;

        case 6:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 240 && x <440)
                    x+=10;
                else if (x == 440 && y < 300)
                    y+=10;
                else if (x > 280 && y == 300)
                    x-=10;
                else
                    y-=10;
            }
            break;
        case 7:
            //(1,80,120);7,450,120
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x <540)
                    x+=10;
                else if (x == 540 && y < 300)
                    y+=10;
                else if (x > 440 && y == 300)
                    x-=10;
                else
                    y-=10;
            }
            break;
        default:
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(tempo_parado));
    }
}

