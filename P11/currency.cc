// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 11: Algoritmos Voraces (Greedy). Cambio de Monedas
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 21/12/2022
// Archivo currency.cc: Fichero que implementa la clase Currency
// Historial de revisiones 
//   20/12/2022 - Primera version
//   21/12/2022 - Revision final

#include "currency.h"

/**
 * @brief Constructor de Currency que recibe un nombre, un vector del valor de las monedas (mayor a menor valor) y otro vector del valor de los billetes (mayor a menor)
 * 
 * @param name Nombre de la divisa
 * @param coins Vector de monedas
 * @param bills Vector de billetes
 */
Currency::Currency(std::string name, std::vector<long long int> coins, std::vector<long long int> bills){
  name_ = name;
  for (auto coin : coins){
    coins_.insert(coin);
  }
  for (auto bill : bills){
    bills_.insert(bill);
  }
}
/**
 * @brief Setter de vector de billetes
 * 
 * @param bills Billetes a añadir
 */
void Currency::addBills(std::vector<long long int> bills){
  for(auto bill: bills) {
    bills_.insert(bill);
  }
}

/**
 * @brief Algoritmo basico del calculo del cambio. 
 * Recibe una cantidad a cambiar y devolvera un vector con la cantidad de billetes y monedas usadas
 * 
 * @param n Cantidad a cambiar
 * @return std::vector<std::pair<long long int, long long int>> Vector de billetes y monedas usadas
 */
std::vector<std::pair<long long int, long long int>> Currency::exchange(long long int n) {
  std::set<long long int> items = coins_;
  std::vector<long long int> M(items.begin(), items.end());
  // Opcion -b
  if(bills_.size()!=0) {
    items.insert(bills_.begin(), bills_.end());
    M = std::vector<long long int>(items.begin(), items.end());
  }
  std::vector<std::pair<long long int, long long int>> S = {};
  long long int suma = 0;
  size_t i = M.size();
  size_t prev = -1;
  while (suma < n) {
    std::pair<long long int,long long int> aux;
    for (;i-- > 0;) {
      if(M[i] + suma <= n){
        break;
      }
    }
    if(i == M.size()){
      return {aux};
    }
    if(prev == i){
      S[S.size()-1].second +=1; 
    } else {
      prev = i;
      aux.first = M[i];
      aux.second = 1;
      S.push_back(aux);
    }
    suma = suma + M[i];
    i++;
  }
  return S;
}

/**
 * @brief Algoritmo mejorado del calculo del cambio
 * Recibe una cantidad a cambiar y devolvera un vector con la cantidad de billetes y monedas usadas
 * 
 * @param n Cantidad a cambiar
 * @return std::vector<std::pair<long long int, long long int>> Vector de billetes y monedas usadas
 */
std::vector<std::pair<long long int, long long int>> Currency::betterExchange(long long n) {
  std::set<long long int> items = coins_;
  std::vector<long long int> M(items.begin(), items.end());
  // Opcion -b
  if(bills_.size()!=0) {
    items.insert(bills_.begin(), bills_.end());
    M = std::vector<long long int>(items.begin(), items.end());
  }
  std::vector<std::pair<long long int, long long int>> S = {};
  long long int suma = 0;
  for (size_t i = M.size(); i-- > 0;) {
    long long int value = M[i];
    long long c = (n - suma) / value;
    if (c > 0) {
      std::pair<long long int,long long int> aux;
      aux.first = value;
      aux.second = c;
      S.push_back(aux);
      suma = suma + value * c;
    }
  }
  return S;
}
