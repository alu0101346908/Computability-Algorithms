// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 19/10/2022
// Archivo calculator.h: Fichero con la definición de la clase Calculator.
// Historial de revisiones:
//   18/10/2022 - Primera versión
//   19/10/2022 - Continuación de programación
//   19/10/2022 - Revision final
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stack>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "language.h"
#include <sstream>
#include <set>

class Calculator {
  public:
    Calculator();
    std::stack<std::string>& get_operations_stack();
    std::set<std::string> get_operators();
    std::string operate(std::string, std::set<Language>);
  private:
    std::stack<std::string> operations_stack_;
    std::set<std::string> available_operators_;
};

#endif