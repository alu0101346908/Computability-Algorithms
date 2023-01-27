// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 7: Gramáticas Regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 16/11/2022
// Archivo nonTerminal.h: Fichero con la definicion de la clase NonTerminal.
// Historial de revisiones 
//   14/11/2022 - Primera versión
//   15/11/2022 - Continuación de programación
//   16/11/2022 - Revision final


#ifndef NONTERMINAL_H_
#define NONTERMINAL_H_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>

/**
 * @brief Clase NonTerminal analoga a la clase Estado
 * 
 */
class NonTerminal {
  public:
    NonTerminal();
    NonTerminal(uint, std::string, bool, bool);
    void AddProduction(std::pair<std::string, std::string>);
    std::vector<std::pair<std::string, std::string>> GetProductions()const;
    uint GetID() const;
    std::string GetName() const;
    bool IsFinalNonTerminal() const;
    bool IsStartNonTerminal() const;
    bool IsUselessNonTerminal() const;
    void SetUselessNonTerminal(bool);
    //std::vector<std::pair<std::string,uint>> TransitionWithSymbols(std::string, int) const;
    bool operator<(const NonTerminal&) const;
  private:

    uint id_;
    std::string name_;

    bool is_starting_non_terminal_ = false;
    bool is_final_non_terminal_ = false;
    bool is_useless_non_terminal_ = false;

    std::vector<std::pair<std::string, std::string>> productions_;
};

#endif