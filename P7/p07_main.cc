// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 7: Gramáticas Regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 16/11/2022
// Archivo p07_main.cc: Fichero main donde se leen el fichero de entrada .fa y el de salida .gr, el fichero .fa cargara un automata
// en la clase Automaton y este generara la gramatica correspondiente
// Historial de revisiones 
//   14/11/2022 - Primera versión
//   15/11/2022 - Continuación de programación
//   16/11/2022 - Revision final


//MOD: NO ALMACENAR LAS PRODUCCIONES DE UN TERMINAL QUE REPRESENTA UN ESTADO DE MUERTE


#include <string.h>
#include "automaton.h"
#include "grammar.h"

int main(int argc, char* argv[]) {
  if (argc != 3 || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-h") ) {
    std::cout << "To use the program you need to provide a file that contains a DFA or NFA and an output file" << std::endl;
    return 0;
  }
  std::string input_fa_file = argv[1];
  std::string output_file = argv[2];
  try {
    Automaton fa(input_fa_file);
    fa.ConvertToGrammar(output_file).WriteOutputFile();
  } catch(const char* e){
    std::cout << e;
      std::cout << "Program terminated unsuccessfully" << std::endl;
    return -1;
  }

  std::cout << "Program terminated successfully" << std::endl;
  return 0;
} 