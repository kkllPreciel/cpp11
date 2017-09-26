#include <vector>
#include <string>

int main()
{
	using StringVecgtor = std::vector<std::basic_string<char>>; // OK

	std::basic_string<char> str = "hello";
	static_cast<const std::basic_string<char>>(str);	// OK

	return 0;
}