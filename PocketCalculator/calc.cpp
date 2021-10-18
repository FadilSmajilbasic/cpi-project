#include "calc.h"
#include <istream>
#include <string>
#include <limits>

int calc(int lhs, int rhs, char op){
	switch (op){
	  case '+':
		  return lhs + rhs;
	  case '-':
		  return lhs - rhs;
	  case '*':
		  return lhs * rhs;
	  case '/':
		  if(rhs == 0){
			  throw std::invalid_argument{"Division by zero"};
		  }
		  return lhs / rhs;
	  case '%':
		  if(rhs == 0){
			  throw std::invalid_argument{"Division by zero"};
		    }
		  return lhs % rhs;
	}

	throw std::invalid_argument{"Invalid argument"};

}

int calc(std::istream & in){
	std::string input{};
	std::getline(in, input);
	int positionOperator = input.find_first_of("+-*/%");
	std::string firstNumber = input.substr(0, positionOperator);
	std::string secondNumber = input.substr(positionOperator+1, input.length()-1);
	char operatorSymbol = input.at(positionOperator);
	int numberOne = std::stoi(firstNumber);
	int numberTwo = std::stoi(secondNumber);
	return calc(numberOne, numberTwo, operatorSymbol);
}
