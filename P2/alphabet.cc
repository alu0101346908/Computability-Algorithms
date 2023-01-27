// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 12/10/2022
// Archivo alphabet.cc: Fichero con la implementacion de la clase Alphabet.
// Historial de revisiones 
//   12/10/2022 - Primera versión
//   12/10/2022 - Continuación de programación
//   13/10/2022 - Revision final

#include "alphabet.h"


  //Alphabet class constructor that given an input line, loads the given alphabet and language to their respectives attributes
Alphabet::Alphabet(std::string const &input_line) {
  std::string input_line_copy = input_line;
  int alphabet_ini_pos = input_line_copy.find_first_of("{");
  int alphabet_end_pos = input_line_copy.find_first_of("}");
  std::string alphabet = input_line_copy.substr(alphabet_ini_pos + 1, alphabet_end_pos - (alphabet_ini_pos + 1));
  input_line_copy = input_line_copy.substr(alphabet_end_pos + 1, input_line_copy.size() - alphabet_end_pos);
  int language_ini_pos = input_line_copy.find_first_of("{");
  int language_end_pos = input_line_copy.find_first_of("}");
  std::string language = input_line_copy.substr(language_ini_pos + 1, language_end_pos - (language_ini_pos + 1));


  char alphabet_copy[alphabet.length()];
  strcpy(alphabet_copy, alphabet.c_str());
  char* word_piece = strtok(alphabet_copy, " ");

  while (word_piece != NULL) {
    alphabet_.push_back(std::string(word_piece)); 
    word_piece = strtok(NULL, " "); 
  }

  char language_copy[language.length()];
  strcpy(language_copy, language.c_str());
  word_piece = strtok(language_copy, " ");
  while (word_piece != NULL) {
    language_.add_string(std::string(word_piece)); 
    word_piece = strtok(NULL, " "); 
  }
}

  //Alphabet class constructor that given a language, generates the alphabet from the given language and sets its attributes
Alphabet::Alphabet(Language language) {
  set_alphabet_from_language(language);
  language_=language;
}



  //Function that generates the alphabet from a given language
void Alphabet::set_alphabet_from_language(Language language) {
  alphabet_.clear();
  std::string input_string;
  bool in_alphabet = false;
  for(unsigned int k = 0; k < language.get_strings().size(); k++) {
    input_string = language.get_strings()[k].get_string();
    for(unsigned int i = 0; i < input_string.size(); i++) {
      for(unsigned int j = 0; j < alphabet_.size(); j++) {
        if (alphabet_[j] == std::string(1,input_string[i])) {
          in_alphabet = true;
        }
      }
      if (!in_alphabet) {
        if (std::string(1,input_string[i]) != EMPTY_STRING){
          alphabet_.push_back(std::string(1,input_string[i]));
        }
      }
      in_alphabet = false;
    }
  }
  
}

  //Getter of language_ attribute
Language Alphabet::get_language() {
  return language_;
}


//   //Returns the size of the string_ attribute
// int Alphabet::get_string_length(){
//   //return string_.get_string().size();
// } 

//   //Function that returns the reverse of its string_ by calling the String class method
// std::string Alphabet::get_reverse_string(){
//   //return string_.reverse();
// } 
//   //Function that returns the prefixes of its string_ by calling the String class method
// std::string Alphabet::get_prefix_strings(){
//   //return string_.prefixes();
// }

//   //Function that returns the suffixes of its string_ by calling the String class method
// std::string Alphabet::get_suffix_strings(){
//   //return string_.suffixes();
// }


//   //Function that returns the substrings of its string_ by calling the String class method
// std::string Alphabet::sub_strings(){
//   //return string_.substrings();
// }

  //Returns the string containing all the information about the class formatted
std::string Alphabet::info() {
  std::string info = "Alfabeto : {";
  for(unsigned int i = 0; i < alphabet_.size(); i++) {
    if (i == alphabet_.size()-1) {
      info = info + alphabet_[i];
    } else info = info + alphabet_[i] + ", ";
  }
  return info + "} \t L: " +language_.info();

  // std::string unused_symbols = get_unused_symbols();
  // if(unused_symbols != "") {
  //   return info + "}" + "\n" + "Simbolos sin usar: " + unused_symbols + "\n" + "Cadena: {" + string_.get_string() + "}";
  // }
  // else return info + "}" + "\n" + "Se usan todos los simbolos\n" + "Cadena: {" + string_.get_string() + "}";

}

// std::string Alphabet::get_unused_symbols() {
//   std::string string_copy = string_.get_string();
//   std::vector<std::string> symbols;
//   std::string unused_symbols = "";
//   std::string dummy = "";
//   bool found = false;
//   for (int i = 0; i < alphabet_.size(); i++) {
//     for (int k = 0; k < alphabet_[i].size(); k++) {
//       for (int j = 0; j < string_copy.size(); j++) {
//         if (string_copy[j] == alphabet_[i][k]){
//           found = true;
//         }
//       }
//       if (!found) {
//         unused_symbols = unused_symbols + " " + alphabet_[i][k]; 
//       }
//       found = false;
//     }
//   }
//   return unused_symbols;
// }