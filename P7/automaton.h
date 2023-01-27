// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 7: Gramáticas Regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 16/11/2022
// Archivo automaton.h: Fichero con la definicion de la clase Automaton.
// Historial de revisiones 
//   14/11/2022 - Primera versión
//   15/11/2022 - Continuación de programación
//   16/11/2022 - Revision final

#ifndef AUTOMATON_H_
#define AUTOMATON_H_

#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>


#include "alphabet.h"
#include "grammar.h"
#include "state.h"

/**
 * @brief Clase Automaton que representa un automata, contiene  el archivo de especificacion .fa y el archivo de strings ademas del conjunto de estados
 * cargados desde el fichero y el numero de estados
 * 
 */
class Automaton {
  public:
    Automaton(std::string);
    ~Automaton();
    void Start();
    bool ValidateString(std::string);
    bool TransitFa(std::set<State>::iterator&, std::string);
    Grammar ConvertToGrammar(std::string);

  private:

    std::ifstream fa_file_;
    std::ifstream strings_file_;
    std::ofstream output_file_;

    Alphabet alphabet_;
    std::set<State> states_;

    uint number_of_states_;
};

#endif