#include <iostream>

// �֐��I�u�W�F�N�gf���Ăяo�������ʂ̌^���A�֐�g()�̖߂�l�^�ɂ���
template <class F>
auto g(F f) -> decltype(f()) { return f(); }

int h() { return 3; }

int main()
{
	int result = g(h);
	std::cout << result << std::endl;

	return 0;
}