#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v = { 3, 1, 4, 2, 5 };

	std::cout << std::boolalpha;
	std::cout << "before: is sorted? " << std::is_sorted(v.begin(), v.end()) << std::endl;

	std::sort(v.begin(), v.end());

	std::cout << " after: is sorted? " << std::is_sorted(v.begin(), v.end()) << std::endl;

	return 0;
}