#ifndef TREM_H
#define TREM_H

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
    void setEnable(bool);

signals:
    void updateGUI(int,int,int);

private:
   std::thread threadTrem;
   int id;
   int x;
   int y;
   int tempo_parado;
   bool enable;
};

#endif // TREM_H



