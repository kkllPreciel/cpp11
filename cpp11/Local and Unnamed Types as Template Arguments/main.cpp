#include <iostream>

template <class T>
int to_int(T x) { return static_cast<int>(x); }

int main()
{
	enum { E1, E2 };

	int value = to_int(E2);
	std::cout << value << std::endl;

	int value2 = to_int<decltype(E2)>(E2);
	std::cout << value2 << std::endl;

	return 0;
}