#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "trem.h"
class Servidor
{
public:
    Servidor();
    void fechar(int);
    int aqui(int);

private:
    Trem *trem;
};

#endif // SERVIDOR_H
