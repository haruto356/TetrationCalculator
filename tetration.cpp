#include <iostream>
#include "tetration.hpp"

long Tetration::getArrayLen(std::array<short, MAX_DIGIT> a) {
	long i;
	for(i = 0; i < MAX_DIGIT; i++) {
		if(a.at(i) != 0) {
			break;
		}
	}
	return MAX_DIGIT - i;
}

void Tetration::printResult() {
	int flag = 1;
	long digit = 0;

	for(long i = 0; i < MAX_DIGIT; i++) {
		if(flag == 1 && result.at(i) == 0) {
			continue;
		} else {
			flag = 0;
			digit++;
			std::cout << result.at(i);
		}
	}
	std::cout << std::endl << "桁数:" << digit << std::endl;
}

void Tetration::calcMulti(std::array<short, MAX_DIGIT> a, std::array<short, MAX_DIGIT> b) {
	long aLen = getArrayLen(a);
	long bLen = getArrayLen(b);

	for(long i = MAX_DIGIT - 1; i >= MAX_DIGIT - bLen; i--) {
		for(long j = MAX_DIGIT - 1; j >= MAX_DIGIT - aLen; j--) {
			result[MAX_DIGIT - 1 - (MAX_DIGIT - j - 1) - (MAX_DIGIT - i - 1)] += a[j] * b[i];
		}
	}

	for(long i = MAX_DIGIT - 1; i >= 0; i--) {
		if(result[i] > 10) {
			result[i - 1] += result[i] / 10;
			result[i] %= 10;
		}
	}
}
