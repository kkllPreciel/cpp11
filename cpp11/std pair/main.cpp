#include <iostream>
#include <utility>
#include <string>

int main()
{
	// pair�I�u�W�F�N�g�̍\�z
	std::pair<int, std::string> p = std::make_pair(1, "hello");

	// �v�f�̎Q��
	std::cout << p.first << std::endl;
	std::cout << p.second << std::endl;

	return 0;
}