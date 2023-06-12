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

float distancia(Ponto P, Ponto Q) {
  Vetor<int> p = P.getCoordenadas();
  Vetor<int> q = Q.getCoordenadas();
  int d_x = p.get(0) - q.get(0);
  int d_y = p.get(1) - q.get(1);
  return(sqrt(d_x * d_x + d_y * d_y));
}

float angulo(Ponto P, Ponto Q, Ponto R) {
  if (distancia(P,Q) == 0 || distancia(P,R) == 0 || distancia(Q,R) == 0) {
    return 0;
  } else {
  Vetor<int> p = P.getCoordenadas();
  Vetor<int> q = Q.getCoordenadas();
  Vetor<int> r = R.getCoordenadas();
  int a_x = p.get(0) - q.get(0);
  int a_y = p.get(1) - q.get(1);
  int b_x = r.get(0) - q.get(0);
  int b_y = r.get(1) - q.get(1);
  float prodAB = sqrt(a_x * b_x + a_y * b_y);
  float mod_a = sqrt(a_x * a_x + a_y * a_y);
  float mod_b = sqrt(b_x * b_x + b_y * b_y);
  return acos(prodAB / (mod_a * mod_b));
  }
}