// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 8: Gramaticas en Forma Normal de Chomsky
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 23/11/2022
// Archivo grammar.cc: Fichero con la implementacion de la clase Grammar.
// Historial de revisiones 
//   21/11/2022 - Primera versión
//   22/11/2022 - Continuación de programación
//   23/11/2022 - Revision final

#include "grammar.h"

/**
 * @brief Constructor que recibe el bloque de texto que representa el fichero .gr que se pasa por entrada, se añaden 
 *        los no terminales, los terminales y sus correspondientes producciones
 * 
 * @param input Bloque de texto = fichero de entrada de la gramatica 
 */
Grammar::Grammar(std::string input) {

  std::string read_line = "";
  std::string start_non_terminal_name = "";
  std::string left_side_production = "";
  std::string right_side_production = "";
  std::string separator = "";
  bool is_start_prod = false;
  uint terminals_number = 0;
  std::set<NonTerminal> non_terminals_temp;
  input = input + "\n";
  std::istringstream input_stream(input);
  while(!input_stream.eof()) {
    getline(input_stream, read_line);
    terminals_number = stoi(read_line);
    for(uint i = 0; i < terminals_number; i++) {
      getline(input_stream, read_line);
      terminals_.AddSymbol(read_line);
    }
    input_stream >> read_line;
    number_of_non_terminals_ = stoi(read_line);
    input_stream >> read_line;
    start_non_terminal_name = read_line;
    uint i = 0;
    while(i < number_of_non_terminals_ && !input_stream.eof()) {
      input_stream >> read_line;
      if(start_non_terminal_name == read_line) is_start_prod = true;
      else is_start_prod = false;
      NonTerminal non_terminal(read_line, is_start_prod, false);
      non_terminals_.insert(non_terminal);
      i++;
    }
    i = 0;
    input_stream >> left_side_production >> separator >> right_side_production;
    while(i < number_of_non_terminals_) {
      NonTerminal current_non_terminal = *non_terminals_.find(NonTerminal(left_side_production, is_start_prod, false));
      while(left_side_production == current_non_terminal.GetName() && !input_stream.eof()) {
        if(right_side_production == "&") current_non_terminal.SetFinalNonTerminal(true);
        current_non_terminal.AddProduction(right_side_production);
        input_stream >> left_side_production >> separator >> right_side_production;
      }
      non_terminals_temp.insert(current_non_terminal);
      i++;
    }
  }
  non_terminals_ = non_terminals_temp;
}


/**
 * @brief Destructor por defecto
 */
