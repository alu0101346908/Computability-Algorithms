// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 26/10/2022
// Archivo loop.cc: Fichero con la implementacion de la clase Loop.
// Historial de revisiones 
//   25/10/2022 - Primera versión
//   25/10/2022 - Continuación de programación
//   26/10/2022 - Revision final

#include "loop.h"

// Costructor que recibe el nombre del tipo de loop y la linea donde se encuentra
Loop::Loop(std::string type, size_t line) {
  line_ = line;
  type_ = type;
}

size_t Loop::get_line() const {
  return line_;
}


std::string Loop::get_type() const {
  return type_;
}

// Devuelve la informacion almacenada en la clase formateada correctamente en una string
std::string Loop::print() const {
  return "[Line " + std::to_string(line_) + "] LOOP: " + type_; 
}