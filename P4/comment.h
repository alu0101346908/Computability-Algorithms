// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 26/10/2022
// Archivo comment.h: Fichero con la definición de la clase Comment.
// Historial de revisiones 
//   25/10/2022 - Primera versión
//   25/10/2022 - Continuación de programación
//   26/10/2022 - Revision final

#ifndef COMMENT_H_
#define COMMENT_H_

#include <string>
#include <iostream>

class Comment {

  public:
    Comment(std::string comment, size_t line);
    size_t get_line() const;
    std::string get_comment() const;
    std::string print() const;

  private:
    bool is_description = false;
    std::string comment_;
    size_t line_;
    size_t length_ = 0;
};

#endif