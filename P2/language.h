// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 12/10/2022
// Archivo language.h: Fichero con la definición de la clase Language.
// Historial de revisiones 
//   12/10/2022 - Primera versión
//   12/10/2022 - Continuación de programación
//   13/10/2022 - Revision final

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "string.h"


class Language {
  public:
  void add_string(std::string string);
  std::vector<String> get_strings();
  friend std::ostream& operator<< (std::ostream&, Language&);
  friend std::ofstream& operator<< (std::ofstream&, Language&);
  Language operator* (Language language_right);
  Language operator+ (Language language_right);
  Language operator/ (Language language_right);
  Language operator- (Language language_right);
  Language operator~ ();
  Language operator^ (int exponent);
  std::string info();
  private:
    std::vector<String> strings_;
};

#endif