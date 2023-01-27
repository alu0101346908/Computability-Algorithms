// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 6: Simulación de autómatas finitos
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 9/10/2022
// Archivo alphabet.cc: Fichero con la implementacion de la clase Alphabet.
// Historial de revisiones 
//   7/11/2022 - Primera versión
//   8/11/2022 - Continuación de programación
//   9/11/2022 - Revision final


#include "alphabet.h"

/**
 * @brief Constructor por defecto del alfabeto vacio
 * 
 */
Alphabet::Alphabet(){}

/**
 * @brief Contructor de Alphabet que recibe una cadena que contiene la especificacion del alfabeto (simbolos separados por espacios) y la
 * añade al set de simbolos
 * 
 * @param alphabet_string Especificacion del alfabeto
 */
Alphabet::Alphabet(std::string alphabet_string) {
  std::string symbol = "";
  std::istringstream alphabet_stream (alphabet_string);
  while(getline(alphabet_stream, symbol, ' ')) {
    symbols_.insert(symbol);
  }
}

/**
 * @brief Setter de symbols_
 * 
 * @param symbol Simbolo a añadir
 */
void Alphabet::add_symbol(std::string symbol) {
  symbols_.insert(symbol);
}

/**
 * @brief Comprueba si el simbolo esta en el alfabeto
 * 
 * @param symbol Simbolo a buscar
 * @return true Si esta
 * @return false Si no esta
 */
bool Alphabet::symbol_in_alphabet(std::string symbol) {
  return symbols_.find(symbol) != symbols_.end();

}

/**
 * @brief Comprueba si los simbolos de la cadena estan en el alfabeto
 * 
 * @param symbols Cadena a comprobar
 * @return true Si esta
 * @return false Si no esta
 */
bool Alphabet::symbols_in_alphabet(std::string symbols) {
  for (int i = 0; i < symbols.size(); i++) {
    if (symbol_in_alphabet(symbols.substr(i,1))) return true;
  }
  return false;
}

/**
 * @brief Funcion print que muestra por pantalla los simbolos almacenados en el alfabeto
 * 
 */
void Alphabet::print() {
  std::cout << "Alfabeto: ";
  std::string print_string = "";
  for (std::string symbol : symbols_) {
    print_string += (symbol + ", ");
  }
  std::cout << print_string.substr(0, print_string.length()-2) << std::endl;
}