#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> v = { 3, 1, 4 };

	std::cout << std::boolalpha;

	// �S�Ă̗v�f��5��菬������
	bool result1 = std::all_of(v.begin(), v.end(), [](int x) { return x < 5; });
	std::cout << result1 << std::endl;

	// �S�Ă̗v�f��1�ł��邩
	bool result2 = std::all_of(v.begin(), v.end(), [](int x) { return x == 1; });
	std::cout << result2 << std::endl;

	return 0;
}