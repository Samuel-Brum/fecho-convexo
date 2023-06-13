#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

using namespace std;

#include "vetor.hpp"
#include "TADs.hpp"
#include "jarvis.hpp"
#include "sorts.hpp"
#include "graham.hpp"

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
  Ponto R(5,0);
  CHECK(angulo(P,O,R) == (float) M_PI_2);
}

TEST_CASE("Jarvis funciona corretamente") {
  SUBCASE("Teste 10") {
    Vetor<Ponto> entrada10 = lerEntrada("./test/hull/ENTRADA10.txt");
    Vetor<Ponto> saida10 = lerEntrada("./test/hull/SAIDA10.txt");
    CHECK(mesmoVetor(jarvis(entrada10), saida10));
  }

  SUBCASE("Teste 100") {
    Vetor<Ponto> entrada100 = lerEntrada("./test/hull/ENTRADA100.txt");
    Vetor<Ponto> saida100 = lerEntrada("./test/hull/SAIDA100.txt");
    CHECK(mesmoVetor(jarvis(entrada100), saida100));
  }
}

TEST_CASE("Insertion Sort") {
  Vetor<Ponto> entrada10 = lerEntrada("./test/hull/ENTRADA10.txt");
  Vetor<Ponto> saida10 = lerEntrada("./test/sort/SAIDA10.txt");
  CHECK(mesmoVetor(insertionSort(entrada10, Ponto(6,8)), saida10));
}