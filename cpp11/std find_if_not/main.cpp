#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 3, 1, 4 };
	// 3‚Å‚Í‚È‚¢Å‰‚Ì—v‘f‚ğŒŸõ‚·‚é
	auto result = std::find_if_not(v.begin(), v.end(), [](int x) { return x == 3; });
	if (result == v.end()) {
		std::cout << "not found" << std::endl;
	} else {
		std::cout << "found:" << *result << std::endl;
	}

	return 0;
}