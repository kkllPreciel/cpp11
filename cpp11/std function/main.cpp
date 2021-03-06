#include <iostream>
#include <functional>

int add(int x) { return x + 1; }

int main()
{
	// 関数を代入
	std::function<int(int)> f = add;

	// 保持している関数を呼び出す
	int result = f(1);
	std::cout << result << std::endl;

	return 0;
}