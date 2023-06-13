#ifndef GRAHAM_HPP
#define GRAHAM_HPP

#include "vetor.hpp"
#include "TADs.hpp"

/// @brief Realiza o algorítmo de Graham para um conjunto de pontos
/// @param entrada Conjunto de pontos 
/// @return Vetor de pontos com casca convexa
Vetor<Ponto> graham(Vetor<Ponto> entrada);

#endif