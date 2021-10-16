#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "calc.h"
#include <limits>

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
	auto result = calc(5, 0, '/');
	ASSERT_EQUAL(INT32_MAX, result);
}

void test_modulo(){
	auto result = calc(6, 3, '%');
	ASSERT_EQUAL(0, result);
	result = calc(7, 3, '%');
	ASSERT_EQUAL(1, result);
}

void test_wrong_operator(){
	auto result = calc(6, 3, '&');
	ASSERT_EQUAL(0, result);
}
bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(test_one_plus_one));
	s.push_back(CUTE(test_two_times_two));
	s.push_back(CUTE(thest_three_divided_two));
	s.push_back(CUTE(test_five_divided_zero));
	s.push_back(CUTE(test_wrong_operator));
	s.push_back(CUTE(test_modulo));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}
int main(int argc, char const *argv[]) {
	return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

