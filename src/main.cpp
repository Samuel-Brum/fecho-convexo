#include <iostream>
#include <fstream>
#include <iomanip>

#include "sorts.hpp"
#include "graham.hpp"
#include "jarvis.hpp"
#include "timer.hpp"

using namespace std;

#define N 10000

Vetor lerEntrada(string path);

int main(int argc, char* argv[]) {
  //Vetor entrada = lerEntrada(argv[1]); 
  Vetor entrada = lerEntrada("./test/hull/ENTRADA10.txt");
  cout << "FECHO CONVEXO: " << endl;
  jarvis(entrada).printPontos();
  cout << endl;

  cout.precision(2);

  auto timer = Timer();
  for (int i = 0; i < N; i++) {
    graham(entrada, 'i');
  }
  cout << "GRAHAM + INSERTSORT: " << timer.Stop() << "s" << endl;

  timer.reset();
  for (int i = 0; i < N; i++) {
    graham(entrada, 'm');
  }
  cout << "GRAHAM + MERGESORT: " << timer.Stop() << "s" << endl;

  timer.reset();
  for (int i = 0; i < N; i++) {
    jarvis(entrada);
  }
  cout << "JARVIS: " << timer.Stop() << "s" << endl;

  timer.reset();
  

}


Vetor lerEntrada(string path) {
  Vetor pontos;
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

/*
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
    result = insertionSort(entrada10, findLowest(entrada10));
    cout << "Insertion Sort" << endl;
    result.printPontos();
    cout << "Jarvis" << endl;
    result = jarvis(entrada10);
    result.printPontos();
    result = graham(entrada10, 'm');
    result.printPontos();

    cout << endl << "Depois: " << endl << endl;
    mergeSort(entrada10, findLowest(entrada10), 0 , entrada10.size() - 1);
    entrada10.printPontos();

    cout << "Correto: " << endl << endl;
    hull10.printPontos();
}
*/