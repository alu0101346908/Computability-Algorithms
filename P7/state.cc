// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 7: Gramáticas Regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 16/11/2022
// Archivo state.cc: Fichero con la implementacion de la clase State.
// Historial de revisiones 
//   14/11/2022 - Primera versión
//   15/11/2022 - Continuación de programación
//   16/11/2022 - Revision final


#include "state.h"

/**
 * @brief Constructor de la clase State
 * 
 * @param id Id unico
 * @param name Posible nombre del estado
 * @param is_starting_state Booleano para marcar el estado como inicial
 * @param is_final_state Booleano para marcar el estado como final
 */
State::State(uint id, std::string name, bool is_starting_state, bool is_final_state){
  id_ = id;
  name_ = name;
  is_final_state_ = is_final_state;
  is_starting_state_ = is_starting_state;
}

/**
 * @brief Getter de id
 * 
 * @return uint Id del estado
 */
uint State::GetID() const {
  return id_;
}

/**
 * @brief Getter del booleano indicador si es estado final
 * 
 * @return true Si es final
 * @return false Si no es final
 */
bool State::IsFinalState() const{
  return is_final_state_;
}

/**
 * @brief Getter del booleano indicador si es estado inicial
 * 
 * @return true Si es inicial
 * @return false Si no es inicial
 */
bool State::IsStartingState() const{
  return is_starting_state_;
}

/**
 * @brief Getter del vector transiciones de la clase
 * 
 * @return std::vector<std::pair<std::string, uint>> vector de parejas (simbolo transita a id del estado) 
 */
std::vector<std::pair<std::string, uint>> State::GetTransitions(){
  return transitions_;
}


/**
 * @brief Setter de transiciones
 * 
 * @param transition Transicion guardada como par: simbolo --> estado
 */
void State::AddTransition(std::pair<std::string, uint> transition){
  transitions_.push_back(transition);
}

/**
 * @brief Getter de las transiciones del estado con el simbolo pasado por argumento 
 * 
 * @param symbol Simbolo
 * @param symbol_length Longitud del simbolo (por si se especifica que un conjunto de simbolos representa una entrada del lenguaje)
 * @return std::vector<std::pair<std::string,uint>> 
 */
std::vector<std::pair<std::string,uint>> State::TransitionWithSymbols(std::string symbol, int symbol_length) const{
  std::vector<std::pair<std::string,uint>> found_transitions;
  std::string aux_symbol = symbol.substr(0,symbol_length);
  for (std::pair<std::string,uint> transition : transitions_) {
    if(transition.first == aux_symbol){
      found_transitions.push_back(transition);
    } 
  }
  return found_transitions;
}


/**
 * @brief Operador sobrecargado comparador de estados para buscar los estados cuando se almacenen en un set en Automaton, necesario por std::set
 * 
 * @param state Estado que se esta buscando
 * @return true 
 * @return false  
 */
bool State::operator<(const State& state) const {
  return (this->GetID() < state.GetID());
}
