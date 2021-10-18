#include "calc.h"

#include <iostream>
#include <istream>
#include <iterator>
#include <string>
#include <limits>
#include <sstream>

int calc(int lhs, int rhs, char op) {
	switch (op) {
	case '+':
		return lhs + rhs;
	case '-':
		return lhs - rhs;
	case '*':
		return lhs * rhs;
	case '/':
		if (rhs == 0) {
			throw std::invalid_argument { "Division by zero" };
		}
		return lhs / rhs;
	case '%':
		if (rhs == 0) {
			throw std::invalid_argument { "Division by zero" };
		}
		return lhs % rhs;
	}

	throw std::invalid_argument { "Invalid argument" };

}

int calc(std::istream &inputStream) {

	using input = std::istream_iterator<std::string>;
	using output = std::ostream_iterator<std::string>;
	std::stringstream inputStringStream{};

	input eof{};
	input in{inputStream};
	output out{inputStringStream};

	std::copy(in,eof,out);
	std::string inputString = inputStringStream.str();

	int positionOperator = inputString.find_first_of("+-*/%");
	int firstNumber = std::stoi(inputString.substr(0, positionOperator));
	int secondNumber = std::stoi(inputString.substr(positionOperator + 1, inputString.length() - 1));
	char operatorSymbol = inputString[positionOperator];

	return calc(firstNumber, secondNumber, operatorSymbol);
}
