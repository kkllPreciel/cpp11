#include <iostream>
#include <string>

int main()
{
	std::string s = u8"����������";
	
	// �o�C�g�����擾
	// UTF-8�̂��߁A�ЂƂ̃R�[�h�|�C���g(������)�̃o�C�g���͌Œ�ł͂Ȃ�
	std::size_t byte_size = s.size();

	std::cout << byte_size << std::endl;

	return 0;
}