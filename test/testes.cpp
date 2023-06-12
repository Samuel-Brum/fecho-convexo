#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include <iostream>

#include "vetor.hpp"
#include "TADs.hpp"

TEST_CASE("Testa função distância") {
  Ponto Q;
  Ponto P(0, 1);
  Ponto R(1, 0);
  CHECK(distancia(P,Q) == 1);
  CHECK(distancia(R,Q) == 1);
  CHECK(distancia(P,R) == sqrtf(2));
}

TEST_CASE("Testa função Angulo") {
  Ponto Q(0, 0);
  Ponto P(0, 1);
  Ponto R(1, 0);
  CHECK(sin(angulo(P,Q,R)) == 1);
  Ponto S(1, 1);
  cout << distancia(S,Q) << " and" <<  distancia(S,P) << " and" << distancia(Q,P) << endl;
  CHECK(sin(angulo(S,Q,P)) == (sqrtf(2) / 2));
}