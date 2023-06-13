#include <iostream>
#include <fstream>

#include "vetor.hpp"
#include "TADs.hpp"
#include "insertionSort.hpp"
#include "mergeSort.hpp"
#include "graham.hpp"
#include "jarvis.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  Vetor<Ponto> entrada10 = lerEntrada("./test/entradas/ENTRADA10.txt");
  cout << entrada10.size() << endl;
  entrada10.printPontos();
  cout << endl;
  Vetor<Ponto> teste = jarvis(entrada10);
  teste.printPontos();
}