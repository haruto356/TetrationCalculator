#include <array>
#define MAX_DIGIT 10000

class Tetration {
	private:
		std::array<short, MAX_DIGIT> result;
	public:
		void calcMulti(std::array<short, MAX_DIGIT> a, std::array<short, MAX_DIGIT> b);
};
