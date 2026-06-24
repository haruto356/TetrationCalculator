#include <iostream>
#include "timer.hpp"
#include "tetration.hpp"

void printArray(std::array<short, MAX_DIGIT> a) {
	int flag = 1;

	for(int i = 0; i < MAX_DIGIT; i++) {
		if(flag == 1 && a.at(i) == 0) {
			continue;
		} else {
			flag = 0;
			std::cout << a.at(i);
		}
	}
	std::cout << std::endl;
}

void initArray(std::array<short, MAX_DIGIT>& a, int num) {
	int i = 10;
	int index = MAX_DIGIT - 1;

	do {
		a[index] = (num % i) / (i / 10);
		i *= 10;
		index--;
	} while(i / 10 < num);
}

int main(void) {
	int a, b;
	std::array<short, MAX_DIGIT> arrayA, arrayB;
	Timer timer = Timer();

	arrayA.fill(0);
	arrayB.fill(0);

	do {
		std::cout << "2つの値を入力してください" << std::endl;
		std::cin >> a >> b;
		if(a == 0 || b == 0) {
			std::cout << "1以上の整数を指定してください" << std::endl;
		}
	} while(a == 0 || b == 0);

	initArray(arrayA, a);
	initArray(arrayB, b);

	printArray(arrayA);
	printArray(arrayB);

	timer.startTimer();

	timer.endTimer();
	return 0;
}
