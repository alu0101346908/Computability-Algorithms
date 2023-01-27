// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 26/10/2022
// Archivo p04_main.cc: Fichero que contiene el main donde se recibe por consola dos argumentos, uno es un fichero de entrada que debe representar un codigo en c++ 
//                      y el otro el nombre del fichero de salida. El main verifica los parametros, crea los objetos stream y crea un objecto File con su constructor. 
//                      Luego con el operador sobrecargado escribe todos los datos de la clase en el fichero de salida.
// Historial de revisiones 
//   25/10/2022 - Primera versión
//   25/10/2022 - Continuación de programación
//   26/10/2022 - Revision final

#include "file.h"

#include <string.h>
#include <fstream>


int main(int argc, char* argv[]) {
  if (argc != 3 || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-h") ) {
    std::cout << "To use the program you need to provide an input file that  contains c++ code following using Google's programming style (input.cc) and an outputfile" << std::endl;
    return 0;
  }
  std::string input_file_string = argv[1];
  std::string output_file_string = argv[2];

  std::ifstream in_file(input_file_string, std::fstream::in);
  std::ofstream out_file(output_file_string, std::fstream::out);
  if (!in_file.good() || !out_file.good()) {
    std::cout << "Input file doesnt exist, try again" << std::endl;
    return 0;
  }
  // El constructor recibe el nombre del fichero y el stream del fichero
  File file(input_file_string, in_file);
  // Con el operador sobrecargado, internamente se invoca al print de la clase
  out_file << file;
  in_file.close();
  out_file.close();

  return 0;
} 