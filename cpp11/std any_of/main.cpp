#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 3, 1, 4 };

	std::cout << std::boolalpha;

	// 5以上の要素が存在するかどうか
	bool result1 = std::any_of(v.begin(), v.end(), [](int x) { return x >= 5; });
	std::cout << result1 << std::endl;

	// 1の要素が存在するかどうか
	bool result2 = std::any_of(v.begin(), v.end(), [](int x) { return x == 1; });
	std::cout << result2 << std::endl;

	return 0;
}