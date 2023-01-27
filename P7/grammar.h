// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 7: Gramáticas Regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 16/11/2022
// Archivo grammar.h: Fichero con la definicion de la clase Grammar.
// Historial de revisiones 
//   14/11/2022 - Primera versión
//   15/11/2022 - Continuación de programación
//   16/11/2022 - Revision final

#ifndef GRAMMAR_H_
#define GRAMMAR_H_

#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


#include "alphabet.h"
#include "state.h"
#include "nonTerminal.h"

/**
 * @brief Clase Grammar que representa una gramatica de un lenguaje
 * 
 */
class Grammar {
  public:
    Grammar(Alphabet, std::set<State>, uint, std::string);
    Grammar(Grammar&);
    ~Grammar();
    void Start();
    bool ValidateString(std::string);
    //bool TransitFa(std::set<State>::iterator&, std::string);
    std::string IdToTerminalLetter(uint);
    std::set<NonTerminal> StatesToNonTerminal(std::set<State> states);
    void WriteOutputFile();

  private:

    std::ofstream output_file_;

    Alphabet terminals_;
    std::set<NonTerminal> non_terminals_;
    uint number_of_non_terminals_;
};

#endif