#include <iostream>
#include <memory>

int main()
{
	// new�����|�C���^��shared_ptr�I�u�W�F�N�g�ɊǗ�������
	// ���L�҂�1�l�B
	std::shared_ptr<int> p1(new int(3));

	{
		// shared_ptr�I�u�W�F�N�g���R�s�[���邱�ƂŁA
		// �����̃I�u�W�F�N�g����̃��\�[�X�����L�ł���B
		// ���L�҂�2�l�ɂȂ�B
		std::shared_ptr<int> p2 = p1;

		// ���L���Ă��郊�\�[�X�ɃA�N�Z�X����
		std::cout << *p2 << std::endl;
	}	// p2�̃f�X�g���N�^�����s�����B
		// ���\�[�X�̏��L�҂�1�l�ɂȂ�B
		// �����ł͂܂��A���\�[�X�͉������Ȃ��B

	std::cout << *p1 << std::endl;
	return 0;
}	// p1�̃f�X�g���N�^�����s�����B
	// ���\�[�X�̏��L�҂�0�l�ɂȂ�B
	// �N�����\�[�X���Q�Ƃ��Ȃ��Ȃ����̂ŁA���\�[�X����������B