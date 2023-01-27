// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 26/10/2022
// Archivo loop.h: Fichero con la definición de la clase Loop.
// Historial de revisiones 
//   25/10/2022 - Primera versión
//   25/10/2022 - Continuación de programación
//   26/10/2022 - Revision final

#ifndef LOOP_H_
#define LOOP_H_

#include <iostream>
#include <string>

class Loop {
  public:
    Loop(std::string type, size_t line);
    size_t get_line() const;
    std::string get_type() const;
    std::string print() const;
  private: 
    std::string type_;
    size_t line_;
};

#endif