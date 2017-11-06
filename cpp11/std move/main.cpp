#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <memory>

int main()
{
	std::vector<std::unique_ptr<int>> v;
	for (int i = 0; i < 5; ++i)
		v.emplace_back(new int(i));

	std::vector<std::unique_ptr<int>> v2;
	// v‚Ì‚»‚ê‚¼‚ê‚Ì—v‘f‚ğv2‚Öƒ€[ƒu‚·‚é
	std::move(v.begin(), v.end(), std::back_inserter(v2));

	std::for_each(v2.begin(), v2.end(),
		[](const std::unique_ptr<int>& v) { std::cout << *v << std::endl; });

	return 0;
}