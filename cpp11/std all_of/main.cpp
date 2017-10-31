#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> v = { 3, 1, 4 };

	std::cout << std::boolalpha;

	// ‘S‚Ä‚Ì—v‘f‚ª5‚æ‚è¬‚³‚¢‚©
	bool result1 = std::all_of(v.begin(), v.end(), [](int x) { return x < 5; });
	std::cout << result1 << std::endl;

	// ‘S‚Ä‚Ì—v‘f‚ª1‚Å‚ ‚é‚©
	bool result2 = std::all_of(v.begin(), v.end(), [](int x) { return x == 1; });
	std::cout << result2 << std::endl;

	return 0;
}