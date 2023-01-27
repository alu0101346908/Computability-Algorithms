// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 6: Simulación de autómatas finitos
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 9/11/2022
// Archivo p06_main.cc: Fichero main donde se leeran dos ficheros pasados por argumentos, el primero representando un DFA o NFA y el segundo un fichero de
//                      strings que se probaran frente al DFA/NFA
// Historial de revisiones 
//   7/11/2022 - Primera versión
//   8/11/2022 - Continuación de programación
//   9/11/2022 - Revision final

//  MOD: NFA (a+(ab|(bc)*)b+) A FICHERO 
#include <string.h>
#include "automaton.h"

int main(int argc, char* argv[]) {
  if (argc != 4 || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-h") ) {
    std::cout << "To use the program you need to provide a file that contains a DFA or NFA specification and a file with strings to be tested against the NFA or DFA, also an output file" << std::endl;
    return 0;
  }
  std::string input_fa_file = argv[1];
  std::string input_strings_file = argv[2];
  std::string output_file = argv[3];
  // Hay throws implementados que se deben capturar
  try {
    Automaton fa(input_fa_file, input_strings_file, output_file);
    fa.start();
  } catch(const char* e){
    std::cout << e;
      std::cout << "Program terminated unsuccessfully" << std::endl;
    return -1;
  }

  std::cout << "Program terminated successfully" << std::endl;
  return 0;
} 