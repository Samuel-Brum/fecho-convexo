#include <iostream>
#include <memory>
#include <chrono>

/// @brief Classe para benchmarking
class Timer {
  public:
    Timer() {
      StartTimePoint = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
    }

    /// @brief Retorna o tempo desde a inicialização da classe
    /// @return 
    double Stop() {
      auto endTimePoint = std::chrono::high_resolution_clock::now();

      auto start = std::chrono::time_point_cast<std::chrono::microseconds>(StartTimePoint).time_since_epoch().count();
      auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

      auto duration = end - start;
      double time = duration * 0.000001;
      return time;
    }

    void reset() {
      StartTimePoint = std::chrono::high_resolution_clock::now();
    }

  private: 
    std::chrono::time_point<std::chrono::high_resolution_clock> StartTimePoint;
};