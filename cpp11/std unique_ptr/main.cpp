#include <cstdlib>
#include <memory>
#include <iostream>

struct hoge {
	hoge() { std::cout << "hoge::hoge()" << std::endl; }
	~hoge() { std::cout << "hoge::~hoge()" << std::endl; }
};

int main()
{
	std::unique_ptr<hoge> p0(new hoge());

	// hogeオブジェクトの所有権をp0からp1に移動
	// p0は何も所有していない状態になる
	std::unique_ptr<hoge> p1(std::move(p0));

	if (p0) {
		std::abort();	// p0は空
	}

	return 0;

	// p1が所有しているリソースが解放される
}