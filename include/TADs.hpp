#ifndef TADS_HPP
#define TADS_HPP

#include "vetor.hpp"

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

bool mesmoPonto (Ponto p, Ponto q);

bool mesmoVetor(Vetor<Ponto> P, Vetor<Ponto> Q);

Vetor<Ponto> lerEntrada(string path);

class FechoConvexo {
  private:
    Vetor<Ponto> FechoConvexo;
};

class Reta {
  public:
    /// @brief Contrutor da Reta
    /// @param A Ponto inicial da reta
    /// @param B Ponto final da reta
    Reta(Ponto A, Ponto B);

    /// @brief Getter para os pontos que formam a reta
    /// @return Vetor com os Pontos
    Vetor<Ponto> getPontos();

  private:
    Ponto A;
    Ponto B;
};

#endif