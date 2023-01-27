// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 19/10/2022
// Archivo language.cc: Fichero con la implementacion de la clase Language.
// Historial de revisiones
//   12/10/2022 - Primera versión
//   12/10/2022 - Continuación de programación
//   13/10/2022 - Revision final
//   18/10/2022 - Segunda versión
//   19/10/2022 - Continuación de programación
//   19/10/2022 - Revision final


#include "language.h"
//Default constructor of the Language class
  Language::Language(){}

//  Constructor of the Language class that given a string containing a language loads the strings and the name of the language 
  Language::Language(std::string language_string) {
    std::string dummy_name = "";
    for(unsigned int i = 0; i < language_string.size(); i++) {
      if(language_string[i] == '=') {
        name_ = dummy_name;
        dummy_name = "";
      }
      dummy_name = dummy_name + language_string[i];
      if(language_string[i] == '{') {
        std::string dummy_string = "";
        for(i++; i < language_string.size(); i++) {
          if(language_string[i] == ',' || language_string[i] == '}') {
            if(dummy_string != "")add_string(dummy_string);
            dummy_string = "";
          } else {
            dummy_string = dummy_string + language_string[i];
          }
        }
      }
    }
  }
  //Language class setter for its array of string attribute
void Language::add_string(std::string string) {
  String new_string;
  new_string.set_string(string);
  strings_.push_back(new_string);
}

  //Language class getter for its array of string attribute

  //Language class getter for its array of string attribute
std::vector<String> Language::get_strings() const {

  return strings_;
}

  //Language class getter for its name 
std::string Language::get_name() const{

  return name_;
}
  //Language class getter for its name 
std::string Language::get_name_from() const{

  return name_from_;
}
  //Language class setter for its name 
void Language::set_name(std::string name){

  name_ = name;
}
  //Language class setter for its name from
void Language::set_name_from(std::string name) {

  name_from_ = name;
}

  //Returns the string containing all the information about the class formatted
std::string Language::info() const{
  std::string info = "{";
  std::string dummy = "";
  for(unsigned int i = 0; i < strings_.size(); i++) {
    dummy = strings_[i].get_string();
    if (i == strings_.size()-1) {
      info = info + strings_[i].get_string();
    } else info = info + strings_[i].get_string() + ", ";
  }
  return get_name_from().empty() ? get_name() : (get_name_from()+" -> "+get_name()) + " : "+ info + "}";
}

  //Overloaded operator+ that represents the concatenation operation, the function iterates over both operands strings
  //making all possibilities and filtering them if they already exist on the result language, also checks if some of the operands
  //string contains the EMPTY_STRING to avoid concatenating the symbol itself with the other operand
Language Language::operator+ (Language language_right) {
  Language language_result;
  bool found = false;
  bool empty_string = false;
  bool empty_string_dual = false;
  std::vector<String> language_right_strings = language_right.get_strings();
  for(int i = 0; i < strings_.size(); i++) {
    for(int j = 0; j < language_right_strings.size(); j++) {
      if(i == 0 && j == 0) {
        if((strings_[i].get_string() == std::string(EMPTY_STRING)) && (language_right_strings[j].get_string() != std::string(EMPTY_STRING))) {
          language_result.add_string(language_right_strings[j].get_string());
        } else if((strings_[i].get_string() != std::string(EMPTY_STRING)) && (language_right_strings[j].get_string() == std::string(EMPTY_STRING))) {
          language_result.add_string(strings_[i].get_string());
        } else if((strings_[i].get_string() == std::string(EMPTY_STRING)) && (language_right_strings[j].get_string() == std::string(EMPTY_STRING))) {
          language_result.add_string(EMPTY_STRING);
        } else {
          language_result.add_string(strings_[i].get_string()+language_right_strings[j].get_string());
        }
      }
      else {
        for(int k = 0; k < language_result.get_strings().size(); k++) {
          if ((strings_[i].get_string() != std::string(EMPTY_STRING)) && (language_right_strings[j].get_string() != std::string(EMPTY_STRING))){
            if(language_result.get_strings()[k].get_string() == strings_[i].get_string()+language_right_strings[j].get_string()) {
              found = true;
            }
          } else if((strings_[i].get_string() == std::string(EMPTY_STRING)) && (language_right_strings[j].get_string() != std::string(EMPTY_STRING))) {
            if(language_result.get_strings()[k].get_string() == language_right_strings[j].get_string()) {
              found = true;
              empty_string = true;
            }
          } else if((strings_[i].get_string() != std::string(EMPTY_STRING)) && (language_right_strings[j].get_string() == std::string(EMPTY_STRING))) {
            if(language_result.get_strings()[k].get_string() == strings_[i].get_string()) {
              empty_string = true;
              found = true;
            }
          } else if((strings_[i].get_string() == std::string(EMPTY_STRING)) && (language_right_strings[j].get_string() == std::string(EMPTY_STRING))) {
            empty_string_dual = true;
          }
        }
        if (!found) {
          if (empty_string_dual) {
            language_result.add_string(std::string(EMPTY_STRING));
          } else if (strings_[i].get_string() == std::string(EMPTY_STRING)) {
            language_result.add_string(language_right_strings[j].get_string());
          } else if (language_right_strings[j].get_string() == std::string(EMPTY_STRING)) {
            language_result.add_string(strings_[i].get_string());
          } else language_result.add_string(strings_[i].get_string()+language_right_strings[j].get_string());
        } 
        empty_string = false;
        empty_string_dual = false;
        found = false;
      }
    }
  }
  language_result.set_name_from(language_right.get_name()+'+'+get_name());
  return language_result;
}

  //Overloaded operator| that represents the union operation, the function iterates over both operands strings
  //making all possibilities and filtering them if they already exist on the result language
