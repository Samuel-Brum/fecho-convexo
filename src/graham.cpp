#include "graham.hpp"

Vetor<Ponto> graham(Vetor<Ponto> entrada, char sortType) {
  Vetor<Ponto> saida;

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

  saida.push(entrada.get(baixo));

  
}