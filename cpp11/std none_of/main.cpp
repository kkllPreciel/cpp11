#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 3, 1, 4 };

	std::cout << std::boolalpha;

	// 全ての要素が3以上であるか
	bool result1 = std::none_of(v.begin(), v.end(), [](int x) { return x < 3; });
	std::cout << result1 << std::endl;

	// 全ての要素が0以下であるか
	bool result2 = std::none_of(v.begin(), v.end(), [](int x) { return x == 0; });
	std::cout << result2 << std::endl;

	return 0;
}