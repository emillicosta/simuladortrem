#ifndef TREMAUX_H
#define TREMAUX_H


class Tremaux
{
public:
    Tremaux(int,int);
    int getId();
    int getTemp();


private:
   int id;
   int tempo_parado;
};

#endif // TREMAUX_H
