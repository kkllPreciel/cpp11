#include <iostream>
#include <tuple>
#include <string>

int main()
{
	// 3�v�f�̃^�v�������
	std::tuple<int, char, std::string> t = std::make_tuple(1, 'a', "hello");

	// 0�Ԗڂ̗v�f���Q��
	int& i = std::get<0>(t);
	std::cout << i << std::endl;

	// 2�Ԗڂ̗v�f���Q��
	std::string& s = std::get<2>(t);
	std::cout << s << std::endl;

	return 0;
}