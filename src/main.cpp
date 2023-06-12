#include <iostream>
#include <fstream>

#include "vetor.hpp"
#include "TADs.hpp"
#include "insertionSort.hpp"
#include "mergeSort.hpp"
#include "graham.hpp"
#include "jarvis.hpp"

using namespace std;

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
  return pontos;
}

int main(int argc, char* argv[]) {
  Vetor<Ponto> entrada10 = lerEntrada("./test/entradas/ENTRADA10.txt");
  cout << entrada10.size() << endl;
  entrada10.printPontos();
}