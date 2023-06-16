#include "graham.hpp"
#include "sorts.hpp"


Ponto findLowest(Vetor entrada) {
  int baixo = 0;

  for (int i = 1; i < entrada.size(); i++) {
    int i_y = entrada.get(i).y;
    int down_y = entrada.get(baixo).y;
    if (down_y > i_y) {
      baixo = i;
    } else if (down_y == i_y) {
      int i_x = entrada.get(i).x;
      int down_x = entrada.get(baixo).x;
      if (down_x > i_x) {
        baixo = i;
      }
    }
  }
  return entrada.get(baixo);
}

Vetor graham(Vetor entrada, char sortType) {
  Vetor ordenado(entrada.size());
  ordenado = entrada;
  Ponto low = findLowest(entrada);

  switch (sortType)
  {
  case 'i':
    ordenado = insertionSort(entrada, low);
    break;
  case 'm':
    mergeSort(ordenado, low, 0, ordenado.size() - 1);
    break;
  }
  
  

  /*
  // Vetor ordenado_dist(entrada.size());

  // Remove pontos de angulo igual
  for (int i = 0; i < ordenado.size(); i ++) {
    Ponto I = ordenado.get(i);
    Ponto J = ordenado.get(i+1);
    while ((i < ordenado.size() - 1) && (orientacao(I, low, J) == 0) 
          && (distancia(low, I) < distancia (low, J)) ) {
      i++;
    }
    ordenado_dist.push(ordenado.get(i));
  }
  */
  Vetor pilha(entrada.size());
  pilha.push(low);
  pilha.push(ordenado.get(1));
  pilha.push(ordenado.get(2));
  //cout << "ordenado: " << endl;
  //ordenado.printPontos();
  //cout << "Pilha: " << endl;
  //pilha.printPontos();

  for (int i = 3; i < ordenado.size() - 1; i++) {
    //cout << "Para: " << i << endl;
    //pilha.printPontos();
    while (pilha.size() > 1 && (orientacao(ordenado.get(i), pilha.get(pilha.size() - 1), pilha.get(pilha.size() - 2))) > 0) {
      //cout << "Antes: " << endl;
      //pilha.printPontos();
      pilha.pop();
      //cout << "Depois: " << endl;
      //pilha.printPontos();
    }
    pilha.push(ordenado.get(i));
  }
  return pilha;
}