#ifndef GRAHAM_HPP
#define GRAHAM_HPP

#include "vetor.hpp"

/// @brief Acha ponto mais baixo de um conjunto
/// @param entrada Conjunto de pontos
/// @return Ponto mais baixo
Ponto findLowest(Vetor entrada);

/// @brief Realiza o algorítmo de Graham para um conjunto de pontos
/// @param entrada Conjunto de pontos 
/// @return Vetor de pontos com casca convexa
Vetor graham(Vetor entrada);

#endif