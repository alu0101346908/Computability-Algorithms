// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 6: Simulación de autómatas finitos
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 9/11/2022
// Archivo state.h: Fichero con la definicion de la clase State.
// Historial de revisiones 
//   7/11/2022 - Primera versión
//   8/11/2022 - Continuación de programación
//   9/11/2022 - Revision final

#ifndef STATE_H_
#define STATE_H_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>

/**
 * @brief Clase Estado que representa un estado de un automata finito, contiene id, nombre, indicador si es final o inicial y sus posibles transiciones
 * 
 */
class State {
  public:

    State(uint, std::string, bool, bool);
    void add_transition(std::pair<std::string, uint>);
    uint get_id() const;
    bool is_final_state() const;
    std::vector<std::pair<std::string,uint>> transition_with_symbol(std::string, int) const;
    bool operator<(const State& state) const;
  private:

    uint id_;
    std::string name_;

    bool is_starting_state_ = false;
    bool is_final_state_ = false;

    std::vector<std::pair<std::string, uint>> transitions_;
};

#endif