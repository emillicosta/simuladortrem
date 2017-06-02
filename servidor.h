#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <thread>


#define MAXMSG 1024
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
    char* dados=new char[MAXMSG+1];;

};

#endif // SERVIDOR_H
