#include <iostream>
#include <iterator>
#include <vector>

int main()
{
	std::vector<int> v = { 3, 1, 4, 5, 2 };

	{
		decltype(v)::iterator it = std::prev(v.end());		// �C�e���[�^��1��t�ɐi�߂�
		std::cout << *it << std::endl;
	}
	{
		decltype(v)::iterator it = std::prev(v.end(), 2);	// �C�e���[�^��2��t�ɐi�߂�
		std::cout << *it << std::endl;
	}

	return 0;
}