// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 19/10/2022
// Archivo P3-main.cc: Fichero que contiene el main donde se leera un ficheros de entrada y lo procesara mostrando por pantalla los resultados o un fichero de salida (opcional).
// Historial de revisiones 
//   18/10/2022 - Primera versión
//   19/10/2022 - Continuación de programación
//   19/10/2022 - Revision final

//MOD AÑADIR EVALUACION DE EXPRESIONES POR CONSOLA SEGUN LOS LENGUAJES CARGADOS POR FICHERO

#include "alphabet.h"
#include "calculator.h"

int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::string help = argv[1];
    if (help.find("--help")!= std::string::npos) {
      std::cout << "To use the program you need to provide an input file (input.txt) and optionally an outputfile" << std::endl;
      std::cout << "The input file must have the following format:" << std::endl;
      std::cout << "\t Lx = {0, 1....}" << std::endl;
      std::cout << "\t Reverse polish notation for operations" << std::endl;
      std::cout << "\t     Lx Ly |........" << std::endl;
      return 0;
    }
  }
  if (argc > 4) {
    std::cout << "Unexpected parameters given" << std::endl;
    std::cout << "Expected:  input_file.txt" << std::endl;
    return 0;
  }
  std::ifstream input_file;
  input_file.open(argv[1]);
  std::ofstream output_file;
  if(argc == 3) {
    std::string checker = argv[2];
    if(checker.find("--manual") == std::string::npos) {
      output_file.open(argv[3]);
    }
  }

  if (input_file.good() == false) {
    std::cout << "Input file doesnt exist, try again" << std::endl;
    return 0;
  }

  std::cout << "Opening \n input file: " << argv[1] << std::endl << std::endl;
  
  std::set<Language> language_set;
  std::string read_line;
  Calculator calculator;
  int counter = 1;
  while (std::getline(input_file, read_line, '\n')) {
    std::string word = "";
    std::istringstream string_stream(read_line);
    std::string dummy = "";
    std::vector<std::string> splitted_string;
    if (read_line.find("=") != std::string::npos) {
      while (std::getline(string_stream, word, ' ')) {         //Gets rid of the spaces
        dummy = dummy + word.c_str();
      }
      Language new_language(dummy);
      language_set.insert(new_language);
    } 
    else {
      std::cout << "Operation " << counter  <<" (" << read_line <<"):"<< std::endl;
      if(output_file.is_open()) {
        output_file << "Operation " << counter  <<" (" << read_line <<"):"<< std::endl << calculator.operate(read_line,language_set) << std::endl;
      }
      counter++;
    }
  }
  // for(std::set<Language>::iterator it = language_set.begin(); it != language_set.end(); it++) {
  //   output_file << it->info() << std::endl;
  // }
  if(argc == 4 || argc == 3) {
    std::string op = argv[2];
    std::string op2 = "";
    if(argc==4) {
      op2 = argv[3];
    }
    if (op.find("--manual") != std::string::npos || op2.find("--manual") != std::string::npos) {
      std::string input = "";
      while(input != "x") {
        std::cout << "Enter the operation (x to exit)" << std::endl;
        std::getline(std::cin,input);
        if(input != "x") {
          std::cout << std::endl << std::endl;
          counter++;
          std::cout << "Operation " << counter  <<" (" << input <<"):"<< std::endl;
          if(output_file.is_open()){
            output_file << "Operation " << counter  <<" (" << input <<"):"<< std::endl << calculator.operate(input,language_set) << std::endl;
          }
          counter++;
        }
      }
    }
  }
  input_file.close();
  output_file.close();
  std::cout << "Program completed successfully" << std::endl;
  return 0;
};

