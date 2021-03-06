#include <functional>
#include <memory>
#include <iostream>

int main()
{
	auto l = std::make_shared<std::less<int>>();
	std::cout << std::boolalpha;
	std::cout << (*l)(3, 5) << std::endl;
	std::cout << std::mem_fn(&std::less<int>::operator())(l, 3, 5) << std::endl;
	std::cout << std::bind(*l, std::placeholders::_1, 5)(3) << std::endl;

	// std::cout << std::bind(l, std::placeholders::_1, 5)(3) << std::endl;
	// エラー！std::shared_ptr<std::less<int>>はCallableでない

	// mem_fn()で包むとCallableになる
	std::cout << std::bind(std::mem_fn(&std::less<int>::operator()), l, std::placeholders::_1, 5)(3) << std::endl;

	return 0;
}