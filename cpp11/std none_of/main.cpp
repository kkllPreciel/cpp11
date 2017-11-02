#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 3, 1, 4 };

	std::cout << std::boolalpha;

	// �S�Ă̗v�f��3�ȏ�ł��邩
	bool result1 = std::none_of(v.begin(), v.end(), [](int x) { return x < 3; });
	std::cout << result1 << std::endl;

	// �S�Ă̗v�f��0�ȉ��ł��邩
	bool result2 = std::none_of(v.begin(), v.end(), [](int x) { return x == 0; });
	std::cout << result2 << std::endl;

	return 0;
}