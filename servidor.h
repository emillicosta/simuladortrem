#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "trem.h"
#include <thread>
class Servidor
{
public:
    Servidor(int);
    ~Servidor();
    void start();
    void run();
    int getVelocidade();
    int getId();
    void setVelocidade(int);

private:
    std::thread threadServ;
    int velocidade;
    int socketId;
    Trem *trem;

};

#endif // SERVIDOR_H
