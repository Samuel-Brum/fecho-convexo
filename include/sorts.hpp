#ifndef SORTS_HPP
#define SORTS_HPP

#include "vetor.hpp"
#include "TADs.hpp"

/// @brief Ordena um vetor de pontos de acordo com o ângulo formado com uma reta
///        horizontal contendo o ponto mais baixo do vetor pelo algorítmo
///        insertion sort
/// @param pontos Vetor de pontos
/// @param P0 Ponto mais baixo do conjunto
Vetor insertionSort(Vetor pontos, Ponto P0);

/// @brief Ordena um vetor de pontos de acordo com o ângulo formado com uma reta
///        horizontal contendo o ponto mais baixo do vetor pelo algorítmo
///        merge sort
/// @param pontos Vetor de pontos
/// @param P0 Ponto mais baixo do conjunto 
/// @param esq Limite de acesso à esquerda ao vetor pontos
/// @param dir Limite de acesso à direita ao vetor pontos
void mergeSort(Vetor pontos, Ponto P0, int esq, int dir);



#endif