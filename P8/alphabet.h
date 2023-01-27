// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 7: Gramáticas Regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 16/11/2022
// Archivo alphabet.h: Fichero con la definicion de la clase Alphabet.
// Historial de revisiones 
//   14/11/2022 - Primera versión
//   15/11/2022 - Continuación de programación
//   16/11/2022 - Revision final

#ifndef ALPHABET_H_
#define ALPHABET_H_


#include <set>
#include <string>
#include <iostream>
#include <sstream>

/**
 * @brief Clase Alphabet que representa un alfabeto, almacena en un set de cadenas los posibles simbolos del alfabeto
 * 
 */
class Alphabet {
  public:
    Alphabet();
    Alphabet(std::string);
    void AddSymbol(std::string);
    bool SymbolInAlphabet(std::string);
    bool SymbolsInAlphabet(std::string);
    uint GetAlphabetSize();
    std::set<std::string> GetSymbolsSet();
    void Print();
  private:

    std::set<std::string> symbols_;


};


#endif