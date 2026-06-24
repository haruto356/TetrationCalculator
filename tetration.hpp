#include <array>
#include <stdint.h>
#define MAX_DIGIT 100000

class Tetration {
	private:
		std::array<int_fast16_t, MAX_DIGIT> result;
		long getArrayLen(std::array<int_fast16_t, MAX_DIGIT> a);
		int decrement(std::array<int_fast16_t, MAX_DIGIT>& a);
	public:
		Tetration() {
			result.fill(0);
		}
		void printResult();
		void calcMulti(std::array<int_fast16_t, MAX_DIGIT> a, std::array<int_fast16_t, MAX_DIGIT> b);
		void calcExp(std::array<int_fast16_t, MAX_DIGIT> a, std::array<int_fast16_t, MAX_DIGIT> b);
		void calcTetr(std::array<int_fast16_t, MAX_DIGIT> a, std::array<int_fast16_t, MAX_DIGIT> b);
};
