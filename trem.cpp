#include "trem.h"
#include <iostream>

Trem::Trem(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    tempo_parado = 120;
    enable = true;

    semaforo0 = new Semaforo(1230,1,IPC_CREAT|0600);
          semaforo1 = new Semaforo(1231,1,IPC_CREAT|0600);
          semaforo2 = new Semaforo(1232,1,IPC_CREAT|0600);
          semaforo3 = new Semaforo(1233,1,IPC_CREAT|0600);
          semaforo4 = new Semaforo(1234,1,IPC_CREAT|0600);
          semaforo5 = new Semaforo(1235,1,IPC_CREAT|0600);
          semaforo6 = new Semaforo(1236,1,IPC_CREAT|0600);
          semaforo7 = new Semaforo(1237,1,IPC_CREAT|0600);
          semaforo8 = new Semaforo(1238,1,IPC_CREAT|0600);
          semaforo9 = new Semaforo(1239,1,IPC_CREAT|0600);
}

Trem::~Trem()
{
    threadTrem.join();
}

void Trem::setTempoParado(int tempo_parado)
{
    this->tempo_parado = tempo_parado;
}

void Trem::setId(int id)
{
    this->id = id;
}

int Trem::getTempoParado()
{
    return this->tempo_parado;
}

int Trem::getId()
{
    return this->id;
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
                if (y == 120 && x <120){
                    if(x==100){
                        if(semaforo1->getContador()>0){
                            semaforo1->P();
                            semaforo0->P();
                            x+=10;
                        }
                    }else{x+=10;}
                }else{
                    if (x == 120 && y < 300){
                        if(semaforo1->getContador()>0){
                            semaforo1->P();
                            semaforo0->P();
                        }
                        y+=10;
                    }else{
                        if (x > 20 && y == 300){
                            if(x==100){
                                semaforo1->V();
                                semaforo0->V();
                            }
                           x-=10;
                        }else{
                            y-=10;
                        }
                    }
                }
            }
            break;
        case 2:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x <280){
                    if(x==140)
                        semaforo0->V();
                    if(x==260) {
                        if(semaforo2->getContador()>0){
                            semaforo2->P();
                            x+=10;
                        }
                    }else{x+=10;}
                }else if (x == 280 && y < 180){
                    if(semaforo2->getContador()>0){
                        semaforo2->P();
                    }
                    if(y==160){
                        if(semaforo4->getContador()>0){
                            semaforo4->P();
                            y+=10;
                        }
                    }else
                        y+=10;
                }else if (x > 120 && y == 180){
                    if(x==140) {
                        if(semaforo0->getContador()>0){
                            semaforo0->P();
                            x-=10;
                        }
                    }else{
                        if(semaforo4->getContador()>0&&x>200)
                            semaforo4->P();
                        if(x==260)
                            semaforo2->V();
                        if(x==200)
                            semaforo4->V();
                        x-=10;
                    }
                }else
                    y-=10;
            }
            break;
        case 3:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 240 && x <280){
                    if(x==140)
                        semaforo1->V();
                    if(x==260) {
                        if(semaforo3->getContador()>0){
                            semaforo3->P();
                            x+=10;
                        }
                    }else{
                        if(x==180) {
                            if(semaforo6->getContador()>0){
                                semaforo6->P();
                                x+=10;
                            }
                        }else{
                            x+=10;
                        }
                    }
                }else{
                    if (x == 280 && y < 300){
                        if(semaforo3->getContador()>0){
                            semaforo3->P();
                        }
                        if(y==260)
                            semaforo6->V();
                        y+=10;
                    }else{
                        if (x > 120 && y == 300){
                            if(x==140) {
                                if(semaforo1->getContador()==1){
                                    semaforo1->P();
                                    x-=10;
                                }
                            }else{
                                if(x==260)
                                    semaforo3->V();
                                x-=10;
                            }
                        }else
                            y-=10;
                    }
                }
            }
            break;
        case 4:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 180 && x <360){
                    if(x==300)
                        semaforo4->V();
                    x+=10;
                }else if (x == 360 && y < 240){
                    if(y==200)
                        semaforo5->V();
                    if(y==220){
                        if(semaforo6->getContador()>0||semaforo7->getContador()>0){
                            semaforo6->P();
                            semaforo7->P();
                            y+=10;
                        }
                    }else
                        y+=10;
                }else if (x > 200 && y == 240){
                    if(x==260)
                        semaforo7->V();
                    x-=10;
                }else{
                    if(y==200){
                        if(semaforo4->getContador()>0||semaforo5->getContador()>0){
                            semaforo4->P();
                            semaforo5->P();
                            y-=10;
                        }
                    }else{
                        if(y==220)
                            semaforo6->V();
                        y-=10;
                    }
                }
            }
            break;
        case 5:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x <440){
                    if(x==420) {
                        if(semaforo8->getContador()>0){
                            semaforo8->P();
                            x+=10;
                        }
                    }else{
                        if(x==300)
                            semaforo2->V();
                        x+=10;
                    }
                }else if (x == 440 && y < 180)
                    y+=10;
                else if (x > 280 && y == 180){
                    if(semaforo5->getContador()>0&&x<320)
                        semaforo5->P();
                    if(x==420)
                        semaforo8->V();
                    if(x==300) {
                        if(semaforo2->getContador()>0){
                            semaforo2->P();
                            x-=10;
                        }
                    }else{
                        if(x==380) {
                            if(semaforo5->getContador()>0){
                                semaforo5->P();
                                x-=10;
                            }
                        }else{
                            x-=10;
                        }
                    }
                }else{
                    if(semaforo2->getContador()>0)
                        semaforo2->P();
                    if(y==160)
                        semaforo5->V();
                    y-=10;
                }
            }
            break;

        case 6:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 240 && x <440){
                    if(x==420) {
                        if(semaforo9->getContador()>0){
                            semaforo9->P();
                            x+=10;
                        }
                    }else{
                        if(x==300)
                            semaforo3->V();
                        if(x==380)
                            semaforo7->V();
                        if(semaforo7->getContador()>0&&x<340)
                            semaforo7->P();
                        x+=10;
                    }
                }else if (x == 440 && y < 300){
                    if(semaforo9->getContador()>0){
                        semaforo9->P();
                    }
                    y+=10;
                }else if (x > 280 && y == 300){
                    if(x==420)
                        semaforo9->V();
                    if(x==300) {
                        if(semaforo3->getContador()>0){
                            semaforo3->P();
                            x-=10;
                        }
                    }else{x-=10;}
                }else{
                    if(semaforo3->getContador()>0)
                        semaforo3->P();
                    if(y==260) {
                        if(semaforo7->getContador()>0){
                            semaforo7->P();
                            y-=10;
                        }
                    }else{y-=10;}
                }
            }
            break;
        case 7:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x <540){
                    if(x==460)
                        semaforo8->V();
                        semaforo9->V();
                    x+=10;
               }else if (x == 540 && y < 300)
                    y+=10;
                else if (x > 440 && y == 300){
                    if(x==460){
                        if(semaforo8->getContador()>0){
                            semaforo8->P();
                            semaforo9->P();
                            x-=10;
                        }
                    }else{x-=10;}
                }else{
                    if(semaforo8->getContador()>0){
                        semaforo8->P();
                    }
                    if(semaforo9->getContador()>0){
                        semaforo9->P();
                    }
                    y-=10;
                }
            }
            break;
        default:
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(tempo_parado));
    }
}
