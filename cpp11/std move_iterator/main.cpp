#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>

int main()
{
	std::vector<std::unique_ptr<int>> v;
	for (int i = 0; i < 5; ++i)
		v.emplace_back(new int(i));

	std::vector<std::unique_ptr<int>> v2;
	v2.assign(std::make_move_iterator(v.begin()),
		std::make_move_iterator(v.end()));

	std::for_each(v2.begin(), v2.end(),
		[](const std::unique_ptr<int>& v) { std::cout << *v << std::endl; });
	
	return 0;
}