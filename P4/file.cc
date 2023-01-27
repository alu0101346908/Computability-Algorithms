// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 26/10/2022
// Archivo file.cc: Fichero con la implementacion de la clase File.
// Historial de revisiones 
//   25/10/2022 - Primera versión
//   25/10/2022 - Continuación de programación
//   26/10/2022 - Revision final



#include "file.h"

//El constructor recibe el nombre del fichero y el stream del fichero de entrada. Luego va leyendo linea por linea y evaluando todas las expresiones especificadas en la practica
//variables, loops, main, comments. Los matches se guardan en el vector que corresponda salvo en el caso de variable que hay que filtrar si se trata de int o double.
//Se mantiene un contador que va aumentando por linea leida para poder guardar la posicion de cada elemento en el fichero

File::File(const std::string& input_file_name, std::ifstream& input_file) {
  file_name_ = input_file_name;
  while(!input_file.eof()) {
    std::string read_line = "";
    std::getline(input_file, read_line);
    std::smatch matches;
    std::regex variable_expression("\\S*(int|double)\\s(\\d|[A-Za-z])*(\\s=\\s(\\d|[A-Za-z]);|;)$");
    if (std::regex_search(read_line, matches, variable_expression)) {
      std::string type = matches[0];
      std::string info = parse_variable(type);
      vars_.push_back(Variable(info, line_counter_));
    }
    std::regex loop_expression("\\s*(for|while)\\s*[(]\\s*");
    if (std::regex_search(read_line, matches, loop_expression)) {
      std::string type = matches[1];
      loops_.push_back(Loop(type, line_counter_));
    }
    std::regex is_main__expression("^int main");
    if (std::regex_search(read_line, matches, is_main__expression)) {
      std::string type = matches[0];
      is_main_ = true;
    }
    std::regex comment_expresion("(((^|\\s)/\\*)|((^|\\s)\\*\\s.*)|(\\*/$))|((^|\\s)//.*)");
    if (std::regex_search(read_line, matches, comment_expresion)) {
      if (line_counter_ == 1) {
        is_description_ = true;
      }
      std::string type = matches[0];
      comments_.push_back(Comment(type, line_counter_));
    }
    line_counter_++;
  }
}



// Recibe el match que corresponde a una variable y la devuelve formateada al estilo solicitado
std::string File::parse_variable(std::string variable_string) {
  std::smatch matches;
  std::string aux;
  if (std::regex_search(variable_string, matches, std::regex("^int*")))
    aux = std::regex_replace(variable_string, std::regex("^int*"), "INT:");
  else 
    aux = std::regex_replace(variable_string, std::regex("^double*"), "DOUBLE:");
  return std::regex_replace(aux, std::regex(";"), "");
}



// Funcion que devuelve una string que contiene toda la informacion almacenada en la clase File, en el formato estructurado solicitado.
// Tiene la logica para comprobar si existe un comentario en bloque de descripcion del codigo para así mostrarlo.
std::string File::print() const {
  std::string program_string = "PROGRAM:\n" + file_name_ + "\n";

  std::string description_string = "DESCRIPTION:\n";
  int end_description = 0;
  if (is_description_ == true) {
    for (const Comment& description_part : comments_) {
      description_string += description_part.get_comment() + "\n";
      if (description_part.get_comment() == "*/") {
        end_description = description_part.get_line();
        break;
      }
    }
  }
  std::string variables_string = "VARIABLES:\n";
  for (const Variable& vars : vars_)
    variables_string += vars.print() + "\n";

  std::string statements_string = "STATEMENTS:\n";
  for (const Loop& loop : loops_)
    statements_string += loop.print() + "\n";

  std::string main_string = "MAIN:\n";
  if (is_main_ == true)
    main_string += "True\n";
  else 
    main_string += "False\n";

  std::string comments_string = "COMMENTS: \n";
  std::string comments_string2 = "";
  if (is_description_ == true) {
    comments_string += "[Line 1 - " + std::to_string(end_description) + "] DESCRIPTION\n";
    for (const Comment& comment : comments_) {
      if(comment.get_line() > end_description) {
        comments_string += comment.print() + "\n";
      }
    }
  }
  else {
    for (const Comment& comment : comments_) {
      comments_string2 += comment.print() + "\n";
    }
  }
  return program_string + "\n" + description_string + "\n" + variables_string + "\n" + statements_string + "\n" + main_string + "\n" + comments_string + "\n" + comments_string2;
}


// Operador << sobrecargado para que se invoque al print de File cuando se quiera guardar la informacion de la clase en un fichero
std::ostream& operator<<(std::ostream& os, const File& f) {
  return os << f.print();
}