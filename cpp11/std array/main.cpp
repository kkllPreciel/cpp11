#include <iostream>
#include <array>
#include <algorithm>

int main()
{
	// 3�v�f��int�^�z����`���A�������q���X�g�ŏ�����
	std::array<int, 3> ar = { 3, 1, 4 };

	// size()�����o�֐��ɂ��v�f���擾
	for (std::size_t i = 0; i < ar.size(); ++i) {
		++ar[i]; // operator[]�ŔC�ӂ̗v�f�Ƀ����_���A�N�Z�X
	}

	// �C�e���[�^�ɂ��v�f�̉��f
	std::for_each(ar.begin(), ar.end(), [](int x) {
		std::cout << x << std::endl;
	});

	return 0;
}