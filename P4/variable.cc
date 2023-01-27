// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 26/10/2022
// Archivo variable.cc: Fichero con la implementacion de la clase Variable.
// Historial de revisiones 
//   25/10/2022 - Primera versión
//   25/10/2022 - Continuación de programación
//   26/10/2022 - Revision final

#include "variable.h"

// Costructor que recibe el nombre del tipo de variable y la linea donde se encuentra
Variable::Variable(std::string type, size_t line) {
  line_ = line;
  type_ = type;
}


size_t Variable::get_line() const {
  return line_;
}



std::string Variable::get_type() const {
  return type_;
}


// Devuelve la informacion almacenada en la clase formateada correctamente en una string
std::string Variable::print() const {
  return "[Line " + std::to_string(line_) + "] " + type_;
}