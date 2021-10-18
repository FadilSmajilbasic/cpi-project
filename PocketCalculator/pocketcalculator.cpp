#include "pocketcalculator.h"
#include "sevensegment.h"
#include "calc.h"

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

void pocketcalculator(std::istream &in, std::ostream &out){
	std::string input;
	while(std::getline(in, input)){
		try {
			std::istringstream userInput{input};
			int result = calc(userInput);
			std::string resultString = std::to_string(result);
			printLargeNumber(result, out);

		} catch (...){
			printLargeError(out);
		}
	}
}
