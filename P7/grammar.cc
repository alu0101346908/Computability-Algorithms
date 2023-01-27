// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 7: Gramáticas Regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 16/11/2022
// Archivo grammar.cc: Fichero con la implementacion de la clase Grammar.
// Historial de revisiones 
//   14/11/2022 - Primera versión
//   15/11/2022 - Continuación de programación
//   16/11/2022 - Revision final

#include "grammar.h"

/**
 * @brief Constructor de la clase Grammar que recibe los atributos de un automata de formas que se cargara una gramatica equivalente al automata
 * 
 * @param alphabet alfabeto -> terminales
 * @param states estados -> no terminales y producciones
 * @param number_of_states -> nº de no terminales
 * @param output_file_name fichero donde se guardara la especificacion de la gramatica
 */
Grammar::Grammar(Alphabet alphabet, std::set<State> states, uint number_of_states, std::string output_file_name) {
  output_file_ = std::ofstream(output_file_name, std::fstream::out);
  terminals_ = alphabet;
  number_of_non_terminals_ = number_of_states;
  non_terminals_ = StatesToNonTerminal(states);
}
/**
 * @brief Destructor de la clase Grammar que cierra el fichero de salida si este se encuentra abierto antes de destruirse
 */
Grammar::~Grammar() {
  if (output_file_.is_open()) {
    output_file_.close();;
  }
}

/**
 * @brief Funcion que recibe el id de un estado y devuelve el simbolo no terminal que le corresponde
 * 
 * @param id Id del estado
 * @return std::string Simbolo equivalente al estado
 */
std::string Grammar::IdToTerminalLetter(uint id){
  std::string terminals_alphabet = "SABCDEFGHIJKLMNOPQRTUVWXYZ";
  std::string dummy = "" + terminals_alphabet.substr(int(id),1);
  return dummy;
}

/**
 * @brief Recibe un set de estados (States) que se convertiran en un set de no terminales (NonTerminals), por cada State se crea un no terminal cuya producciones
 * seran las transiciones del propio estado
 * @param states Set de estados
 * @return std::set<NonTerminal> Set de no terminales resultantes de la conversion 
 */
std::set<NonTerminal> Grammar::StatesToNonTerminal(std::set<State> states) {
  std::set<State>::iterator it;
  std::set<NonTerminal> result;
  uint start_state_id;
  for(it = states.begin(); it!= states.end(); it++) {
    if(it->IsStartingState()) start_state_id = it->GetID();
  }
  std::set<uint> next_state_uid_set;
  std::string terminalLetter = "S";
  next_state_uid_set.insert(start_state_id);
  std::set<uint>::iterator next_state_uid_it(next_state_uid_set.begin());
  while(next_state_uid_it != next_state_uid_set.end()){
    State current_state = *states.find(State(*next_state_uid_it, "", false, false));
    NonTerminal current_non_terminal(current_state.GetID(),terminalLetter, current_state.IsStartingState(), current_state.IsFinalState());
    std::vector<std::pair<std::string, uint>> current_transitions = current_state.GetTransitions();
    uint non_terminal_death_counter = 0;
    for(size_t i = 0; i < current_transitions.size(); i++) {
      std::string aux = IdToTerminalLetter(current_transitions[i].second);
      if (current_non_terminal.GetName() == aux && !current_non_terminal.IsFinalNonTerminal()) non_terminal_death_counter++;
      std::pair<std::string, std::string> production(current_transitions[i].first, aux);
      next_state_uid_set.insert(current_transitions[i].second);
      current_non_terminal.AddProduction(production);
    }
    if(non_terminal_death_counter == current_transitions.size()) current_non_terminal.SetUselessNonTerminal(true);
    result.insert(current_non_terminal);
    next_state_uid_it++;
    if (next_state_uid_it != next_state_uid_set.end())terminalLetter = IdToTerminalLetter(*next_state_uid_it);
  }
  return result;
}


/**
 * @brief Funcion que escribe toda la especificacion de la gramatica formateada en el fichero de salida que se le especificó en el constructor,
 * parte del estado inicial para las producciones y prosigue segun las producciones del inicial
 */
  void Grammar::WriteOutputFile() {
    output_file_ << terminals_.GetAlphabetSize() << std::endl;
    for(auto symbol : terminals_.GetSymbolsSet()) {
      output_file_ << symbol << std::endl;
    }
    output_file_ << number_of_non_terminals_ << std::endl;
    std::set<NonTerminal>::iterator non_terminals_it;
    NonTerminal start_non_terminal;
    std::set<std::string> useless_non_terminal_symbols;
    for(non_terminals_it = non_terminals_.begin(); non_terminals_it != non_terminals_.end(); non_terminals_it++) {
      output_file_ << non_terminals_it->GetName() << std::endl;
      if(non_terminals_it->IsStartNonTerminal()) start_non_terminal = *non_terminals_it;
      if(non_terminals_it->IsUselessNonTerminal()) useless_non_terminal_symbols.insert(non_terminals_it->GetName()); 
    }
    output_file_ << start_non_terminal.GetName() << std::endl;
    for(non_terminals_it = non_terminals_.begin(); non_terminals_it != non_terminals_.end(); non_terminals_it++) {
      if(useless_non_terminal_symbols.find(non_terminals_it->GetName()) != useless_non_terminal_symbols.end()) continue;
      for(auto production: non_terminals_it->GetProductions()) {
        if(useless_non_terminal_symbols.find(production.second) != useless_non_terminal_symbols.end()) continue;
        output_file_ << non_terminals_it->GetName() + " -> " + production.first + production.second << std::endl;
      }
      if(non_terminals_it->IsFinalNonTerminal()) output_file_ << non_terminals_it->GetName() + " -> &" << std::endl;
    }
  }


