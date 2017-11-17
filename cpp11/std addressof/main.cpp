#include <memory>
#include <iostream>

struct useless_type {};

// operator&がオーバーロードされたクラス
class nonaddressable {
public:
	useless_type operator&() const { return useless_type(); }
};

int main()
{
	{
		int x = 3;
		int* p1 = std::addressof(x);	// OK：アドレス取得できる
		int* p2 = &x;					// OK：アドレス取得できる
	}
	{
		nonaddressable x;
		nonaddressable* p1 = std::addressof(x);	// OK：アドレス取得できる
		// nonaddressable* p2 = &x;	// エラー!アドレス取得できない
	}

	return 0;
}