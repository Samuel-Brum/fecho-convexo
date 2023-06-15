#ifndef VETOR_HPP
#define VETOR_HPP

#include <iostream>
#include <fstream>
#include "TADs.hpp"
using namespace std;

/// @brief Implementação de um vetor
class Vetor {
	public:
		/// @brief Contrutor do Vetor
		Vetor() {
			array = new Ponto[1];
			capacidade = 1;
			numeroDeElementos = 0;
		}

		Vetor(int size) {
			array = new Ponto[size];
			capacidade = 2 * size;
			numeroDeElementos = size;
		}

/*
		/// @brief Destrutor do Vetor
		~Vetor() {
			delete [] array;
		}
*/

		/// @brief Insere elemento no final do vetor
		/// @param elemento Elemento a ser inserido
		void push(Ponto elemento) {
			if (numeroDeElementos == capacidade) {
				Ponto* temp = new Ponto[2 * capacidade];
				for (int i = 0; i < capacidade; i++) {
					temp[i] = array[i];
				} // capacidade dobra caso não haja mais espaço

				delete[] array;
				capacidade *= 2;
				array = temp;
			}

			array[numeroDeElementos] = elemento;
			numeroDeElementos++;
		}

		/// @brief Insere elemento em posição específica do Vetor
		/// @param elemento Elemento a ser inserido
		/// @param index Posição a ser inserido o elemento
		void push(Ponto elemento, int index) {
			if (index == capacidade) {
				push(elemento);
			}
			else 
				array[index] = elemento;
		}

		/// @brief Seletor de elemento específico do Vetor a partir da posição
		/// @param index Posição do elemento
		/// @return Elemento na posição <index> ou primeiro elemento caso o índice escape do vetor
		Ponto get(int index) {
			return array[index];
		}

		/// @brief Remove último elemento do Vetor
		Ponto pop() { 
			Ponto pop = array[numeroDeElementos];
			numeroDeElementos--; 
			return pop;
		}

		/// @brief Getter para tamanho do Vetor
		/// @return Número de elemento do Vetor
		int size() { return numeroDeElementos; }

		/// @brief Getter para capacidade máxima do Vetor
		/// @return Capacidade máxima do Vetor
		int getCapacidade() { return capacidade; }

		void printPontos() {
			cout << "----------------" << endl;
			for (int i = 0; i < numeroDeElementos; i++) {
				cout << array[i].x << " " << array[i].y << " " << endl;
			}
			cout << "----------------" << endl;
		}

	private: 
		Ponto* array;
		int capacidade;
		int numeroDeElementos;
};


#endif