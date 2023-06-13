#include "sorts.hpp"
 
void swap(Vetor<Ponto> vetor, int i, int j){
  Ponto temp_i = vetor.get(i);
  Ponto temp_j = vetor.get(j);
  vetor.push(temp_i, j);
  vetor.push(temp_j, i);
}

Vetor<Ponto> insertionSort(Vetor<Ponto> pontos, Ponto P0) {
  Ponto eixo_x(1,0);
  Ponto K;
  int i, j;

  for (int i = 1; i < pontos.size(); i++) {
    K = pontos.get(i);
    j = i - 1;

    while (j >= 0 && angulo(eixo_x, P0, pontos.get(j)) > angulo(eixo_x, P0, K)) {
      swap(pontos, j, j+1);
      j--;
    }
    pontos.get(j+1) = K;
  }
  return pontos;

}