// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 11: Algoritmos Voraces (Greedy). Cambio de Monedas
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 21/12/2022
// Archivo currency.h: Fichero con la definicion de la clase Currency
// Historial de revisiones 
//   20/12/2022 - Primera version
//   21/12/2022 - Revision final

#ifndef CURRENCY_H_
#define CURRENCY_H_

#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <set>

/**
 * @brief Clase Currency que representa a el sistema monetario de una divisa
 * 
 */
class Currency {
  public:
    Currency(std::string, std::vector<long long int>, std::vector<long long int> = {});
    std::vector<std::pair<long long int, long long int>> exchange(long long int);
    std::vector<std::pair<long long int, long long int>> betterExchange(long long int);
    void addBills(std::vector<long long int>);
  private:
    std::string name_;
    std::set<long long int> coins_;
    std::set<long long int> bills_;
};

#endif