#include <array>
#define MAX_DIGIT 100000

class Tetration {
	private:
		std::array<short, MAX_DIGIT> result;
		long getArrayLen(std::array<short, MAX_DIGIT> a);
		int decrement(std::array<short, MAX_DIGIT>& a);
	public:
		Tetration() {
			result.fill(0);
		}
		void printResult();
		void calcMulti(std::array<short, MAX_DIGIT> a, std::array<short, MAX_DIGIT> b);
		void calcExp(std::array<short, MAX_DIGIT> a, std::array<short, MAX_DIGIT> b);
		void calcTetr(std::array<short, MAX_DIGIT> a, std::array<short, MAX_DIGIT> b);
};
