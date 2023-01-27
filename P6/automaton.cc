// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 6: Simulación de autómatas finitos
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 9/11/2022
// Archivo automaton.cc: Fichero con la implementacion de la clase Automaton.
// Historial de revisiones 
//   7/11/2022 - Primera versión
//   8/11/2022 - Continuación de programación
//   9/11/2022 - Revision final

#include "automaton.h"

/**
 * @brief Constructor de la clase Automaton, carga el fichero .fa añadiendo los estados y las transiciones comprobando al final que el fichero es correcto (numero de estados)
 * Además almacena el fichero de cadenas para ser tratado posteriormente en start()
 * 
 * @param fa_file_name Nombre del fichero de especificacion .fa
 * @param strings_file_name Nombre del fichero que contiene las cadenas que se comprobaran con el DFA/NFA
 */
Automaton::Automaton(std::string fa_file_name, std::string strings_file_name, std::string output_file_name) {
  fa_file_ = std::ifstream(fa_file_name, std::fstream::in);
  strings_file_ = std::ifstream(strings_file_name, std::fstream::in);
  output_file_ = std::ofstream(output_file_name, std::fstream::out);
  if (!fa_file_.good() || !strings_file_.good() || !output_file_.good()) {
    throw("Fa file or Input file, or output file doesnt exist, try again");
  }
  std::string read_line = "";
  std::string start_state_name = "";
  std::string state_name = "";
  bool is_start_state = false;
  bool is_final_state = false;
  int number_of_transitions = 0;
  while(!fa_file_.eof()) {

    getline(fa_file_, read_line);
    alphabet_ = Alphabet(read_line);
    
    fa_file_ >> read_line;
    number_of_states_ = stoi(read_line);
    fa_file_ >> read_line;
    start_state_name = stoi(read_line);
    int i = 0;
    while(i < number_of_states_ && !fa_file_.eof()) {
      fa_file_ >> state_name >> is_final_state >> number_of_transitions;
      if(start_state_name == state_name) is_start_state = true;
      else is_start_state = false;
      State new_state(stoi(state_name), state_name, is_start_state, is_final_state);
      for(int j = 0; j < number_of_transitions; j++) {
        std::string symbol = "";
        uint to_state_id = 0;
        fa_file_ >> symbol >> to_state_id;
        alphabet_.add_symbol(symbol);
        std::pair<std::string, uint> transition(symbol,to_state_id);
        new_state.add_transition(transition);
      }
      states_.insert(new_state);
      i++;
    }
    if(i != number_of_states_) throw("Missing states specification, cant proceed\n");
    if(i > number_of_states_) throw("There are more states descriptions than the number of states\n");
  }
}

/**
 * @brief Destructor de la clase Automaton que cierra el fichero .fa y el de cadenas
 * 
 */
Automaton::~Automaton() {

  if (fa_file_.is_open()) {
    fa_file_.close();;
  }
  if (strings_file_.is_open()) {
    strings_file_.close();
  }
}


/**
 * @brief Funcion intermedia que va leyendo del fichero de cadenas y comprobando que la cadena no tiene simbolos no pertenecientes al alfabeto
 * 
 */
void Automaton::start() {
  std::string aux;
  alphabet_.print();
  if (strings_file_.is_open()) {
    while (!strings_file_.eof()) {
      strings_file_ >> aux;      
      if (alphabet_.symbols_in_alphabet(aux) && validate_string(aux)) {
        std::cout << aux << " --> ACCEPTED" << std::endl;
        output_file_ << aux << " --> ACCEPTED" << std::endl;
      } else {
        std::cout << aux << " --> REJECTED" << std::endl;
        output_file_ << aux << " --> REJECTED" << std::endl;
      }
    }
  } else throw("Cant start without a string file loaded\n");
}

/**
 * @brief Funcion que recibe la cadena a comprobar si es aceptada o no por el automata
 * 
 * @param string Cadena a comprobar
 * @return true Si es aceptada
 * @return false Si es rechazada
 */
bool Automaton::validate_string(std::string string) {
  std::set<State>::iterator states(states_.begin());
  return transit_fa(states, string);
}

/**
 * @brief Algoritmo recursivo principal el cual recibe un iterado de estados y la cadena. En cada invocacion se va a extraer el primer simbolo
 * de la cadena, se va a invocar a transition_with_symbol para devolver las transiciones posibles desde el estado actual con el simbolo de la cadena.
 * Posteriormente se van a recorrer todas las transiciones resultantes (NFA) y se va a volver a invocar recursivamente con el iterador apuntando al
 * estado de la transicion (find) con la cadena sin el simbolo actual si no se trata de una E-transicion. Si es una E-transicion se invoca con la misma cadena
 * pero con el estado transitado.
 * Si alguna de estas invocaciones recursivas acepta, se devuelve true, si se acaban las transiciones y no se da se devuelve false.
 * 
 * @param states Iterador de los estados que contiene el puntero al estado actual
 * @param string Cadena de la que se va extrayendo los simbolos y realizando las transiciones
 * @return true Si se para en un estado de aceptacion
 * @return false Si se para en un estado que no es de aceptacion
 */
bool Automaton::transit_fa(std::set<State>::iterator &states, std::string string) {
  int symbol_length = 1;
  if(string.empty()){

    return states->is_final_state();
    //std::cout << states->get_id() << std::endl;
    //std::cout << states->is_final_state() << std::endl;
  }
  std::vector<std::pair<std::string,uint>> found_transitions = states->transition_with_symbol(string, symbol_length);
  //std::cout << found_transitions.size() << std::endl;
  for(std::pair<std::string,uint> transition : found_transitions) {
    //std::cout << transition.first << std::endl;
    //std::cout << transition.second << std::endl;
    states = states_.find(State(transition.second, "", false, false));
    //std::cout << states->get_id() << std::endl;
    if (transition.first != "&"){
      if(transit_fa(states, string.substr(1,string.length()))) return true;
    } else if(transit_fa(states, string)) return true;
  }
  return false;
}


