#include "Calculator.h"

#include <iostream>
#include <ostream>
#include <limits>

int calc(int a, int b, char operation) {
	switch (operation) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '%':
		return a % b;
	case '/':
		if (b != 0) {
			return a / b;
		}
		/* no break */
	default:
		return INT32_MAX;
	}
}

