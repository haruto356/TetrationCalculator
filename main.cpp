#include <iostream>
#include "timer.hpp"

int main(void) {
	int a, b;
	Timer timer = Timer();

	std::cout << "2つの値を入力してください" << std::endl;
	std::cin >> a >> b;

	timer.startTimer();

	std::cout << a * b << std::endl;

	timer.endTimer();
	return 0;
}
