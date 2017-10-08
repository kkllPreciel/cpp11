#include <iostream>

// 関数オブジェクトfを呼び出した結果の型を、関数g()の戻り値型にする
template <class F>
auto g(F f) -> decltype(f()) { return f(); }

int h() { return 3; }

int main()
{
	int result = g(h);
	std::cout << result << std::endl;

	return 0;
}