#ifndef VETOR_HPP
#define VETOR_HPP

#include <iostream>
using namespace std;

/// @brief Implementação própria de um vetor
/// @tparam T tipo do vetor
template <typename T> class Vetor {
	public:
		/// @brief Contrutor do Vetor
		Vetor() {
			array = new T[1];
			capacidade = 1;
			numeroDeElementos = 0;
		}

		/// @brief Destrutor do Vetor
		~Vetor() {
			delete [] array;
		}

		/// @brief Insere elemento no final do vetor
		/// @param elemento Elemento a ser inserido
		void push(T elemento) {
			if (numeroDeElementos == capacidade) {
				T* temp = new T[2 * capacidade];
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
		void push(T elemento, int index) {
			if (index == capacidade)
				push(elemento);
			else
				array[index] = elemento;
		}

		/// @brief Seletor de elemento específico do Vetor a partir da posição
		/// @param index Posição do elemento
		/// @return Elemento na posição <index>
		T get(int index) {
			if (index < numeroDeElementos)
				return array[index];
		}

		/// @brief Remove último elemento do Vetor
		void pop() { numeroDeElementos--; }

		/// @brief Getter para tamanho do Vetor
		/// @return Número de elemento do Vetor
		int size() { return numeroDeElementos; }

		/// @brief Getter para capacidade máxima do Vetor
		/// @return Capacidade máxima do Vetor
		int getCapacidade() { return capacidade; }

		/// @brief Imprime elementos
		void print() {
			for (int i = 0; i < numeroDeElementos; i++) {
				cout << array[i] << " ";
			}
			cout << endl;
		}

		void printPontos() {
			for (int i = 0; i < numeroDeElementos; i++) {
				cout << this->get(i).x << " " << this->get(i).y << " " << endl;
			}
		}

	private: 
		T* array;
		int capacidade;
		int numeroDeElementos;
};

#endif