Language Language::operator| (Language language_right) {
  Language language_result;
  bool found = false;
  std::vector<String> language_right_strings = language_right.get_strings();
  for(int i = 0; i < strings_.size(); i++) {
    language_result.add_string(strings_[i].get_string());
  }
  for(int i = 0; i < language_right_strings.size(); i++) {
    for(int k = 0; k < language_result.get_strings().size(); k++) {
      if(language_result.get_strings()[k].get_string() == language_right_strings[i].get_string()) {
        found = true;
      }
    }
    if (!found) {
      language_result.add_string(language_right_strings[i].get_string());
    } 
    found = false;
  }
  language_result.set_name_from(language_right.get_name()+'|'+get_name());
  return language_result;
}

  //Overloaded operator^ that represents the intersection operation, the function iterates over both operands strings
  //making all possibilities
Language Language::operator^ (Language language_right) {
  Language language_result;
  std::vector<String> language_right_strings = language_right.get_strings();
  for(int i = 0; i < strings_.size(); i++) {
    for(int j = 0; j < language_right_strings.size(); j++) {
      if (strings_[i].get_string() == language_right_strings[j].get_string()){
        language_result.add_string(strings_[i].get_string());
      }
    }
  }
  language_result.set_name_from(get_name()+'^'+language_right.get_name());
  return language_result;
}
  //Overloaded operator- that represents the difference operation, the function iterates over both operands strings
  //making all possibilities and filtering them if they already exist on the result language
Language Language::operator- (Language language_right) {
  Language language_result;
  bool found = false;
  std::vector<String> language_right_strings = language_right.get_strings();
  for(int i = 0; i < strings_.size(); i++) {
    for(int j = 0; j < language_right_strings.size(); j++) {
      if (strings_[i].get_string() == language_right_strings[j].get_string()){
        found = true;
      }
    }
    if(!found)language_result.add_string(strings_[i].get_string());
    found = false;
  }
  language_result.set_name_from(language_right.get_name()+'-'+get_name());
  return language_result;
}
  //Overloaded operator! that represents the inverse operation, the function iterates over the invocant strings
  //reversing them and adding it to the result language
Language Language::operator! () {
  Language language_result;
  std::string reversed_string;
  for(int i = 0; i < strings_.size(); i++) {
    reversed_string = strings_[i].get_string();
    std::reverse(reversed_string.begin(), reversed_string.end());
    language_result.add_string(reversed_string);
  }
  language_result.set_name_from('!'+get_name());
  return language_result;
}

  //Overloaded operator* that represents the power operation, the function iterates over the invocant strings
  // and operates them using the concatenation operator *
Language Language::operator* (int exponent) {
  Language language_itself = *this;
  Language language_result;
  std::string reversed_string;
  if(exponent == 0) {
    language_result.add_string(EMPTY_STRING);
  } else {
    language_result = language_result | language_itself;
    if(exponent > 1) {
      for(int i = 1; i < exponent; i++) {
        language_result = language_result + language_itself;
      }
    }
  }
  language_result.set_name_from(get_name()+'*'+std::to_string(exponent));
  return language_result;
}

  //Overloaded operator< that the set class needs to check if a value exists already in the set when inserting and searching (its result its irrelevant)

bool Language::operator< (Language const language_right) const{

  if(stoi(name_.substr(1,name_.size()-1)) < stoi(language_right.get_name().substr(1,language_right.get_name().size()-1))) {
    return true;
  }
  return false;
}
