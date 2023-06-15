#include <iostream>
#include <fstream>

#include "sorts.hpp"
#include "graham.hpp"
#include "jarvis.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  Vetor entrada10;
  entrada10.push(Ponto(27, 11));
  entrada10.push(Ponto(6, 8));
  entrada10.push(Ponto(6, 82));
  entrada10.push(Ponto(19, 82));
  entrada10.push(Ponto(33, 96));
  entrada10.push(Ponto(45, 13));
  entrada10.push(Ponto(38, 82));
  entrada10.push(Ponto(6, 22));
  entrada10.push(Ponto(68, 79));
  entrada10.push(Ponto(66, 68));
  for (int i = 0; i < 0; i++) {
    entrada10.push(Ponto(12,12));
  }




  Vetor saida10;
  saida10.push(Ponto(6,8));
  saida10.push(Ponto(45,13));
  saida10.push(Ponto(27,11));
  saida10.push(Ponto(66,68));
  saida10.push(Ponto(68,79));
  saida10.push(Ponto(38,82));
  saida10.push(Ponto(33,96));
  saida10.push(Ponto(19,82));
  saida10.push(Ponto(6,22));
  saida10.push(Ponto(6,82));

  Vetor hull10;
  hull10.push(Ponto(6,8));
  hull10.push(Ponto(45,13));
  hull10.push(Ponto(66,68));
  hull10.push(Ponto(68,79));
  hull10.push(Ponto(33, 96));
  hull10.push(Ponto(6,82));

  cout << "Antes: " << endl;
  entrada10.printPontos();
  
  Vetor result(entrada10.size());
  //result = insertionSort(entrada10, findLowest(entrada10));
  //cout << "Insertion Sort" << endl;
  //result.printPontos();
  //cout << "Jarvis" << endl;
  //result = jarvis(entrada10);
  //result.printPontos();
  result = graham(entrada10);
  result.printPontos();

  //cout << endl << "Depois: " << endl << endl;
  //mergeSort(entrada10, findLowest(entrada10), 0 , entrada10.size() - 1);
  //entrada10.printPontos();

  cout << "Correto: " << endl << endl;
  hull10.printPontos();
}