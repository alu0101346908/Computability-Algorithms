// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 8: Gramaticas en Forma Normal de Chomsky
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 23/11/2022
// Archivo p08_main.cc: Fichero main que recibe el fichero .gr que representa a una CFG, carga el fichero en la clase
// grammar, la pasa a FNC y la imprime por pantalla y por el fichero de salida
// Historial de revisiones 
//   21/11/2022 - Primera versión
//   22/11/2022 - Continuación de programación
//   23/11/2022 - Revision final

//MOD

#include <string.h>
#include "grammar.h"

int main(int argc, char* argv[]) {
  if (argc != 3 || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-h") ) {
    std::cout << "To use the program you need to provide a file that contains a CFG and an output file" << std::endl;
    return 0;
  }
  std::string input_gr_file_name = argv[1];
  std::string output_gr_file_name = argv[2];
  try {
    std::ifstream input_gr_file_ = std::ifstream(input_gr_file_name, std::fstream::in);
    std::ofstream output_gr_file_ = std::ofstream(output_gr_file_name, std::fstream::out);
    std::string input_block ((std::istreambuf_iterator<char>(input_gr_file_)), std::istreambuf_iterator<char>());
    Grammar gr(input_block);
    gr.CfgToChomsky();
    output_gr_file_ << gr.Print();
    //Automaton fa(input_fa_file);
    //fa.ConvertToGrammar(output_file).WriteOutputFile();
  } catch(const char* e){
    std::cout << e;
      std::cout << "Program terminated unsuccessfully" << std::endl;
    return -1;
  }

  std::cout << "Program terminated successfully" << std::endl;
  return 0;
} 