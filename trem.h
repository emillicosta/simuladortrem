#ifndef TREM_H
#define TREM_H

#include "semaforo.h"
#include <QObject>
#include <thread>
#include <chrono>
using namespace std;

class Trem : public QObject
{
    Q_OBJECT
public:
    Trem(int,int,int);
    ~Trem();
    void start();
    void run();
    void setTempoParado(int);
    void setId(int);
    int getTempoParado();
    int getId();
    void setEnable(bool);
    void setSemaforo(Semaforo*,Semaforo*,Semaforo*,Semaforo*,Semaforo*,Semaforo*,Semaforo*,Semaforo*,Semaforo*,Semaforo*);

signals:
    void updateGUI(int,int,int);

private:
   std::thread threadTrem;
   int id;
   int x;
   int y;
   int tempo_parado;
   bool enable;

   Semaforo *semaforo0;
         Semaforo *semaforo1;
         Semaforo *semaforo2;
         Semaforo *semaforo3;
         Semaforo *semaforo4;
         Semaforo *semaforo5;
         Semaforo *semaforo6;
         Semaforo *semaforo7;
         Semaforo *semaforo8;
         Semaforo *semaforo9;
};

#endif // TREM_H



