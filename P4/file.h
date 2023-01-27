// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 26/10/2022
// Archivo file.h: Fichero con la definición de la clase File.
// Historial de revisiones 
//   25/10/2022 - Primera versión
//   25/10/2022 - Continuación de programación
//   26/10/2022 - Revision final


#ifndef FILE_H_
#define FILE_H_

#include "variable.h"
#include "comment.h"
#include "loop.h"

#include <vector>
#include <algorithm>
#include <fstream>

#include <regex>


// Clase que representa el archivo de entrada, sus variables almacenan toda la informacion leida en el constructor y filtrada con los regex
class File {

  public:
    File(const std::string& input_file_name, std::ifstream& input_file);
    std::string parse_variable(std::string str);
    std::string print() const;
    friend std::ostream& operator<<(std::ostream& os, const File& f);

  private:
    bool is_main_ = false;
    bool is_description_ = false;
    int line_counter_ = 1;
    std::string file_name_;
    std::vector<Comment> comments_;
    std::vector<Comment> description_;
    std::vector<Loop> loops_;
    std::vector<Variable> vars_;
};

#endif