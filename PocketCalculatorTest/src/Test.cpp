#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "calc.h"
#include "sevensegment.h"
#include "pocketcalculator.h"
#include <limits>
#include <ostream>
#include <sstream>

void test_one_plus_one() {
	auto result = calc(1, 1, '+');
	ASSERT_EQUAL(2, result);
}
void test_two_times_two() {
	auto result = calc(2, 2, '*');
	ASSERT_EQUAL(4, result);
}
void thest_three_divided_two() {
	auto result = calc(3, 2, '/');
	ASSERT_EQUAL(1, result);
}
void test_five_divided_zero() {
	ASSERT_THROWS(calc(5, 0, '/'),std::exception);
}

void test_modulo_zero() {
	ASSERT_THROWS(calc(3, 0, '%'),std::exception);
}

void test_modulo(){
	auto result = calc(6, 3, '%');
	ASSERT_EQUAL(0, result);
	result = calc(7, 3, '%');
	ASSERT_EQUAL(1, result);
}

void testPrintLargeDigitZero() {
	std::ostringstream output{};
	printLargeDigit(0, output);
	ASSERT_EQUAL(	" - \n"
					"| |\n"
					"   \n"
					"| |\n"
					" - \n", output.str());
}

void testFullOperation() {

	std::ostringstream output{};
	std::stringstream input{};
	input << "2 + 3";

	pocketcalculator(input, output);

	ASSERT_EQUAL(	" - \n"
					"|  \n"
					" - \n"
					"  |\n"
					" - \n", output.str());
}

void testError() {
	std::ostringstream output{};
	std::stringstream input{};
	input << "18/0";

	pocketcalculator(input, output);
	ASSERT_EQUAL(	" -             \n"
			 "|              \n"
			 " -  -  -  -  - \n"
			 "|  |  |  | ||  \n"
			 " -        -    \n", output.str());
}

void test_wrong_operator(){

	ASSERT_THROWS(calc(6, 3, '&'), std::exception);
}
bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(test_one_plus_one));
	s.push_back(CUTE(test_two_times_two));
	s.push_back(CUTE(thest_three_divided_two));
	s.push_back(CUTE(test_five_divided_zero));
	s.push_back(CUTE(test_wrong_operator));
	s.push_back(CUTE(test_modulo));
	s.push_back(CUTE(testPrintLargeDigitZero));
	s.push_back(CUTE(testFullOperation));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}
int main(int argc, char const *argv[]) {
	return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

