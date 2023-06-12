#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"



using namespace std;

#include "vetor.hpp"
#include "TADs.hpp"
#include "jarvis.hpp"

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
  CHECK(angulo(P,O,Q) == (float) M_PI_2);
  Ponto S(1, 1);
  CHECK(angulo(P,O,S) == (float) M_PI_4);
  CHECK(angulo(Q,O,P) == -1 * (float) M_PI_2);
}

TEST_CASE("Jarvis funciona corretamente") {
  Vetor<Ponto> entrada10 = lerEntrada("./test/entradas/ENTRADA10.txt");
  Vetor<Ponto> saida10 = lerEntrada("./test/entradas/SAIDA10.txt");
  CHECK(mesmoPonto(entrada10.get(0), Ponto(27,11)));
}
// Vetor<Ponto> saida10 = lerEntrada(".test/saidas/SAIDA10.txt");
// CHECK(saidaTeste.get(0).x == saida10.get(0).y);