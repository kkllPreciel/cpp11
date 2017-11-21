#include <iostream>
#include <functional>

int main()
{
	int x;

	// char�^�̒l'C'�ɑ΂���n�b�V���l�����߂�
	std::cout << std::hash<char>()('C') << std::endl;

	// int�^�̒l100�ɑ΂���n�b�V���l�����߂�
	std::cout << std::hash<int>()(100) << std::endl;

	// double�^�̒l3.14�ɑ΂���n�b�V���l�����߂�
	std::cout << std::hash<double>()(3.14) << std::endl;

	// int*�^�̃A�h���X�l(&x)�ɑ΂���n�b�V���l�����߂�
	std::cout << std::hash<int*>()(&x) << std::endl;

	return 0;
}