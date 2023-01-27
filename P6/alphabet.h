// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 6: Simulación de autómatas finitos
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 9/11/2022
// Archivo alphabet.h: Fichero con la definicion de la clase Alphabet.
// Historial de revisiones 
//   7/11/2022 - Primera versión
//   8/11/2022 - Continuación de programación
//   9/11/2022 - Revision final

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
    void add_symbol(std::string);
    bool symbol_in_alphabet(std::string);
    bool symbols_in_alphabet(std::string);
    void print();
  private:

    std::set<std::string> symbols_;


};


#endif