// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 6: Simulación de autómatas finitos
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 9/11/2022
// Archivo automaton.h: Fichero con la definicion de la clase Automaton.
// Historial de revisiones 
//   7/11/2022 - Primera versión
//   8/11/2022 - Continuación de programación
//   9/11/2022 - Revision final

#ifndef AUTOMATON_H_
#define AUTOMATON_H_

#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>


#include "alphabet.h"
#include "state.h"

/**
 * @brief Clase Automaton que representa un automata, contiene  el archivo de especificacion .fa y el archivo de strings ademas del conjunto de estados
 * cargados desde el fichero y el numero de estados
 * 
 */
class Automaton {
  public:
    Automaton(std::string, std::string, std::string);
    ~Automaton();
    void start();
    bool validate_string(std::string);
    bool transit_fa(std::set<State>::iterator&, std::string);

  private:

    std::ifstream fa_file_;
    std::ifstream strings_file_;
    std::ofstream output_file_;

    Alphabet alphabet_;
    std::set<State> states_;

    uint number_of_states_;
};

#endif