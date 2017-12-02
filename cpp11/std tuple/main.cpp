#include <iostream>
#include <tuple>
#include <string>

int main()
{
	// 3要素のタプルを作る
	std::tuple<int, char, std::string> t = std::make_tuple(1, 'a', "hello");

	// 0番目の要素を参照
	int& i = std::get<0>(t);
	std::cout << i << std::endl;

	// 2番目の要素を参照
	std::string& s = std::get<2>(t);
	std::cout << s << std::endl;

	return 0;
}