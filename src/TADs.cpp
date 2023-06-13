#include <cmath>
#include <iostream>
#include <fstream>

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

bool mesmoVetor(Vetor<Ponto> P, Vetor<Ponto> Q) {
	if (P.size() != Q.size()) {
		return false;
	}
	for (int i = 0; i < P.size(); i++) {
		if (!mesmoPonto(P.get(i),Q.get(i))) {
			return false;
		}
	}
  return true;
}

Vetor<Ponto> lerEntrada(string path) {
  Vetor<Ponto> pontos;
  ifstream file;
  Ponto ponto;
  int x, y;

  file.open(path);
  if (file.is_open()) {
    while(file >> x >> y) {
      ponto.x = x;
      ponto.y = y;
      pontos.push(ponto);
    }
  }
  pontos.printPontos();
  cout << endl;
  return pontos;
}