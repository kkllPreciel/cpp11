#include <iostream>
#include <functional>

int add(int a, int b, int c)
{
	return a + b + c;
}

int main()
{
	// ‘æ1ˆø”‚Ì‚İ‚ğæ‚É“n‚·
	using namespace std::placeholders;
	std::function<int(int, int)> f = std::bind(add, 2, _1, _2);

	// c‚è‚Ìˆø”‚ğ“n‚µ‚ÄŠÖ”‚ğŒÄ‚Ño‚·
	const int result = f(3, 4);

	std::cout << result << std::endl;

	return 0;
}