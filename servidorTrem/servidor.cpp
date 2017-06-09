#include "servidor.h"
#include "tremaux.h"
#include "mainwindow.h"

#include <cstdio>       //printf
#include <cstring>      //memset
#include <cstdlib>      //exit
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <unistd.h>     //close
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define MAXMSG 1024
#define MAXNAME 100
#define PORTNUM 4325

Servidor::Servidor(int idsocket)
{
    socketId=idsocket;
    velocidade=0;
    id=-1;
}

Servidor::~Servidor()
{
    threadServ.join();
}

void Servidor::start(){
    threadServ = std::thread(&Servidor::run,this );
}

void Servidor::run(){
    //variáveis do servidor
    stringstream temp;

       //variáveis relacionadas com as conexões clientes
       struct sockaddr_in enderecoCliente;
       socklen_t tamanhoEnderecoCliente = sizeof(struct sockaddr);
       int conexaoClienteId;

       int byteslidos;

       //servidor ficar em um loop infinito
       while(1)
       {

           printf("Servidor: esperando conexões clientes\n");

           //Servidor fica bloqueado esperando uma conexão do cliente
           conexaoClienteId = accept( socketId,(struct sockaddr *) &enderecoCliente,&tamanhoEnderecoCliente );

           printf("Servidor: recebeu conexão de %s\n", inet_ntoa(enderecoCliente.sin_addr));

           //Verificando erros
           if ( conexaoClienteId == -1)
           {
               printf("Falha ao executar accept()");
               exit(EXIT_FAILURE);
           }

           //receber uma msg do cliente
           printf("Servidor vai ficar esperando uma mensagem\n");
           byteslidos = recv(conexaoClienteId,dados,MAXMSG,0);

           if (byteslidos == -1)
           {
               printf("Falha ao executar recv()");
               exit(EXIT_FAILURE);
           }
           else if (byteslidos == 0)
           {
               printf("Cliente finalizou a conexão\n");
               exit(EXIT_SUCCESS);
           }
           //Inserir o caracter de fim de mensagem
           dados[byteslidos] = '\0';
           cout<<"Servidor recebeu a seguinte msg do cliente:  "<<dados<<"\n";
           for (int i = 8; i < byteslidos; ++i)
           {
               temp<<dados[i];
           }
           id = dados[3] - '0';
           cout<<"Servidor recebeu a seguinte msg do cliente:  "<<id<<"\n";
           velocidade=atoi(temp.str().c_str());
           temp.str("");


           close(conexaoClienteId);
       }
}

int Servidor::getVelocidade(){
    return velocidade;
}

int Servidor::getId(){
    return id;
}
void Servidor::setVelocidade(int vel){
    velocidade=vel;
}
