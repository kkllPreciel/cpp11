#include <iostream>
#include <utility>
#include <tuple>
#include <string>

// 0�ȏ�̃e���v���[�g�p�����[�^���󂯎��
template <class... Args>
struct X{
	// �p�����[�^�p�b�N�� ... �œW�J���āA
	// std::tuple�N���X�e���v���[�g�̈����Ƃ��ēn��
	std::tuple<Args...> values;
};

void g(int, char, const std::string&) {}

// 0�ȏ�̔C�ӂ̌^�̃p�����[�^���󂯎��
template <class... Args>
void f(Args... args)
{
	// �p�����[�^�p�b�N�� ... �œW�J���āA
	// �֐�g()�̈����Ƃ��ēn��
	g(args...);
}

// �p�����[�^�p�b�N����ɂȂ�����I��
void print() {}

// �ЂƂȏ�̃p�����[�^���󂯎��悤�ɂ��A
// �ψ�����擪�Ƃ���ȊO�ɕ�������
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail)
{
	std::cout << head << std::endl;

	// �p�����[�^�p�b�Ntail�������head��tail�ɕ�������
	print(std::move(tail)...);
}

int main()
{
	f(3, 'a', "hello");

	print(1, 'a', "hello");

	return 0;
}