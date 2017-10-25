#include <iostream>
#include <iterator>
#include <vector>

int main()
{
	std::vector<int> v = { 3, 1, 4, 5, 2 };

	{
		decltype(v)::iterator it = std::next(v.begin());	// イテレータを1回進める
		std::cout << *it << std::endl;
	}
	{
		decltype(v)::iterator it = std::next(v.begin(), 2);	// イテレータを2回進める
		std::cout << *it << std::endl;
	}

	return 0;
}