#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

bool isOdd(int x) { return x % 2 != 0; }

int main()
{
	std::vector<int> v1 = { 3, 1, 4 };
	std::vector<int> v2 = { 1, 5, 9 };
	std::vector<int> v3 = { 2, 6, 5 };
	std::vector<int> result(v1.size() + v2.size() + v3.size());

	// copy_ifの戻り値を使って、複数のコンテナにある奇数を全て繋げる
	auto out = result.begin();
	out = std::copy_if(v1.begin(), v1.end(), out, isOdd);
	out = std::copy_if(v2.begin(), v2.end(), out, isOdd);
	out = std::copy_if(v3.begin(), v3.end(), out, isOdd);

	std::copy(result.begin(), out, std::ostream_iterator<int>(std::cout, ","));

	return 0;
}