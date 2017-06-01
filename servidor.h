#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <thread>
#include <string>
#include <sstream>


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
    int id;
    std::stringstream dados;

};

#endif // SERVIDOR_H