Grammar::~Grammar() {
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

// /**
//  * @brief Recibe un set de estados (States) que se convertiran en un set de no terminales (NonTerminals), por cada State se crea un no terminal cuya producciones
//  * seran las transiciones del propio estado
//  * @param states Set de estados
//  * @return std::set<NonTerminal> Set de no terminales resultantes de la conversion 
//  */
// std::set<NonTerminal> Grammar::StatesToNonTerminal(std::set<State> states) {
//   std::set<State>::iterator it;
//   std::set<NonTerminal> result;
//   input_streamuint start_state_id;
//   for(it = states.begin(); it!= states.end(); it++) {
//     if(it->IsStartingState()) start_state_id = it->GetID();
//   }
//   std::set<uint> next_state_uid_set;
//   std::string terminalLetter = "S";
//   next_state_uid_set.insert(start_state_id);
//   std::set<uint>::iterator next_state_uid_it(next_state_uid_set.begin());
//   while(next_state_uid_it != next_state_uid_set.end()){
//     State current_state = *states.find(State(*next_state_uid_it, "", false, false));
//     NonTerminal current_non_terminal(current_state.GetID(),terminalLetter, current_state.IsStartingState(), current_state.IsFinalState());
//     std::vector<std::pair<std::string, uint>> current_transitions = current_state.GetTransitions();
//     uint non_terminal_death_counter = 0;
//     for(size_t i = 0; i < current_transitions.size(); i++) {
//       std::string aux = IdToTerminalLetter(current_transitions[i].second);
//       if (current_non_terminal.GetName() == aux && !current_non_terminal.IsFinalNonTerminal()) non_terminal_death_counter++;
//       std::pair<std::string, std::string> production(current_transitions[i].first, aux);
//       next_state_uid_set.insert(current_transitions[i].second);
//       current_non_terminal.AddProduction(production);
//     }
//     if(non_terminal_death_counter == current_transitions.size()) current_non_terminal.SetUselessNonTerminal(true);
//     result.insert(current_non_terminal);
//     next_state_uid_it++;
//     if (next_state_uid_it != next_state_uid_set.end())terminalLetter = IdToTerminalLetter(*next_state_uid_it);
//   }
//   return result;
// }


/**
 * @brief Funcion que escribe toda la especificacion de la gramatica formateada por pantalla y la devuelve como un string para poder
 *        añadirselo al fichero de salida
 */
  std::string Grammar::Print() {
    std::string formatted_string = "";
    formatted_string += std::to_string(terminals_.GetAlphabetSize()) + "\n";
    for(auto symbol : terminals_.GetSymbolsSet()) {
      formatted_string += symbol + "\n";
    }
    formatted_string += std::to_string(number_of_non_terminals_) + "\n";
    std::set<NonTerminal>::iterator non_terminals_it;
    NonTerminal start_non_terminal;
    std::set<std::string> useless_non_terminal_symbols;
    for(non_terminals_it = non_terminals_.begin(); non_terminals_it != non_terminals_.end(); non_terminals_it++) {
      formatted_string += non_terminals_it->GetName() + "\n";
      if(non_terminals_it->IsStartNonTerminal()) start_non_terminal = *non_terminals_it;
      if(non_terminals_it->IsUselessNonTerminal()) useless_non_terminal_symbols.insert(non_terminals_it->GetName()); 
    }
    formatted_string += start_non_terminal.GetName() + "\n";
    for(non_terminals_it = non_terminals_.begin(); non_terminals_it != non_terminals_.end(); non_terminals_it++) {
      if(useless_non_terminal_symbols.find(non_terminals_it->GetName()) != useless_non_terminal_symbols.end()) continue;
      for(auto production: non_terminals_it->GetProductions()) {
        if(useless_non_terminal_symbols.find(production) != useless_non_terminal_symbols.end()) continue;
        formatted_string += non_terminals_it->GetName() + " -> " + production + "\n";
      }
      if(non_terminals_it->IsFinalNonTerminal()) formatted_string += non_terminals_it->GetName() + " -> &" + "\n";
    }
    std::cout << formatted_string;
    return formatted_string;
  }
/**
 * @brief Metodo que hace la transformacion de CFG a FNC, esta dividido en dos pasos que se van a invocar
 * 
 */
void Grammar::CfgToChomsky() {

  CfgToChomskyFirstPart();
  CfgToChomskySecondPart();
}

/**
 * @brief Primer paso de la transformacion de CFG a Chomsky donde se añadiran nuevos no terminales si la produccion
 *  genera un terminal y es >=2
 * 
 */
void Grammar::CfgToChomskyFirstPart() {
  std::set<NonTerminal> new_non_terminals;
  std::string aux_prod = "";
  std::string aux_name = "";
  std::set<NonTerminal> non_terminals_copy = non_terminals_;
  for(std::set<NonTerminal>::iterator it_non_terminal = non_terminals_copy.begin(); it_non_terminal != non_terminals_copy.end(); it_non_terminal++) {
    NonTerminal temp (it_non_terminal->GetName(), it_non_terminal->IsStartNonTerminal(), it_non_terminal->IsFinalNonTerminal()); 
    std::set<std::string> it_non_terminals_productions = it_non_terminal->GetProductions();
    std::set<std::string>::iterator it_prod = it_non_terminals_productions.begin();
    std::set<std::string>::iterator it_prod_end = it_non_terminals_productions.end();
    while(it_prod != it_prod_end) {
      if(it_prod->length() >= 2) {
        aux_prod = "" + *it_prod;
        for(uint i = 0; i < aux_prod.length(); i++) {
          std::string terminal = aux_prod.substr(i,1);
          if(terminals_.SymbolInAlphabet(terminal)) {
            aux_name = "U_"+terminal;
            NonTerminal auxiliar(aux_name,false,false);
            auxiliar.AddProduction(terminal);
            new_non_terminals.insert(auxiliar);
            aux_prod = std::regex_replace(aux_prod, std::regex(terminal), aux_name);
            i = i + 2; 
          }
        }
        temp.AddProduction(aux_prod);
      } else {
        temp.AddProduction(*it_prod);
      }
      it_prod++;
    }
    new_non_terminals.insert(temp);
  }
  non_terminals_ = new_non_terminals;
}

/**
 * @brief Segundo paso de la transformacion de CFG a FNC donde ya habiendo separado las producciones de terminales y no terminales
 * se procede a crear tantos nuevos no terminales y producciones como sea necesario para que el tamaño maximo de una produccion
 * sea de 2 elementos
 * 
 */
void Grammar::CfgToChomskySecondPart() {

std::set<NonTerminal> new_non_terminals;
  std::string aux_prod = "";
  std::string aux_name = "";
  std::set<NonTerminal> non_terminals_copy = non_terminals_;
  std::vector<std::string> k_non_terminals_names;
  number_of_non_terminals_ = 0;
  int counter = 1;
  for(std::set<NonTerminal>::iterator it_non_terminal = non_terminals_copy.begin(); it_non_terminal != non_terminals_copy.end(); it_non_terminal++) {
    number_of_non_terminals_++;
    NonTerminal temp (it_non_terminal->GetName(), it_non_terminal->IsStartNonTerminal(), it_non_terminal->IsFinalNonTerminal()); 
    std::set<std::string> it_non_terminals_productions = it_non_terminal->GetProductions();
    std::set<std::string>::iterator it_prod = it_non_terminals_productions.begin();
    std::set<std::string>::iterator it_prod_end = it_non_terminals_productions.end();
    while(it_prod != it_prod_end) {
      std::string aux2 = std::regex_replace(*it_prod, std::regex("._"), "");
      std::string to_new_prod;
      if(aux2.length() >= 3) {
        if(std::regex_search(it_prod->substr(0,2), std::regex("._"))) {
          to_new_prod = it_prod->substr(3,it_prod->length()-3);
        } else {
          to_new_prod = it_prod->substr(1,it_prod->length()-1);
        }
        aux_name = "V_" + std::to_string(counter);
        aux_prod = "" + *it_prod;
        NonTerminal auxiliar(aux_name,false,false);
        auxiliar.AddProduction(to_new_prod);
        new_non_terminals.insert(auxiliar);
        non_terminals_copy.insert(auxiliar);
        aux_prod = std::regex_replace(aux_prod, std::regex(to_new_prod), aux_name);
        counter++;
        temp.AddProduction(aux_prod);
      } else {
        temp.AddProduction(*it_prod);
      }
      it_prod++;
    }
    if(new_non_terminals.find(temp) != new_non_terminals.end()){
      new_non_terminals.erase(new_non_terminals.find(temp));
    }
    new_non_terminals.insert(temp);
  }
  non_terminals_ = new_non_terminals;


}
