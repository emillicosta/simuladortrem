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

    trem1 = new Trem(1,70,120);
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem1->start();

    trem2 = new Trem(2,180,120);
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem2->start();

    trem3 = new Trem(3,180,300);
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem3->start();

    trem4 = new Trem(4,200,210);
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem4->start();

    trem5 = new Trem(5,360,120);
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem5->start();

    trem6 = new Trem(6,370,300);
    connect(trem6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem6->start();

    trem7 = new Trem(7,490,120);
    connect(trem7,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem7->start();

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

    trem1->setSemaforo(semaforo0,semaforo1,semaforo2,semaforo3,semaforo4,semaforo5,semaforo6,semaforo7,semaforo8,semaforo9);
    trem2->setSemaforo(semaforo0,semaforo1,semaforo2,semaforo3,semaforo4,semaforo5,semaforo6,semaforo7,semaforo8,semaforo9);
    trem3->setSemaforo(semaforo0,semaforo1,semaforo2,semaforo3,semaforo4,semaforo5,semaforo6,semaforo7,semaforo8,semaforo9);
    trem4->setSemaforo(semaforo0,semaforo1,semaforo2,semaforo3,semaforo4,semaforo5,semaforo6,semaforo7,semaforo8,semaforo9);
    trem5->setSemaforo(semaforo0,semaforo1,semaforo2,semaforo3,semaforo4,semaforo5,semaforo6,semaforo7,semaforo8,semaforo9);
    trem6->setSemaforo(semaforo0,semaforo1,semaforo2,semaforo3,semaforo4,semaforo5,semaforo6,semaforo7,semaforo8,semaforo9);
    trem7->setSemaforo(semaforo0,semaforo1,semaforo2,semaforo3,semaforo4,semaforo5,semaforo6,semaforo7,semaforo8,semaforo9);


    struct sockaddr_in endereco;
    int socketId;
    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    endereco.sin_addr.s_addr = inet_addr("127.0.0.1");
    //endereco.sin_addr.s_addr = inet_addr("192.168.7.1");

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
        id = s->getId();
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
                break;
            case 0:
                trem1->setTempoParado(s->getVelocidade());
                trem2->setTempoParado(s->getVelocidade());
                trem3->setTempoParado(s->getVelocidade());
                trem4->setTempoParado(s->getVelocidade());
                trem5->setTempoParado(s->getVelocidade());
                trem6->setTempoParado(s->getVelocidade());
                trem7->setTempoParado(s->getVelocidade());
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
    if(semaforo0->getContador()) ui->labelSema0->setStyleSheet("background-color:green; ");
        else ui->labelSema0->setStyleSheet("background-color:red; ");
    if(semaforo1->getContador()) ui->labelSema1->setStyleSheet("background-color:green; ");
        else ui->labelSema1->setStyleSheet("background-color:red; ");
    if(semaforo2->getContador()) ui->labelSema2->setStyleSheet("background-color:green; ");
        else ui->labelSema2->setStyleSheet("background-color:red; ");
    if(semaforo3->getContador()) ui->labelSema3->setStyleSheet("background-color:green; ");
        else ui->labelSema3->setStyleSheet("background-color:red; ");
    if(semaforo4->getContador()>0) ui->labelSema4->setStyleSheet("background-color:green; ");
        else ui->labelSema4->setStyleSheet("background-color:red; ");
    if(semaforo5->getContador()) ui->labelSema5->setStyleSheet("background-color:green; ");
        else ui->labelSema5->setStyleSheet("background-color:red; ");
    if(semaforo6->getContador()) ui->labelSema6->setStyleSheet("background-color:green; ");
        else ui->labelSema6->setStyleSheet("background-color:red; ");
    if(semaforo7->getContador()) ui->labelSema7->setStyleSheet("background-color:green; ");
        else ui->labelSema7->setStyleSheet("background-color:red; ");
    if(semaforo8->getContador()) ui->labelSema8->setStyleSheet("background-color:green; ");
        else ui->labelSema8->setStyleSheet("background-color:red; ");
    if(semaforo9->getContador()) ui->labelSema9->setStyleSheet("background-color:green; ");
        else ui->labelSema9->setStyleSheet("background-color:red; ");

    ui->tempo1->setText(QString("%1").arg(trem1->getTempo()));
    ui->media1->setText(QString("%1").arg(trem1->getMedia()));
    ui->desvio1->setText(QString("%1").arg(trem1->getDesvio()));

    ui->tempo2->setText(QString("%1").arg(trem2->getTempo()));
    ui->media2->setText(QString("%1").arg(trem2->getMedia()));
    ui->desvio2->setText(QString("%1").arg(trem2->getDesvio()));

    ui->tempo3->setText(QString("%1").arg(trem3->getTempo()));
    ui->media3->setText(QString("%1").arg(trem3->getMedia()));
    ui->desvio3->setText(QString("%1").arg(trem3->getDesvio()));

    ui->tempo4->setText(QString("%1").arg(trem4->getTempo()));
    ui->media4->setText(QString("%1").arg(trem4->getMedia()));
    ui->desvio4->setText(QString("%1").arg(trem4->getDesvio()));

    ui->tempo5->setText(QString("%1").arg(trem5->getTempo()));
    ui->media5->setText(QString("%1").arg(trem5->getMedia()));
    ui->desvio5->setText(QString("%1").arg(trem5->getDesvio()));

    ui->tempo6->setText(QString("%1").arg(trem6->getTempo()));
    ui->media6->setText(QString("%1").arg(trem6->getMedia()));
    ui->desvio6->setText(QString("%1").arg(trem6->getDesvio()));

    ui->tempo7->setText(QString("%1").arg(trem7->getTempo()));
    ui->media7->setText(QString("%1").arg(trem7->getMedia()));
    ui->desvio7->setText(QString("%1").arg(trem7->getDesvio()));

}

