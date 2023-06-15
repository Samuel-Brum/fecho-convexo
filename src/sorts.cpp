#include "sorts.hpp"
 
void swap(Vetor &vetor, int i, int j){
  Ponto temp_i = vetor.get(i);
  Ponto temp_j = vetor.get(j);
  vetor.push(temp_i, j);
  vetor.push(temp_j, i);
}

Vetor insertionSort(Vetor pontos, Ponto P0) {
  Ponto eixo_x(1,0);
  Ponto K;
  //cout << "Inicial: " << endl;
  //pontos.printPontos();

  for (int i = 1; i < pontos.size(); i++) {
    K = pontos.get(i);
    int j = i - 1;

    while (j >= 0 && angulo(eixo_x, P0, pontos.get(j)) < angulo(eixo_x, P0, K)) {
      swap(pontos, j, j+1);
      //cout << "Troca " << i << " por " << j << endl;
      //pontos.printPontos();
      //cout << endl << endl;


      j--;
    }
    pontos.get(j+1) = K;
  }
  return pontos;
}


void merge(Vetor pontos, Ponto P0, int esq, int meio, int dir) {
  Ponto eixo_x(1,0);

  //cout << "Esquerda: " << esq << endl << "Direita: " << dir << endl << "Meio: " << meio << endl << endl;
  
  int sizeTempEsq = meio - esq + 1;
  int sizeTempDir = dir - meio;
  Vetor tempEsq(sizeTempEsq);
  Vetor tempDir(sizeTempDir);

  //cout << sizeTempEsq << " " <<sizeTempDir << endl;

  for (int i = 0; i < sizeTempEsq; i++) {
    tempEsq.push(pontos.get(esq + i), i);
  }
  for (int j = 0; j < sizeTempDir; j++) {
    tempDir.push(pontos.get(meio + 1 + j), j);
  }
  
  /*
  cout << "tempEsq: " << endl;
  tempEsq.printPontos();
  cout << endl << "tempDir: " << endl;
  tempDir.printPontos();
  cout << endl << endl;
  */
  

  int i = 0;
  int j = 0;
  int k = esq;

  while (i < sizeTempEsq && j < sizeTempDir) {
      Ponto I = tempEsq.get(i);
      Ponto J = tempDir.get(j);
    if (angulo(eixo_x, P0, I) > angulo(eixo_x, P0, J)) {
      pontos.push(I, k);
      i++;
    } else {
      pontos.push(J, k);
      j++;
    }
    k++;
  }

  while (i < sizeTempEsq) {
    Ponto I = tempEsq.get(i);
    pontos.push(I, k);
    i++;
    k++;
  }

  while (j < sizeTempDir) {
    Ponto J = tempDir.get(j);
    pontos.push(J, k);
    j++; 
    k++;  
  }
  /*
  cout << "Merged: " << endl;
  pontos.printPontos();
  cout << endl;
  */
}

void mergeSort(Vetor pontos, Ponto P0, int esq, int dir) {
  if (esq < dir) {
    int meio = esq + ((dir - esq) / 2);

    mergeSort(pontos, P0, esq, meio);
    mergeSort(pontos, P0, (meio + 1), dir);

    merge(pontos, P0, esq, meio, dir);
  }
}


