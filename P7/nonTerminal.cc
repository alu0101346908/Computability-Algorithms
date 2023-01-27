// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 7: Gramáticas Regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 16/11/2022
// Archivo nonTerminal.cc: Fichero con la implementacion de la clase NonTerminal.
// Historial de revisiones 
//   14/11/2022 - Primera versión
//   15/11/2022 - Continuación de programación
//   16/11/2022 - Revision final

#include "nonTerminal.h"


/**
 * @brief Construct a new Non Terminal:: Non Terminal object
 * 
 */
NonTerminal::NonTerminal(){}

/**
 * @brief Constructor que recibe la especificacion de un estado y la guarda en los atributos de la clase
 * 
 * @param id identificador numerico del estado
 * @param name nombre del estado
 * @param is_starting si el estado es inicial
 * @param is_final si el estado es final (va a pasar a produccion de &)
 */
NonTerminal::NonTerminal(uint id, std::string name, bool is_starting, bool is_final){
  id_ = id;
  name_ = name;
  is_starting_non_terminal_ = is_starting;
  is_final_non_terminal_ = is_final;
}

/**
 * @brief Getter del id del NonTerminal
 * 
 * @return uint
 */
uint NonTerminal::GetID() const {
  return id_;
}

/**
 * @brief Getter del vector de parejas que representa una produccion
 * 
 * @return std::vector<std::pair<std::string, std::string>> vector de producciones
 */
std::vector<std::pair<std::string, std::string>> NonTerminal::GetProductions() const{
  return productions_;
}

/**
 * @brief Getter del nombre del NonTerminal
 * 
 * @return std::string nombre
 */
std::string NonTerminal::GetName() const{
  return name_;
}

/**
 * @brief Getter para comprobar si el estado es final o no
 * 
 * @return true si es final (produccion -> &)
 * @return false si no es final
 */
bool NonTerminal::IsFinalNonTerminal() const{
  return is_final_non_terminal_;
}

/**
 * @brief Getter para comprobar si el estado es inicial o no
 * 
 * @return true si es inicial (simbolo de arranque)
 * @return false si no es inicial
 */
bool NonTerminal::IsStartNonTerminal() const{
  return is_starting_non_terminal_;
}

bool NonTerminal::IsUselessNonTerminal() const {
  return is_useless_non_terminal_;
}

void NonTerminal::SetUselessNonTerminal(bool value){
  is_useless_non_terminal_ = value;
}

/**
 * @brief Setter del vector de producciones que recibe una pareja string string que representa (terminal,NonTerminal)
 * 
 * @param production produccion
 */
void NonTerminal::AddProduction(std::pair<std::string, std::string> production){
  productions_.push_back(production);
}

/**
 * @brief Operador < sobrecargado para la busqueda de no terminales en el set de no terminales de Grammar
 * 
 * @param non_terminal elemento a comparar
 * @return true 
 * @return false 
 */
bool NonTerminal::operator<(const NonTerminal& non_terminal) const {
  return (this->GetID() < non_terminal.GetID());
}
