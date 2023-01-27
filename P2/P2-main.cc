// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 12/10/2022
// Archivo P2-main.cc: Fichero que contiene el main donde se leera los dos ficheros de entrada y lo procesara a uno de salida segun que operacion se solicite.
// Historial de revisiones 
//   12/10/2022 - Primera versión
//   12/10/2022 - Continuación de programación
//   13/10/2022 - Revision final


#include "alphabet.h"


int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::string help = argv[1];
    if (help.find("--help")!= std::string::npos) {
      std::cout << "To use the program you need to provide an input file a second input file, an output file and an opcode (input.txt input2.txt output.txt 1)" << std::endl;
      std::cout << "Opcodes:\n1.Concatenate\n2.Union\n3.Intersection\n4.Difference\n5.Inverse\n6.Power\n" << std::endl;
      return 0;
    }
  }
  if (argc != 5) {
    std::cout << "Unexpected parameters given" << std::endl;
    std::cout << "Expected:     input_file.txt    output_file.txt   opcode" << std::endl;
    return 0;
  }
  std::ifstream input_file;
  input_file.open(argv[1]);

  std::ifstream input_file_2;
  input_file_2.open(argv[2]);

  std::ofstream output_file;
  output_file.open(argv[3]);

  int opcode = std::stoi(argv[4]);

  if (input_file.good() == false || input_file_2.good() == false ) {
    std::cout << "Input file doesnt exist, try again" << std::endl;
    return 0;
  }

  if (opcode < 1 || opcode > 6) {
    std::cout << "Not implemented, (try 1-6)" << std::endl;
    return 0;
  }
  std::cout << "Opening \n input file 1: " << argv[1] << std::endl << " input file 2: " << argv[2] << std::endl << " output file: " << argv[3] << std::endl << " with opcode: " << argv[4] << std::endl;

  std::string read_line;
  std::string read_line_2;
  int exponent;
  if (opcode == 6) {
    std::cout << "Enter the exponent: (WARNING, USING EXPONENT > 4 THE PROGRAM WILL TAKE SOME TIME TO OUTPUT (concatenating and filtering dup)): ";
    std::cin >> exponent;

  }
  while (std::getline(input_file, read_line, '\n')) {
    Alphabet alphabet(read_line);
    output_file << "INP1: " << alphabet.info() << std::endl;
    switch(opcode) {
      case 1:
        if(std::getline(input_file_2, read_line_2, '\n')) {
          Alphabet alphabet_2(read_line_2);
          output_file << "INP2: "<< alphabet_2.info() << std::endl;
          Language result_language = (alphabet.get_language() * alphabet_2.get_language());
          Alphabet alphabet_3(result_language);
          output_file << "OUT: "<< alphabet_3.info() << std::endl << std::endl;
        }

      break;
      case 2:
        if(std::getline(input_file_2, read_line_2, '\n')) {
          Alphabet alphabet_2(read_line_2);
          output_file << "INP2: "<< alphabet_2.info() << std::endl;
          Language result_language = (alphabet.get_language() + alphabet_2.get_language());
          Alphabet alphabet_3(result_language);
          output_file << "OUT: "<< alphabet_3.info() << std::endl << std::endl;
        }
      break;
      case 3:
        if(std::getline(input_file_2, read_line_2, '\n')) {
          Alphabet alphabet_2(read_line_2);
          output_file << "INP2: "<< alphabet_2.info() << std::endl;
          Language result_language = (alphabet.get_language() / alphabet_2.get_language());
          Alphabet alphabet_3(result_language);
          output_file << "OUT: "<< alphabet_3.info() << std::endl << std::endl;
        }
      break;
      case 4:
        if(std::getline(input_file_2, read_line_2, '\n')) {
          Alphabet alphabet_2(read_line_2);
          output_file << "INP2: "<< alphabet_2.info() << std::endl;
          Language result_language = (alphabet.get_language() - alphabet_2.get_language());
          Alphabet alphabet_3(result_language);
          output_file << "OUT: "<< alphabet_3.info() << std::endl << std::endl;
        }
      break;
      case 5:
        if(true) {
          Language result_language = (~alphabet.get_language());
          Alphabet alphabet_2(result_language);
          output_file << "OUT: "<< alphabet_2.info() << std::endl << std::endl;
        }

      break;
      case 6:
        if(true) {
          Language result_language = (alphabet.get_language()^exponent);
          Alphabet alphabet_2(result_language);
          output_file << "OUT: "<< alphabet_2.info() << std::endl << std::endl;
        }
      break;
    }
  }
  input_file.close();
  input_file_2.close();
  output_file.close();
  std::cout << "Program completed successfully" << std::endl;
  return 0;
};

