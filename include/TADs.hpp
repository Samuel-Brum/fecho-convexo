#ifndef TADS_HPP
#define TADS_HPP

#include "vetor.hpp"

class Ponto {
  public:
    Ponto();

    Ponto(int x, int y);

  private:
    int x;
    int y;
};

class Reta {
  public:
    /// @brief Contrutor da Reta
    /// @param A Ponto inicial da reta
    /// @param B Ponto final da reta
    Reta(Ponto A, Ponto B);

    /// @brief Calcula a distância entre os dois pontos da reta
    /// @return Distância entre os pontos
    float distancia();

    /// @brief Calcula o ângulo entre os dois pontos da reta
    /// @return Ângulo entre os dois pontos
    float angulo();

  private:
    Ponto A;
    Ponto B;
};

class FechoConvexo {
  private:
    Vetor<Reta> FechoConvexo;
};

#endif