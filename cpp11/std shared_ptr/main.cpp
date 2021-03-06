#include <iostream>
#include <memory>

int main()
{
	// newしたポインタをshared_ptrオブジェクトに管理させる
	// 所有者は1人。
	std::shared_ptr<int> p1(new int(3));

	{
		// shared_ptrオブジェクトをコピーすることで、
		// 複数のオブジェクトが一つのリソースを共有できる。
		// 所有者が2人になる。
		std::shared_ptr<int> p2 = p1;

		// 共有しているリソースにアクセスする
		std::cout << *p2 << std::endl;
	}	// p2のデストラクタが実行される。
		// リソースの所有者が1人になる。
		// ここではまだ、リソースは解放されない。

	std::cout << *p1 << std::endl;
	return 0;
}	// p1のデストラクタが実行される。
	// リソースの所有者が0人になる。
	// 誰もリソースを参照しなくなったので、リソースが解放される。