// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 7: Gramáticas Regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 16/11/2022
// Archivo alphabet.cc: Fichero con la implementacion de la clase Alphabet.
// Historial de revisiones 
//   14/11/2022 - Primera versión
//   15/11/2022 - Continuación de programación
//   16/11/2022 - Revision final


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
void Alphabet::AddSymbol(std::string symbol) {
  symbols_.insert(symbol);
}

/**
 * @brief Comprueba si el simbolo esta en el alfabeto
 * 
 * @param symbol Simbolo a buscar
 * @return true Si esta
 * @return false Si no esta
 */
bool Alphabet::SymbolInAlphabet(std::string symbol) {
  return symbols_.find(symbol) != symbols_.end();

}

/**
 * @brief Comprueba si los simbolos de la cadena estan en el alfabeto
 * 
 * @param symbols Cadena a comprobar
 * @return true Si esta
 * @return false Si no esta
 */
bool Alphabet::SymbolsInAlphabet(std::string symbols) {
  for (uint i = 0; i < symbols.size(); i++) {
    if (SymbolInAlphabet(symbols.substr(i,1))) return true;
  }
  return false;
}

/**
 * @brief Getter del numero de simbolos en el alfabeto
 * 
 * @return uint tamaño del alfabeto
 */
uint Alphabet::GetAlphabetSize(){
  return symbols_.size();
}

/**
 * @brief Getter del set de simbolos del afabeto
 * 
 * @return std::set<std::string> Sett que contiene los simbolos del afabeto
 */
std::set<std::string> Alphabet::GetSymbolsSet(){
  return symbols_;
}

/**
 * @brief Funcion Print que muestra por pantalla los simbolos almacenados en el alfabeto
 * 
 */
void Alphabet::Print() {
  std::cout << "Alfabeto: ";
  std::string print_string = "";
  for (std::string symbol : symbols_) {
    print_string += (symbol + ", ");
  }
  std::cout << print_string.substr(0, print_string.length()-2) << std::endl;
}