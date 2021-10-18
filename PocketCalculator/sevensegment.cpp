#include "sevensegment.h"
#include <ostream>
#include <array>
#include <string>
#include <algorithm>
#include <iterator>
#include <string>

const std::array<std::array<std::string, 5>, 10> numbers { { { " - ", "| |", "   ", "| |", " - " }, 	// 0
		{ "   ", "  |", "   ", "  |", "   " }, 	// 1
		{ " - ", "  |", " - ", "|  ", " - " },	// 2
		{ " - ", "  |", " - ", "  |", " - " },	// 3
		{ "   ", "| |", " - ", "  |", "   " },	// 4
		{ " - ", "|  ", " - ", "  |", " - " },	// 5
		{ " - ", "|  ", " - ", "| |", " - " },	// 6
		{ " - ", "  |", "   ", "  |", "   " },	// 7
		{ " - ", "| |", " - ", "| |", " - " },	// 8
		{ " - ", "| |", " - ", "  |", " - " }	// 9
} };

const std::array<std::string,5> minus {"   ","   "," - ","   ","   "};

void printLargeDigit(int i, std::ostream &out) {
	std::for_each(std::cbegin(numbers.at(i)), std::cend(numbers.at(i)), [&out](auto x) {
		out << x << '\n';
	});
}

void printLargeNumber(int i, std::ostream &out) {

	auto stringNumber = std::to_string(i);
	if (i < 0)
		stringNumber = stringNumber.erase(0, 1);

	for (int j = 0; j < 5; j++) {
		if (i < 0) {
				out << minus[j];
		}
		for (char const &character : stringNumber) {
			const int intNum = ((int) character) - 48;
			out << numbers[intNum][j];
		}
		out << "\n";
	}

}

void printLargeError(std::ostream &out) {
	out 	<< " -             \n"
			<< "|              \n"
			<< " -  -  -  -  - \n"
			<< "|  |  |  | ||  \n"
			<< " -        -    \n";
}

