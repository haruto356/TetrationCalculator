#include <iostream>
#include "tetration.hpp"

long Tetration::getArrayLen(std::array<int_fast16_t, MAX_DIGIT> a) {
	long i;
	for(i = 0; i < MAX_DIGIT; i++) {
		if(a.at(i) != 0) {
			break;
		}
	}
	return MAX_DIGIT - i;
}

int Tetration::decrement(std::array<int_fast16_t, MAX_DIGIT>& a) {
	int flag = 1;
	a[MAX_DIGIT - 1]--;

	for(long i = MAX_DIGIT - 1; i > 0; i--) {
		if(a[i] == -1) {
			a[i] = 9;
			a[i - 1]--;
		}
	}
	for(long i = MAX_DIGIT - 1; i >= 0; i--) {
		if(a[i] != 0) {
			flag = 0;
			break;
		}
	}
	return flag;
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

void Tetration::calcMulti(std::array<int_fast16_t, MAX_DIGIT> a, std::array<int_fast16_t, MAX_DIGIT> b) {
	result.fill(0);

	long aLen = getArrayLen(a);
	long bLen = getArrayLen(b);

	if(aLen + 1 > MAX_DIGIT || bLen + 1 > MAX_DIGIT) {
		std::cout << "桁数が足りません" << std::endl;
		exit(1);
	}

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

void Tetration::calcExp(std::array<int_fast16_t, MAX_DIGIT> a, std::array<int_fast16_t, MAX_DIGIT> b) {
	calcMulti(a, a);
	decrement(b);
	int flag = decrement(b);
	while(true) {
		if(flag == 1) break;
		calcMulti(result, a);
		flag = decrement(b);
	}
}

void Tetration::calcTetr(std::array<int_fast16_t, MAX_DIGIT> a, std::array<int_fast16_t, MAX_DIGIT> b) {
	calcExp(a, a);
	decrement(b);
	int flag = decrement(b);
	while(true) {
		if(flag == 1) break;
		calcExp(a, result);
		flag = decrement(b);
	}
}
