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
  Vetor ordenado;
  Vetor saida;

  Ponto low = findLowest(entrada);

  ordenado = insertionSort(entrada, low);
  
  saida.push(ordenado.pop(), 0);
  saida.push(ordenado.pop(), 1);
  saida.push(ordenado.pop(), 2);

  

  return saida;
}