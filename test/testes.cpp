#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include <iostream>

#include "vetor.hpp"
#include "TADs.hpp"

TEST_CASE("Testa função distância") {
  Ponto O;
  Ponto P(0, 1);
  Ponto Q(1, 0);
  CHECK(distancia(P,O) == 1);
  CHECK(distancia(Q,O) == 1);
  CHECK(distancia(P,Q) == sqrtf(2));
}

TEST_CASE("Testa função Angulo") {
  Ponto O(0, 0);
  Ponto P(0, 1);
  Ponto Q(1, 0);
  CHECK(sin(angulo(P,O,Q)) == 1);
  Ponto S(1, 1);
  CHECK(sin(angulo(P,O,S)) == (sqrtf(2) / 2));
  CHECK(sin(angulo(Q,O,P)) == -1);
}