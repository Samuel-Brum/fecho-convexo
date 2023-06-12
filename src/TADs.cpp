#include <cmath>

#include "TADs.hpp"
#include "vetor.hpp"

using namespace std;

Ponto::Ponto() {
  this->x = 0;
  this->y = 0;
}

Ponto::Ponto(int x, int y) {
  this->x = x;
  this->y = y;
}

Vetor<int> Ponto::getCoordenadas() {
  Vetor<int> coordenadas;
  coordenadas.push(this->x);
  coordenadas.push(this->y);
  return coordenadas;
}

Reta::Reta(Ponto A, Ponto B) {
  this->A = A;
  this->B = B;
}

Vetor<Ponto> Reta::getPontos() {
  Vetor<Ponto> pontos;
  pontos.push(this->A);
  pontos.push(this->B);
  return pontos;
}

float distancia(Ponto P, Ponto O) {
  Vetor<int> p = P.getCoordenadas();
  Vetor<int> o = O.getCoordenadas();
  int d_x = p.get(0) - o.get(0);
  int d_y = p.get(1) - o.get(1);
  return(sqrt(d_x * d_x + d_y * d_y));
}

float angulo(Ponto P, Ponto O, Ponto Q) {
  if (distancia(P,O) == 0 || distancia(P,Q) == 0 || distancia(O,Q) == 0) {
    return 0;
  } else {
  Vetor<int> p = P.getCoordenadas();
  Vetor<int> o = O.getCoordenadas();
  Vetor<int> q = Q.getCoordenadas();
  int a_x = p.get(0) - o.get(0);
  int a_y = p.get(1) - o.get(1);
  int b_x = q.get(0) - o.get(0);
  int b_y = q.get(1) - o.get(1);
  return atan2(a_y, a_x) - atan2(b_y, b_x);
  } 
}