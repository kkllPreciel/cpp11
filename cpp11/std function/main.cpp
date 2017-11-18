#include <iostream>
#include <functional>

int add(int x) { return x + 1; }

int main()
{
	// ŠÖ”‚ğ‘ã“ü
	std::function<int(int)> f = add;

	// •Û‚µ‚Ä‚¢‚éŠÖ”‚ğŒÄ‚Ño‚·
	int result = f(1);
	std::cout << result << std::endl;

	return 0;
}