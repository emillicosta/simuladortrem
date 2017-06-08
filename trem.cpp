#include "trem.h"
#include <iostream>

Trem::Trem(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    tempo_parado = 0;
    enable = true;
    tempo =0;

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
float Trem::getTempo()
{
    return this->ultimo_tempo;
}

float Trem::getMedia()
{
    return this->media;
}

void Trem::setSemaforo(Semaforo *s0, Semaforo *s1, Semaforo *s2, Semaforo *s3, Semaforo *s4, Semaforo *s5, Semaforo *s6, Semaforo *s7, Semaforo *s8, Semaforo *s9)
{
    semaforo0=s0;
    semaforo1=s1;
    semaforo2=s2;
    semaforo3=s3;
    semaforo4=s4;
    semaforo5=s5;
    semaforo6=s6;
    semaforo7=s7;
    semaforo8=s8;
    semaforo9=s9;
}

void Trem::start()
{
    threadTrem = std::thread(&Trem::run,this);
}

void Trem::run()
{
    while(true){
        if(tempo_parado>0){
        switch(id){
        case 1:
            if (enable)
            {

               emit updateGUI(id,x,y);
               if (y == 120 && x ==30){
                    ultimo_tempo=tempo;
                    qtdvoltas++;
                    tempo_total = tempo_total+tempo;
                    if(qtdvoltas==0)
                        media=tempo_total;
                    else
                        media=tempo_total/qtdvoltas;
                    tempo=0;

               }
               tempo = tempo + float(tempo_parado*0.001);


               if (y == 120 && x <120){
                   if(x == 100){
                       if(semaforo1->getContador()){
                           semaforo1->P();
                           x+=10;
                       }
                   }else{
                       x+=10;
                   }
               }else{
                   if (x == 120 && y < 300){
                       if(y < 200){
                           if(semaforo1->getContador()>0)
                               semaforo1->P();
                       }
                       if(y > 220){
                           if(semaforo0->getContador()>0)
                               semaforo0->P();
                       }
                       if(y==200){
                           if(!semaforo1->getContador())
                               semaforo1->V();
                       }
                       if(y==220){
                           if(semaforo0->getContador()){
                               semaforo0->P();
                               y+=10;
                           }
                       }else{
                           y+=10;
                       }
                   }else{
                       if (x > 20 && y == 300){
                           if(x==100){
                               if(!semaforo0->getContador())
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
                if (y == 120 && x ==130){
                     ultimo_tempo=tempo;
                     qtdvoltas++;
                     tempo_total = tempo_total+tempo;
                     if(qtdvoltas==0)
                         media=tempo_total;
                     else
                         media=tempo_total/qtdvoltas;
                     tempo=0;

                }
                tempo = tempo + float(tempo_parado*0.001);


               if (y == 120 && x <280){
                   if(x==140){
                       if(!semaforo1->getContador())
                           semaforo1->V();
                   }
                   if(x==260) {
                       if(semaforo2->getContador() && semaforo4->getContador()){
                           semaforo2->P();
                           semaforo4->P();
                           x+=10;
                       }
                   }else{
                       x+=10;
                   }
               }else if (x == 280 && y < 180){
                   if(semaforo2->getContador())
                       semaforo2->P();
                   y+=10;
               }else if (x > 120 && y == 180){
                   if(x == 140){
                       if(semaforo1->getContador()){
                           semaforo1->P();
                           x-=10;
                       }
                   }else{
                       if(x==260){
                           if(!semaforo2->getContador())
                               semaforo2->V();
                       }
                       if(x==190)
                           if(!semaforo4->getContador())
                               semaforo4->V();
                       if(x>200){
                           if(semaforo4->getContador())
                               semaforo4->P();
                       }
                       x-=10;
                   }
               }else{
                   if(semaforo1->getContador()){
                       semaforo1->P();
                   }
                   y-=10;
               }
            }
            break;
        case 3:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 240 && x ==130){
                     ultimo_tempo=tempo;
                     qtdvoltas++;
                     tempo_total = tempo_total+tempo;
                     if(qtdvoltas==0)
                         media=tempo_total;
                     else
                         media=tempo_total/qtdvoltas;
                     tempo=0;

                }
                tempo = tempo + float(tempo_parado*0.001);

               if (y == 240 && x <280){
                   if(x==140){
                       if(!semaforo0->getContador())
                           semaforo0->V();
                   }
                   if(x>180){
                       if(semaforo6->getContador())
                           semaforo6->P();
                   }
                   if(x==180) {
                       if(semaforo3->getContador() && semaforo6->getContador()){
                           semaforo3->P();
                           semaforo6->P();
                           x+=10;
                       }
                   }else{
                       x+=10;
                   }
               }else{
                   if (x == 280 && y < 300){
                       if(semaforo3->getContador())
                           semaforo3->P();
                       if(y==260){
                           if(!semaforo6->getContador())
                               semaforo6->V();
                       }
                       y+=10;

                   }else{
                       if (x > 120 && y == 300){
                           if(x==260){
                               if(!semaforo3->getContador())
                                   semaforo3->V();
                           }
                           if(x == 140){
                               if(semaforo0->getContador()){
                                   semaforo0->P();
                                   x-=10;
                               }
                           }else{
                               x-=10;
                           }
                       }else{
                           if(semaforo0->getContador()){
                               semaforo0->P();
                           }
                           y-=10;
                       }
                   }
               }
            }
            break;
        case 4:
            if (enable)
            {
               emit updateGUI(id,x,y);
                if (y == 190 && x ==200){
                     ultimo_tempo=tempo;
                     qtdvoltas++;
                     tempo_total = tempo_total+tempo;
                     if(qtdvoltas==0)
                         media=tempo_total;
                     else
                         media=tempo_total/qtdvoltas;
                     tempo=0;

                }
                tempo = tempo + float(tempo_parado*0.001);

               if (y == 180 && x <360){
                   if(x==300){
                       if(!semaforo4->getContador())
                           semaforo4->V();
                   }
                   if(x<300){
                       if(semaforo4->getContador())
                           semaforo4->P();
                   }
                   if(x>300){
                       if(semaforo5->getContador())
                           semaforo5->P();
                   }
                   x+=10;
               }
               else if (x == 360 && y < 240){
                   if(y==200){
                       if(!semaforo5->getContador())
                           semaforo5->V();
                   }
                   if(y==220){
                       if(semaforo6->getContador() && semaforo7->getContador()){
                           semaforo6->P();
                           semaforo7->P();
                           y+=10;
                       }
                   }else{
                       y+=10;
                   }
               }else if (x > 200 && y == 240){
                   if(x <= 280){
                       if(semaforo6->getContador())
                           semaforo6->P();
                   }
                   if(x > 280){
                       if(semaforo7->getContador())
                           semaforo7->P();
                   }
                   if(x==280){
                       if(!semaforo7->getContador())
                           semaforo7->V();
                   }
                   x-=10;
               }else{
                   if(y==220){
                       if(!semaforo6->getContador())
                           semaforo6->V();
                   }
                   if(y==200){
                       if(semaforo4->getContador() && semaforo5->getContador()){
                           semaforo4->P();
                           semaforo5->P();
                           y-=10;
                       }
                   }else{
                       y-=10;
                   }
               }
            }
            break;
        case 5:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x ==290){
                     ultimo_tempo=tempo;
                     qtdvoltas++;
                     tempo_total = tempo_total+tempo;
                     if(qtdvoltas==0)
                         media=tempo_total;
                     else
                         media=tempo_total/qtdvoltas;
                     tempo=0;

                }
                tempo = tempo + float(tempo_parado*0.001);

               if (y == 120 && x <440){
                   if(x==300){
                       if(!semaforo2->getContador())
                           semaforo2->V();
                   }
                   if(x==420){
                       if(semaforo8->getContador()){
                           semaforo8->P();
                           x+=10;
                       }
                   }else{
                       x+=10;
                   }
               }else if (x == 440 && y < 180){
                   if(semaforo8->getContador())
                       semaforo8->P();
                    y+=10;
               }else if (x > 280 && y == 180){
                   if(x < 380){
                       if(semaforo5->getContador())
                           semaforo5->P();
                   }
                   if(x==420){
                       if(!semaforo8->getContador())
                           semaforo8->V();
                   }
                   if(x==380){
                       if(semaforo2->getContador() && semaforo5->getContador()){
                           semaforo2->P();
                           semaforo5->P();
                           x-=10;
                       }
                   }else{
                       x-=10;
                   }
               }else{
                   if(semaforo2->getContador()>0)
                       semaforo2->P();
                   if(y==160){
                       if(!semaforo5->getContador())
                           semaforo5->V();
                   }
                   y-=10;
               }
            }
            break;

        case 6:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 240 && x ==370){
                     ultimo_tempo=tempo;
                     qtdvoltas++;
                     tempo_total = tempo_total+tempo;
                     if(qtdvoltas==0)
                         media=tempo_total;
                     else
                         media=tempo_total/qtdvoltas;
                     tempo=0;

                }
                tempo = tempo + float(tempo_parado*0.001);


               if (y == 240 && x <440){
                   if(x==300){
                       if(!semaforo3->getContador())
                           semaforo3->V();
                   }
                   if(x==380){
                       if(!semaforo7->getContador())
                           semaforo7->V();
                   }
                   if(x<380){
                       if(semaforo7->getContador())
                           semaforo7->P();
                   }
                   if(x==420){
                       if(semaforo9->getContador()){
                           semaforo9->P();
                           x+=10;
                       }
                   }else{
                       x+=10;
                   }
               }else if (x == 440 && y < 300){
                   if(semaforo9->getContador())
                       semaforo9->P();
                   y+=10;
               }else if (x > 280 && y == 300){
                   if(x==420){
                       if(!semaforo9->getContador())
                           semaforo9->V();
                   }
                   if(x==300){
                       if(semaforo3->getContador() && semaforo7->getContador()){
                           semaforo3->P();
                           semaforo7->P();
                           x-=10;
                       }
                   }else{
                       x-=10;
                   }
               }else{
                   if(semaforo3->getContador()){
                       semaforo3->P();
                   }
                   y-=10;
               }
            }
            break;
        case 7:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x ==450){
                     ultimo_tempo=tempo;
                     qtdvoltas++;
                     tempo_total = tempo_total+tempo;
                     if(qtdvoltas==0)
                         media=tempo_total;
                     else
                         media=tempo_total/qtdvoltas;
                     tempo=0;

                }
                tempo = tempo + float(tempo_parado*0.001);


               if (y == 120 && x <540){
                   if(x==460){
                       if(!semaforo8->getContador())
                           semaforo8->V();
                   }
                   x+=10;
               }else if (x == 540 && y < 300){
                    y+=10;
               }else if (x > 440 && y == 300){
                   if(x==460){
                       if(semaforo9->getContador()){
                           semaforo9->P();
                           x-=10;
                       }
                   }else{
                       x-=10;
                   }
               }else{
                   if(y==220){
                       if(!semaforo9->getContador())
                           semaforo9->V();
                   }
                   if(y>220){
                       if(semaforo9->getContador())
                           semaforo9->P();
                   }
                   if(y<200){
                       if(semaforo8->getContador())
                           semaforo8->P();
                   }
                   if(y==200){
                       if(semaforo8->getContador()){
                           semaforo8->P();
                           y-=10;
                       }
                   }else{
                       y-=10;
                   }
               }
            }
            break;
        default:
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(tempo_parado));
        }
    }
}

