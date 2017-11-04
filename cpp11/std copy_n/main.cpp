#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
	std::vector<int> v = { 3, 1, 5, 2, 4 };
	std::copy_n(v.begin(), 5, std::ostream_iterator<int>(std::cout, "\n"));

	return 0;
}