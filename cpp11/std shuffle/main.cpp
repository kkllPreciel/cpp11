#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <random>

int main()
{
	std::vector<int> v(10);
	std::iota(v.begin(), v.end(), 0);	// 0~9までの値を生成

	std::cout << "before: ";
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout));
	std::cout << std::endl;

	// シャッフル
	std::random_device seed_gen;
	std::mt19937 engine(seed_gen());
	std::shuffle(v.begin(), v.end(), engine);

	std::cout << " after: ";
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout));
	std::cout << std::endl;

	return 0;
}