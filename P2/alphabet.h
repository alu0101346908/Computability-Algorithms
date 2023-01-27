// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 12/10/2022
// Archivo alphabet.h: Fichero con la definición de la clase Alphabet.
// Historial de revisiones 
//   12/10/2022 - Primera versión
//   12/10/2022 - Continuación de programación
//   13/10/2022 - Revision final
#ifndef ALPHABET_H
#define ALPHABET_H

#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "language.h"


class Alphabet {
  public:
  Alphabet(std::string const &input_line);
  Alphabet(Language language);
  std::string info();
  Language get_language();
  std::string concatenate_language(Language language);
  void set_alphabet_from_string(std::string string_);
  void set_alphabet_from_language(Language language);
  // std::string get_reverse_string();
  // int get_string_length();
  // std::string get_prefix_strings();
  // std::string get_suffix_strings();
  // std::string sub_strings();
  // std::string get_unused_symbols();
  private:
    std::vector<std::string> alphabet_;
    Language language_;
};

#endif