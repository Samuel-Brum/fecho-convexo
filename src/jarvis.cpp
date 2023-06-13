#include "jarvis.hpp"
#include <cmath>

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

  int onHull = esquerda, proxPonto;
  do {
    saida.push(entrada.get(onHull));

    proxPonto = (onHull + 1) % entrada.size();
    for (int ponto = 0; ponto < entrada.size(); ponto++) {
      Ponto P = entrada.get(onHull);
      Ponto I = entrada.get(ponto);
      Ponto Q = entrada.get(proxPonto);
      float orient = orientacao(P, I, Q);

      if (orient < 0) {
        proxPonto = ponto;  
      } else if (orient == 0) {
        float distPQ = distancia(P,Q);
        float distPI = distancia(P,I);
        if (distPQ < distPI) {
          proxPonto = ponto;
        }
      }
    }
    onHull = proxPonto;
  } while (onHull != esquerda);

  return saida;
}