#include "servidor.h"
#include "trem.h"
#include "mainwindow.h"

#include <cstdio>       //printf
#include <cstring>      //memset
#include <cstdlib>      //exit
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <unistd.h>     //close
#include <iostream>
using namespace std;

#define MAXMSG 1024
#define MAXNAME 100
#define PORTNUM 4325

Servidor::Servidor()
{

}

int Servidor::aqui(int socketId){
    struct sockaddr_in enderecoCliente;
    socklen_t tamanhoEnderecoCliente = sizeof(struct sockaddr);
    int byteslidos;

    int velocidade=0;
    int conexaoClienteId;
    cout<<"Servidor: esperando conexões clientes\n";

    //Servidor fica bloqueado esperando uma conexão do cliente
    conexaoClienteId = accept( socketId,(struct sockaddr *) &enderecoCliente,&tamanhoEnderecoCliente );

    cout<<"Servidor: recebeu conexão de %s\n", inet_ntoa(enderecoCliente.sin_addr);

    //Verificando erros
    if ( conexaoClienteId == -1)
    {
        cout<<"Falha ao executar accept()";
        exit(EXIT_FAILURE);
    }

    //receber uma msg do cliente
    cout<<"Servidor vai ficar esperando uma mensagem\n";
    byteslidos = recv(conexaoClienteId, &velocidade, sizeof(velocidade),0);

    if (byteslidos == -1)
    {
        cout<<"Falha ao executar recv()";
        exit(EXIT_FAILURE);
    }
    else if (byteslidos == 0)
    {
        cout<<"Cliente finalizou a conexão\n";
        exit(EXIT_SUCCESS);
    }

    Servidor::fechar(conexaoClienteId);

    return velocidade;

}

void Servidor::fechar(int conexaoClienteId)
{
    close(conexaoClienteId);
}
