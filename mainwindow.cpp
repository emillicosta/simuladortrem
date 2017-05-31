#include "mainwindow.h"
#include "ui_mainwindow.h"

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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem(1,80,120);
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem1->start();

    trem2 = new Trem(2,120,120);
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem2->start();

    trem3 = new Trem(3,120,240);
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem3->start();

    trem4 = new Trem(4,200,190);
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem4->start();

    trem5 = new Trem(5,290,120);
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem5->start();

    trem6 = new Trem(6,370,240);
    connect(trem6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem6->start();

    trem7 = new Trem(7,450,120);
    connect(trem7,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem7->start();


    struct sockaddr_in endereco;
    int socketId;
    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    endereco.sin_addr.s_addr = inet_addr("127.0.0.1");

    socketId = socket(AF_INET, SOCK_STREAM, 0);

    if (socketId == -1)
    {
        printf("Falha ao executar socket()\n");
        exit(EXIT_FAILURE);
    }

    //Conectando o socket a uma porta. Executado apenas no lado servidor
    if ( bind (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )
    {
        printf("Falha ao executar bind()\n");
        exit(EXIT_FAILURE);
    }

    //Habilitando o servidor a receber conexoes do cliente
    if ( listen( socketId, 10 ) == -1)
    {
        printf("Falha ao executar listen()\n");
        exit(EXIT_FAILURE);
    }

    s = new Servidor(socketId);
    s->start();
    threadVel=std::thread(&MainWindow::run,this);
    threadVel.detach();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::run()
{
    int id;
    while (true) {
        id=s->getId();
        switch(id){
            case 1:
                trem1->setTempoParado(s->getVelocidade());
                break;
            case 2:
                trem2->setTempoParado(s->getVelocidade());
                break;
            case 3:
                trem3->setTempoParado(s->getVelocidade());
                break;
            case 4:
                trem4->setTempoParado(s->getVelocidade());
                break;
            case 5:
                trem5->setTempoParado(s->getVelocidade());
                break;
            case 6:
                trem6->setTempoParado(s->getVelocidade());
                break;
            case 7:
                trem7->setTempoParado(s->getVelocidade());
            default:
                break;
        }
    }
}

void MainWindow::updateInterface(int id, int x, int y)
{
    switch(id){
        case 1:
            ui->labelTrem01->setGeometry(x,y,20,20);
            break;
        case 2:
            ui->labelTrem02->setGeometry(x,y,20,20);
            break;
        case 3:
            ui->labelTrem03->setGeometry(x,y,20,20);
            break;
        case 4:
            ui->labelTrem04->setGeometry(x,y,20,20);
            break;
        case 5:
            ui->labelTrem05->setGeometry(x,y,20,20);
            break;
        case 6:
            ui->labelTrem06->setGeometry(x,y,20,20);
            break;
        case 7:
            ui->labelTrem07->setGeometry(x,y,20,20);
            break;
        default:
            break;
    }
}

