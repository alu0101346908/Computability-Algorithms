// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 19/10/2022
// Archivo string.cc: Fichero con la implementacion de la clase String.
// Historial de revisiones 
//   03/10/2022 - Primera versión
//   04/10/2022 - Continuación de programación
//   05/10/2022 - Revision final

#include "string.h"


  //Setter of the String class attribute string_
void String::set_string(std::string const str) {
  string_ = str;
}

  //Getter of the String class attribute string_
std::string String::get_string() const{
  return string_;
}

  // Function that returns the reverse of the string_ attribute
std::string String::reverse(){
  std::string string_copy = string_;
  std::string reversed_string = "";
  unsigned int iterator = 1;
  while (iterator <= string_copy.size()){
    reversed_string = reversed_string + string_copy[string_copy.size()-iterator];
    iterator++;
  }
  return reversed_string;
} 

  // Returns all possible prefixes of the string_ attribute
std::string String::prefixes(){
  std::string string_copy = string_;
  std::string partial_string = "";
  std::vector<std::string> prefix_string_array;
  prefix_string_array.push_back(EMPTY_STRING);

  for(unsigned int i = 0; i < string_copy.size(); i++) {
    for(unsigned int j = 0; j <= i; j++) {
      partial_string = partial_string + string_copy[j];
    }
    prefix_string_array.push_back(partial_string);
    partial_string = "";
  }
  std::string output_string = "";
  for(unsigned int i = 0; i < prefix_string_array.size(); i++) {
    output_string = output_string + prefix_string_array[i] + " ";
  }
  return output_string;
}
  //Returns all the possible suffixes of the string_ attribute
std::string String::suffixes(){
  std::string string_copy = string_;
  std::string partial_string = "";
  std::vector<std::string> suffix_string_array;
  suffix_string_array.push_back(EMPTY_STRING);

  unsigned int iterator = 1;
  while (iterator <= string_copy.size()){
    partial_string = partial_string + string_copy[string_copy.size()-iterator];
    suffix_string_array.push_back(partial_string);
    iterator++;
  }

  std::string output_string = "";
  for(unsigned int i = 0; i < suffix_string_array.size(); i++) {
    output_string = output_string + suffix_string_array[i] + " ";
  }
  return output_string;
}

  //Returns all the possible substrings of the string_ attribute
std::string String::substrings(){
  std::string string_copy = string_;
  std::string partial_string = "";
  std::vector<std::string> sub_string_array;
  bool exist = false;
  sub_string_array.push_back(EMPTY_STRING);
    for (int i = 1; i <= string_copy.size(); i++) {   
      for (int j = 0; j <= string_copy.size() - i; j++) {
        int x = j + i - 1;                
        for (int k = j; k <= x; k++) {
          partial_string = partial_string + string_copy[k];
        }
        for (int z = 0; z < sub_string_array.size(); z++) { //Checks to avoid duplicates
          if (sub_string_array[z] == partial_string) {
            exist = true;
          }
        }
        if (!exist) sub_string_array.push_back(partial_string); // If its not in the array we add it
        exist = false;
        partial_string = "";
      }
    }
  std::string output_string = "";
  for(unsigned int i = 0; i < sub_string_array.size(); i++) {
    output_string = output_string + sub_string_array[i] + "\n";
  }
  return output_string;
}
