// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 03/10/2022
// Archivo alphabet.h: Fichero con la definición de la clase Alphabet.
// Historial de revisiones 
//   03/10/2022 - Primera versión
//   04/10/2022 - Continuación de programación
//   05/10/2022 - Revision final
#ifndef ALPHABET_H
#define ALPHABET_H

#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "string.h"


class Alphabet {
  public:
  Alphabet(std::string const &input_line);
  std::string info();
  void set_alphabet_from_string(std::string string_);
  std::string get_reverse_string();
  int get_string_length();
  std::string get_prefix_strings();
  std::string get_suffix_strings();
  std::string sub_strings();
  std::string get_unused_symbols();
  private:
    std::vector<std::string> alphabet_;
    String string_;
};

#endif