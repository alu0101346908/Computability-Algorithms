// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia 
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Mario Hernández García
// Correo: alu0101346908@ull.es
// Fecha: 19/10/2022
// Archivo calculator.cc: Fichero con la implementacion de la clase Calculator.// Historial de revisiones 
// Historial de revisiones:
//   18/10/2022 - Primera versión
//   19/10/2022 - Continuación de programación
//   19/10/2022 - Revision final



#include "calculator.h"
#include "alphabet.h"


// Default constructor of the class Calculator that loads the supported operations to the available_operators set

Calculator::Calculator() {
  std::vector<std::string> operators {"+","|","^","-","!","*"};
  available_operators_.insert(operators.begin(), operators.end());
}


//  Getter of the operations_stack_ attribute of the class
std::stack<std::string>& Calculator::get_operations_stack() {

  return operations_stack_;

}

//  Getter of the available_operators_ attribute of the class
std::set<std::string> Calculator::get_operators() {
  return available_operators_;

}

// Core function of the Calculator class that receives a string that contains an operation in reversed polish notation, also receives the set of the languages currently
// loaded (not as a reference because the operations are individual).
// To parse the string containing the operations we make use of getline with the delimiter being the whitespace, if the read word contains a L, its pushed to the operations stack
// If the read word its an operator it tops and pops the stack one o two times depending on the operation, then it searches the specified languages in the set, retrieves it
// and operates giving the result language, setting its name to the next available one (L1+L2 -> L3).
// As its needed to generate the alphabet we create a new alphabet with the result language as the constructor argument, invoking then the load of the alphabet based on the language strings
// It operates making use of the overloaded operators specified in the previous assigment.
std::string Calculator::operate(std::string operations_string, std::set<Language> language_set) {
  std::istringstream operations_string_stream(operations_string);
  std::string word = "";
  std::string output_string = "";
  std::string left_operand_name;
  Language left_operand_language;
  Language right_operand_language;
  Language result_language;
  std::string right_operand_name;
  std::set<std::string> available_operators = get_operators();
  std::stack<std::string> operations_stack;
  while (std::getline(operations_string_stream, word, ' ')) {
    // std::cout << word << std::endl;
    // std::cout << operations_stack.size() << std::endl;
    // for (std::stack<std::string> dump = operations_stack; !dump.empty(); dump.pop())
    //     std::cout << dump.top() << '\n';
    // std::cout << "(" << operations_stack.size() << " elements)\n";
    if (available_operators.find(word) != available_operators.end()) {
      if(word == "!" || word == "*") {
        if(operations_stack.size() < 1) {
          std::cout << "Bad expression, insufficient operands " + std::to_string(operations_stack.size()) + " expecting at least 1" << std::endl << std::endl;
          return output_string + "Bad expression, insufficient operands " + std::to_string(operations_stack.size()) + " expecting at least 1"+"\n\n";
        }
        if(word == "*") {
          int exponent = std::stoi(operations_stack.top());
          operations_stack.pop();
          left_operand_name = operations_stack.top();
          operations_stack.pop();
          left_operand_language.set_name(left_operand_name);
          if(language_set.find(left_operand_language) != language_set.end()) left_operand_language = *language_set.find(left_operand_language);
          else {
            std::cout << "Operator not declared: " + left_operand_name + " skipping..." << std::endl << std::endl;
            return output_string + "Operator not declared: " + left_operand_name + " skipping..." + "\n\n";
          }
          result_language = (left_operand_language * exponent);
          result_language.set_name("L"+std::to_string(language_set.size()+1));


        } else {
          left_operand_name = operations_stack.top();
          operations_stack.pop();
          left_operand_language.set_name(left_operand_name);
          if(language_set.find(left_operand_language) != language_set.end()) left_operand_language = *language_set.find(left_operand_language);
          else {
            std::cout << "Operator not declared: " + left_operand_name + " skipping..." << std::endl << std::endl;
            return output_string + "Operator not declared: " + left_operand_name + " skipping..." + "\n\n";
          }
          result_language = (!left_operand_language);
          result_language.set_name("L"+std::to_string(language_set.size()+1));


        }
      } else {
        if(operations_stack.size() < 2) {
          std::cout << "Bad expression, insufficient operands " + std::to_string(operations_stack.size()) + " expecting at least 2" << std::endl << std::endl;
          return output_string + "Bad expression, insufficient operands " + std::to_string(operations_stack.size()) + " expecting at least 2"+"\n\n";
        }
        right_operand_name = operations_stack.top();
        operations_stack.pop();
        right_operand_language.set_name(right_operand_name);
        if(language_set.find(right_operand_language) != language_set.end()) right_operand_language = *language_set.find(right_operand_language);
          else {
            std::cout << "Operator not declared: " + right_operand_name + " skipping..." << std::endl << std::endl;
            return output_string + "Operator not declared: " + right_operand_name + " skipping..." + "\n\n";
        }
        left_operand_name = operations_stack.top();
        operations_stack.pop();
        left_operand_language.set_name(left_operand_name);
        if(language_set.find(left_operand_language) != language_set.end()) left_operand_language = *language_set.find(left_operand_language);
          else {
            std::cout << "Operator not declared: " + left_operand_name  + " skipping..." << std::endl << std::endl;
            return output_string + "Operator not declared: " + left_operand_name + " skipping..." + "\n\n";
          }
        if (word == "+") {
          result_language = (left_operand_language + right_operand_language);
          result_language.set_name("L"+std::to_string(language_set.size()+1));


        }
        if (word == "|") {
          result_language = (left_operand_language | right_operand_language);
          result_language.set_name("L"+std::to_string(language_set.size()+1));


        }
        if (word == "^") {
          result_language = (left_operand_language ^ right_operand_language);
          result_language.set_name("L"+std::to_string(language_set.size()+1));


        }
        if (word == "-") {
          result_language = (left_operand_language - right_operand_language);
          result_language.set_name("L"+std::to_string(language_set.size()+1));


        }
      }
      Alphabet result_language_alphabet(result_language);
      std::cout << result_language_alphabet.info() << std::endl;
      output_string = output_string + result_language_alphabet.info() + "\n";
      language_set.insert(result_language);
      operations_stack.push(result_language.get_name());
    } else {
      //std::cout << word << std::endl;
      operations_stack.push(word);
    }
  }
  if(operations_stack.size() > 1) {
    std::cout << "Bad expression, there are " + std::to_string(operations_stack.size()) + " operands, expecting 1 remaining" << std::endl << std::endl;
    return output_string + "Bad expression, there are " + std::to_string(operations_stack.size()) + " operands, expecting 1 remaining" +"\n\n";
  }
  std::cout << std::endl<< std::endl;
  return output_string;
}
