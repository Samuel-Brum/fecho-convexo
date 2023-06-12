#include "jarvis.hpp"

Vetor<Ponto> jarvis(Vetor<Ponto> entrada) {
  Vetor<Ponto> saida;

  // Primeira entrada
  int esquerda = 0;

  // Primeiro ponto é o mais à esquerda
  for (int i = 1; i < entrada.size(); i++) {
    int i_x = entrada.get(i).x;
    int esq_x = entrada.get(esquerda).x;
    if (esq_x > i_x) {
      esquerda = i;
    }
  }

  int p = esquerda, q;
  do {
    saida.push(entrada.get(p));

    q = (p + 1) % entrada.size();
    for (int i = 0; i < entrada.size(); i++) {
      if (angulo(entrada.get(p), entrada.get(i), entrada.get(q)) > 0) {
        p = q;  
      }
    }
  } while (p != esquerda);

  return saida;
}