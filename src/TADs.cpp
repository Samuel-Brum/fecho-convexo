#include <cmath>

#include "TADs.hpp"

using namespace std;

Ponto::Ponto() {
  this->x = 0;
  this->y = 0;
}

Ponto::Ponto(int x, int y) {
  this->x = x;
  this->y = y;
}

float distancia(Ponto P, Ponto O) {
  int d_x = P.x - O.x;
  int d_y = P.y - O.y;
  return(sqrt(d_x * d_x + d_y * d_y));
}

float angulo(Ponto P, Ponto O, Ponto Q) {
  if (distancia(P,O) == 0 || distancia(P,Q) == 0 || distancia(O,Q) == 0) {
    return 0;
  } else {
  int a_x = P.x - O.x;
  int a_y = P.y - O.y;
  int b_x = Q.x - O.x;
  int b_y = Q.y - O.y;
  return atan2(a_y, a_x) - atan2(b_y, b_x);
  } 
}

float orientacao(Ponto P, Ponto O, Ponto Q) {
  return ((Q.y - O.y) * (O.x - P.x)) - ((O.y - P.y) * (Q.x - O.x));
}

bool mesmoPonto (Ponto p, Ponto q) {
  if (q.x == p.x && q.y == p.y) {
    return true;
  } 
  return false;
}


