#ifndef TADS_HPP
#define TADS_HPP

#include <cmath>

class Ponto {
  public:
    Ponto();

    Ponto(int x, int y);

    int x;
    int y;
};

float distancia(Ponto P, Ponto Q);

float angulo(Ponto P, Ponto Q, Ponto R);

float orientacao(Ponto P, Ponto Q, Ponto R);

bool mesmoPonto(Ponto P, Ponto Q);




#endif