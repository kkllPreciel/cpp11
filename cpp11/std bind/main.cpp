#include <iostream>
#include <functional>

int add(int a, int b, int c)
{
	return a + b + c;
}

int main()
{
	// ��1�����݂̂��ɓn��
	using namespace std::placeholders;
	std::function<int(int, int)> f = std::bind(add, 2, _1, _2);

	// �c��̈�����n���Ċ֐����Ăяo��
	const int result = f(3, 4);

	std::cout << result << std::endl;

	return 0;
}