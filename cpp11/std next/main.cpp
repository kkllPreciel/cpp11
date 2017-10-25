#include <iostream>
#include <iterator>
#include <vector>

int main()
{
	std::vector<int> v = { 3, 1, 4, 5, 2 };

	{
		decltype(v)::iterator it = std::next(v.begin());	// �C�e���[�^��1��i�߂�
		std::cout << *it << std::endl;
	}
	{
		decltype(v)::iterator it = std::next(v.begin(), 2);	// �C�e���[�^��2��i�߂�
		std::cout << *it << std::endl;
	}

	return 0;
}