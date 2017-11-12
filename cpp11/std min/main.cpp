#include <cassert>
#include <algorithm>
#include <functional>

int main()
{
	int result1 = std::min(2, 3);
	assert(result1 == 2);

	int result2 = std::min(2, 3, std::greater<int>());
	assert(result2 == 3);

	int result3 = std::min({ 1, 2, 3 });
	assert(result3 == 1);

	int result4 = std::min({ 1, 2, 3 }, std::greater<int>());
	assert(result4 == 3);

	return 0;
}