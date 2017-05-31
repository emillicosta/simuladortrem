#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "trem.h"
#include "servidor.h"
#include <QMainWindow>
#include <thread>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void run();

public slots:
    void updateInterface(int,int,int);

private:
    Ui::MainWindow *ui;
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
    Trem *trem6;
    Trem *trem7;
    Servidor *s;
    std::thread threadVel;
};

#endif // MAINWINDOW_H
