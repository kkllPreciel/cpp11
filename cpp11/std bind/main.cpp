#include <iostream>
#include <functional>

int add(int a, int b, int c)
{
	return a + b + c;
}

int main()
{
	// 第1引数のみを先に渡す
	using namespace std::placeholders;
	std::function<int(int, int)> f = std::bind(add, 2, _1, _2);

	// 残りの引数を渡して関数を呼び出す
	const int result = f(3, 4);

	std::cout << result << std::endl;

	return 0;
}