// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 8: Gramaticas en Forma Normal de Chomsky
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 23/11/2022
// Archivo nonTerminal.h: Fichero con la definicion de la clase NonTerminal.
// Historial de revisiones 
//   21/11/2022 - Primera versión
//   22/11/2022 - Continuación de programación
//   23/11/2022 - Revision final


#ifndef NONTERMINAL_H_
#define NONTERMINAL_H_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <set>

/**
 * @brief Clase NonTerminal analoga a la clase Estado
 * 
 */
class NonTerminal {
  public:
    NonTerminal();
    NonTerminal(std::string, bool, bool);
    void AddProduction(std::string);
    std::set<std::string> GetProductions()const;
    //uint GetID() const;
    std::string GetName() const;
    bool IsFinalNonTerminal() const;
    bool IsStartNonTerminal() const;
    bool IsUselessNonTerminal() const;
    void SetUselessNonTerminal(bool);
    void SetFinalNonTerminal(bool);
    //std::vector<std::pair<std::string,uint>> TransitionWithSymbols(std::string, int) const;
    bool operator<(const NonTerminal&) const;
  private:

    std::string name_;

    bool is_starting_non_terminal_ = false;
    bool is_final_non_terminal_ = false;
    bool is_useless_non_terminal_ = false;

    std::set<std::string> productions_;
};

#endif