#include <iostream>
#include <functional>

int add(int x) { return x + 1; }

int main()
{
	// �֐�����
	std::function<int(int)> f = add;

	// �ێ����Ă���֐����Ăяo��
	int result = f(1);
	std::cout << result << std::endl;

	return 0;
}