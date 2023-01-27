// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 26/10/2022
// Archivo comment.h: Fichero con la implementacion de la clase Comment.
// Historial de revisiones 
//   25/10/2022 - Primera versión
//   25/10/2022 - Continuación de programación
//   26/10/2022 - Revision final


#include "comment.h"

// Constructor que almacena el comentario y la linea y si es un comentario en la linea 1 se trata de una descripcion
Comment::Comment(std::string comment, size_t line) {
  line_ = line;
  comment_ = comment;
  if (line_ == 1)
    is_description = true;
}



size_t Comment::get_line() const {
  return line_;
}



std::string Comment::get_comment() const {
  return comment_;
}



// Devuelve la informacion almacenada en la clase formateada correctamente en una string
std::string Comment::print() const {
  return "[Line " + std::to_string(line_) + (length_ ? "-" + std::to_string(line_ + length_) : "") + "] " + comment_;
}