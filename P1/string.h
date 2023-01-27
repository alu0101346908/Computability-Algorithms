// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 03/10/2022
// Archivo string.h: Fichero con la definición de la clase String.
// Historial de revisiones 
//   03/10/2022 - Primera versión
//   04/10/2022 - Continuación de programación
//   05/10/2022 - Revision final
#ifndef STRING_H
#define STRING_H

#include <vector>
#include <string>

#define EMPTY_STRING "&"

class String {
  public:
    void set_string(std::string const str);
    std::string get_string();
    std::string reverse();
    std::string prefixes();
    std::string suffixes();
    std::string substrings();
  private:
    std::string string_;
};


#endif