#include <iostream>
#include <utility>
#include <tuple>
#include <string>

// 0個以上のテンプレートパラメータを受け取る
template <class... Args>
struct X{
	// パラメータパックを ... で展開して、
	// std::tupleクラステンプレートの引数として渡す
	std::tuple<Args...> values;
};

void g(int, char, const std::string&) {}

// 0個以上の任意の型のパラメータを受け取る
template <class... Args>
void f(Args... args)
{
	// パラメータパックを ... で展開して、
	// 関数g()の引数として渡す
	g(args...);
}

// パラメータパックが空になったら終了
void print() {}

// ひとつ以上のパラメータを受け取るようにし、
// 可変引数を先頭とそれ以外に分割する
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail)
{
	std::cout << head << std::endl;

	// パラメータパックtailをさらにheadとtailに分割する
	print(std::move(tail)...);
}

int main()
{
	f(3, 'a', "hello");

	print(1, 'a', "hello");

	return 0;
}