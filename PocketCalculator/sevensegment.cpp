#include "sevensegment.h"
#include <ostream>
#include <array>
#include <string>
#include <algorithm>
#include <iterator>

const std::array<std::array<std::string, 5>, 10> numbers { {
	{" - ","| |","   ","| |"," - "},{"   ","  |","   ","  |","   "},
	{" - ","  |"," - ","|  "," - "},{" - ","  |"," - ","  |"," - "},
	{"   ","| |"," - ","  |","   "},{" - ","|  "," - ","  |"," - "},
	{" - ","|  "," - ","| |"," - "},{" - ","  |"," - ","  |","   "},
	{" - ","| |"," - ","| |"," - "},{" - ","| |"," - ","  |"," - "}
} };

void printLargeDigit(int i, std::ostream &out){
	std::for_each(std::cbegin(numbers.at(i)), std::cend(numbers.at(i)), [&out](auto x){out << x << '\n';});
}

void printLargeNumber(int i, std::ostream &out){

}

void printLargeError(std::ostream &out){
	out << " -             \n" << "|              \n" << " -  -  -  -  - \n" << "|  |  |  | ||  \n" << " -        -    \n" << "Try again!";
}
