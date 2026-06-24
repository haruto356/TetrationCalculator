#include <iostream>
#include "timer.hpp"
#include "tetration.hpp"

void initArray(std::array<short, MAX_DIGIT>& a, long num) {
	a.fill(0);

	long i = 10;
	long index = MAX_DIGIT - 1;

	do {
		a[index] = (num % i) / (i / 10);
		i *= 10;
		index--;
	} while(i / 10 <= num);
}

int main(void) {
	long a, b;
	std::array<short, MAX_DIGIT> arrayA, arrayB;
	Timer timer = Timer();
	Tetration tetration = Tetration();

	do {
		std::cout << "2つの値を入力してください" << std::endl;
		std::cin >> a >> b;
		if(a == 0 || b == 0) {
			std::cout << "1以上の整数を指定してください" << std::endl;
		}
	} while(a == 0 || b == 0);

	initArray(arrayA, a);
	initArray(arrayB, b);

	timer.startTimer();
	tetration.calcMulti(arrayA, arrayB);
	timer.endTimer();
	tetration.printResult();
	return 0;
}
