#include <iostream>
#include <iterator>
#include <vector>

int main()
{
	std::vector<int> v = { 3, 1, 4, 5, 2 };

	{
		decltype(v)::iterator it = std::prev(v.end());		// イテレータを1回逆に進める
		std::cout << *it << std::endl;
	}
	{
		decltype(v)::iterator it = std::prev(v.end(), 2);	// イテレータを2回逆に進める
		std::cout << *it << std::endl;
	}

	return 0;
}