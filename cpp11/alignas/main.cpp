#include <iostream>

struct test {
	alignas(4)	int i4, i4_n;
	alignas(8)	int i8, i8_n;
	alignas(16)	int i16, i16_n;
	alignas(8) alignas(16) int i8_16, i8_16_n;
};

int distance(void* a, void* b)
{
	return reinterpret_cast<int>(a) - reinterpret_cast<int>(b);
}

int main()
{
	test t;

	std::cout <<
		"alignas(8) int i4:" << distance(&t.i4_n, &t.i4) << std::endl <<
		"alignas(8) int i8:" << distance(&t.i8_n, &t.i8) << std::endl <<
		"alignas(16) int i16:" << distance(&t.i16_n, &t.i16) << std::endl;

	std::cout <<
		"alignas(8) alignas(16) int i8_16:" <<
		distance(&t.i8_16_n, &t.i8_16) << std::endl;

	return 0;
}