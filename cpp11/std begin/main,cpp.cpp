#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

void print(int x)
{
	std::cout << x << " ";
}

int main()
{
	// コンテナ
	{
		std::vector<int> v = { 1, 2, 3 };

		decltype(v)::iterator first = std::begin(v);
		decltype(v)::iterator last = std::end(v);

		std::for_each(first, last, print);
	}
	std::cout << std::endl;

	// 組み込み配列
	{
		int ar[] = { 4, 5, 6 };

		int* first = std::begin(ar);
		int* last = std::end(ar);

		std::for_each(first, last, print);
	}

	return 0;
}