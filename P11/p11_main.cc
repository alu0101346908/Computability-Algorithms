// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 11: Algoritmos Voraces (Greedy). Cambio de Monedas
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 21/12/2022
// Archivo p11_main.cc: Fichero main que recibe dos o tres argumentos los cuales representan las opciones de ejecucion
// y la cantidad de dinero. Segun las opciones de ejecucion ejecuta un algoritmo mas rapido o tiene en cuenta los billetes
// Historial de revisiones 
//   20/12/2022 - Primera version
//   21/12/2022 - Revision final

// MOD Contabilizar las monedas pequeñas, total monedas pequeñas

#define CENT u8"\u20B5"
#define EURO u8"\u20AC"

#include "currency.h"
#include <chrono>

int main(int argc, char* argv[]) {
  if (argc == 2 && (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) ) {
    std::cout << "The program takes a quantity in euros and cents (like 123.20) to generate the exchange, by default only";
    std::cout << "coins and the worse algorithm are used.\nTo take into account the bills execute the program with -b. \n";
    std::cout << "To use the better algorithm use -o (both can be combined)" << std::endl;
    return 0;
  }
  std::string name = "euro";
  // Trabajamos con valores enteros por lo que todo < 100 son centimos
  std::vector<long long int> coins_set = {200,100,50,20,10,5,2,1};
  std::vector<long long int> bills_set = {50000,20000,10000,5000,2000,1000,500};
  Currency euro(name, coins_set);
  std::vector<std::pair<long long int, long long int>> result;
  std::string input = argv[1];
  if (argc == 3) {
    input = argv[2];
    if ((!strcmp(argv[1], "-b")) || (!strcmp(argv[1], "-bo")) || (!strcmp(argv[1], "-ob"))) {
      euro.addBills(bills_set);
    }
  }
  // Eliminamos el punto de los centimos
  if(input.find(".") != std::string::npos) {
    input = input.substr(0,input.find(".")) + input.substr(input.find(".")+1,input.length()-2);
  }
  // Clock para medir el tiempo de ejecucion
  auto start = std::chrono::high_resolution_clock::now();
  if((!strcmp(argv[1], "-o")) || (!strcmp(argv[1], "-bo")) || (!strcmp(argv[1], "-ob"))) {
    result = euro.betterExchange(stoll(input));
  } else {
    result = euro.exchange(stoll(input));
  }
  // Paramos el reloj
  auto stop = std::chrono::high_resolution_clock::now();
  // Obtenemos el tiempo transcurrido
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  std::cout << "Elapsed time: " << duration.count() << " ns" << std::endl;
  std::string out = "Solution: ";
  long long int count = 0;
  int copper_coins_count = 0;
  for (auto s: result) {
    count += s.second;
    if(s.first < 10) copper_coins_count += s.second;
    if(s.first < 100){
      out = out + (s.second == 1 ? "" : std::to_string(s.second)+ "x") + std::to_string(s.first) + CENT + ", ";
    } else out = out + (s.second == 1 ? "" : std::to_string(s.second)+ "x") + std::to_string(s.first/100) + EURO + ", ";
  }
  out = out.substr(0, out.length()-2);
  std::cout << out << std::endl;
  std::cout << "Total bills or coins: " << count << std::endl;
  std::cout << "Total small coins (copper): " << copper_coins_count << std::endl;
  std::cout << "Program terminated successfully" << std::endl;
  return 0;
} 