// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 03/10/2022
// Archivo alphabet.h: Fichero con la implementacion de la clase Alphabet.
// Historial de revisiones 
//   03/10/2022 - Primera versión
//   04/10/2022 - Continuación de programación
//   05/10/2022 - Revision final

#include "alphabet.h"


  //Alphabet class constructor that given an input line, loads the given alphabet and string to their respectives attributes,
  // if the alphabet is not given, it generates it through set_alphabet_from_string
Alphabet::Alphabet(std::string const &input_line) {
  
  char input_line_copy[input_line.length()];
  strcpy(input_line_copy, input_line.c_str());
  char* word_piece = strtok(input_line_copy, " ");

  while (word_piece != NULL) {  // https://cplusplus.com/reference/cstring/strtok/
    alphabet_.push_back(std::string(word_piece)); 
    word_piece = strtok(NULL, " "); 
  }
  string_.set_string(alphabet_.back().data());
  if (alphabet_.size() >= 2) {
    alphabet_.pop_back();
  }
  else {
    set_alphabet_from_string(string_.get_string());
  }

}

  //Function that generates the alphabet from a given string
void Alphabet::set_alphabet_from_string(std::string input_string) {
  alphabet_.clear();
  bool in_alphabet = false;
  for(unsigned int i = 0; i < input_string.size(); i++) {
    for(unsigned int j = 0; j < alphabet_.size(); j++) {
      if (alphabet_[j] == std::string(1,input_string[i])) {
        in_alphabet = true;
      }
    }
    if (!in_alphabet)alphabet_.push_back(std::string(1,input_string[i]));
    in_alphabet = false;
  }
}

  //Returns the size of the string_ attribute
int Alphabet::get_string_length(){
  return string_.get_string().size();
} 

  //Function that returns the reverse of its string_ by calling the String class method
std::string Alphabet::get_reverse_string(){
  return string_.reverse();
} 
  //Function that returns the prefixes of its string_ by calling the String class method
std::string Alphabet::get_prefix_strings(){
  return string_.prefixes();
}

  //Function that returns the suffixes of its string_ by calling the String class method
std::string Alphabet::get_suffix_strings(){
  return string_.suffixes();
}


  //Function that returns the substrings of its string_ by calling the String class method
std::string Alphabet::sub_strings(){
  return string_.substrings();
}

  //Returns the string containing all the information about the class formatted
std::string Alphabet::info() {
  std::string info = "Alfabeto : {";
  for(unsigned int i = 0; i < alphabet_.size(); i++) {
    if (i == alphabet_.size()-1) {
      info = info + alphabet_[i];
    } else info = info + alphabet_[i] + ", ";
  }
  std::string unused_symbols = get_unused_symbols();
  if(unused_symbols != "") {
    return info + "}" + "\n" + "Simbolos sin usar: " + unused_symbols + "\n" + "Cadena: {" + string_.get_string() + "}";
  }
  else return info + "}" + "\n" + "Se usan todos los simbolos\n" + "Cadena: {" + string_.get_string() + "}";

}

std::string Alphabet::get_unused_symbols() {
  std::string string_copy = string_.get_string();
  std::vector<std::string> symbols;
  std::string unused_symbols = "";
  std::string dummy = "";
  bool found = false;
  for (int i = 0; i < alphabet_.size(); i++) {
    for (int k = 0; k < alphabet_[i].size(); k++) {
      for (int j = 0; j < string_copy.size(); j++) {
        if (string_copy[j] == alphabet_[i][k]){
          found = true;
        }
      }
      if (!found) {
        unused_symbols = unused_symbols + " " + alphabet_[i][k]; 
      }
      found = false;
    }
  }
  return unused_symbols;
}