#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

using namespace std;

#include "jarvis.hpp"
#include "sorts.hpp"
#include "graham.hpp"

bool mesmoVetor(Vetor P, Vetor Q) {
	if (P.size() != Q.size()) {
		return false;
	}
	for (int i = 0; i < P.size(); i++) {
		if (!mesmoPonto(P.get(i),Q.get(i))) {
			return false;
		}
	}
  return true;
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

Vetor entrada10 = lerEntrada("./test/hull/ENTRADA10.txt");
Vetor entrada100 = lerEntrada("./test/hull/ENTRADA100.txt");

Vetor saida10 = lerEntrada("./test/hull/SAIDA10.txt");
Vetor saida100 = lerEntrada("./test/hull/SAIDA100.txt");

Vetor sort10 = lerEntrada("./test/sort/SAIDA10.txt");

TEST_CASE("Jarvis funciona corretamente") {
  SUBCASE("Teste 10") {
    CHECK(mesmoVetor(jarvis(entrada10), saida10));
  }

  SUBCASE("Teste 100") {
    CHECK(mesmoVetor(jarvis(entrada100), saida100));
  }
}

TEST_CASE("Insertion Sort") {
  SUBCASE("10 Pontos") {
    Vetor teste = insertionSort(entrada10, findLowest(entrada10));
    CHECK(mesmoVetor(teste, sort10));
  }
  SUBCASE("100 Pontos") {
    Vetor teste = insertionSort(entrada100, findLowest(entrada100)); 
  }
}

TEST_CASE("Merge Sort") {
  Vetor entradaSort10 = lerEntrada("./test/hull/ENTRADA10.txt");
  Vetor entradaSort100 = lerEntrada("./test/hull/ENTRADA100.txt");
  mergeSort(entradaSort10, findLowest(entradaSort10), 0 , entrada10.size() - 1);
  CHECK(mesmoVetor(entradaSort10, sort10));  
}

// Por alguma razão falham, mas os vetores são identicos...
TEST_CASE("Graham") {
  cout << "Por alguma razao falham, mas os vetores são identicos..." << endl;
  SUBCASE("Teste 10") {
    CHECK(mesmoVetor(graham(entrada10, 'i'), saida10));
    CHECK(mesmoVetor(graham(entrada10, 'm'), saida10));

    cout << "graham insert: " << endl;
    graham(entrada10, 'i').printPontos();
    cout << "graham merge: " << endl;
    graham(entrada10, 'm').printPontos();
    cout << "saida correta: " << endl;
    saida10.printPontos();
  }

  SUBCASE("Teste 100") {
    CHECK(mesmoVetor(graham(entrada100, 'i'), saida100));
    cout << "graham insert: " << endl;
    graham(entrada100, 'i').printPontos();
    cout << "graham merge: " << endl;
    graham(entrada100, 'm').printPontos();
    cout << "saida correta: " << endl;
    saida100.printPontos();
    CHECK(mesmoVetor(graham(entrada100, 'm'), saida100));
  }
}