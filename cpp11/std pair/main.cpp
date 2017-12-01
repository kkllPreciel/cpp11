#include <iostream>
#include <utility>
#include <string>

int main()
{
	// pairオブジェクトの構築
	std::pair<int, std::string> p = std::make_pair(1, "hello");

	// 要素の参照
	std::cout << p.first << std::endl;
	std::cout << p.second << std::endl;

	return 0;
}