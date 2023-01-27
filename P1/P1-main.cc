// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 03/10/2022
// Archivo P1-main.cc: Fichero que contiene el main donde se leera el fichero de entrada y lo procesara a uno de salida segun que operacion se solicite.
// Historial de revisiones 
//   03/10/2022 - Primera versión
//   04/10/2022 - Continuación de programación
//   05/10/2022 - Revision final



// MODIFICAR FICHERO DE SALIDA PARA QUE MUESTRE LA INFORMACION DEL ALFABETO Y CADENA, ADEMAS MOSTRAR LOS SIMBOLOS QUE NO SE ESTAN UTILIZANDO
#include "alphabet.h"


int main(int argc, char* argv[]) {
  if (argc==2) {
    std::string help = argv[1];
    if (help.find("--help")!= std::string::npos) {
      std::cout << "To use the program you need to provide an input file, an output file and an opcode (input.txt output.txt 1)" << std::endl;
      std::cout << "Opcodes:\n1.String length \n2.Reverse String\n3.Prefixes of the string\n4.Suffixes of the string\n5.Substrings\n" << std::endl;
      return 0;
    }
  }
  if (argc != 4) {
    std::cout << "Unexpected parameters given" << std::endl;
    std::cout << "Expected:     input_file.txt    output_file.txt   opcode" << std::endl;
    return 0;
  }
  std::ifstream input_file;
  input_file.open(argv[1]);

  std::ofstream output_file;
  output_file.open(argv[2]);

  int opcode = std::stoi(argv[3]);

  if (input_file.good() == false) {
    std::cout << "Input file doesnt exist, try again" << std::endl;
    return 0;
  }

  if (opcode < 1 || opcode > 5) {
    std::cout << "Not implemented, (try 1-5)" << std::endl;
    return 0;
  }
  std::cout << "Opening \n input file: " << argv[1] << std::endl << " output file: " << argv[2] << std::endl << " with opcode: " << argv[3] << std::endl;

  std::string read_line;
  while (std::getline(input_file, read_line, '\n')) {
    Alphabet alphabet(read_line);
    output_file << alphabet.info() << std::endl;
    switch(opcode) {
      case 1:
        output_file << alphabet.get_string_length() << std::endl << std::endl;
      break;
      case 2:
        output_file << alphabet.get_reverse_string() << std::endl << std::endl;

      break;
      case 3:
        output_file << alphabet.get_prefix_strings() << std::endl << std::endl;
      break;
      case 4:
        output_file << alphabet.get_suffix_strings() << std::endl << std::endl;
      break;
      case 5:
        output_file << alphabet.sub_strings() << std::endl << std::endl;
      break;
    }
  }
};

