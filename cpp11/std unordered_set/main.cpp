#include <iostream>
#include <unordered_set>
#include <iterator>
#include <algorithm>
#include <string>

template <class C>
void print(const C& c, std::ostream& os = std::cout)
{
	std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, ", "));
	os << std::endl;
}

int main()
{
	std::unordered_set<std::string> us{ "1st element", "2nd element", "3rd element", };

	print(us);

	us.emplace("4th element");

	print(us);

	us.erase("2nd element");

	print(us);

	return 0;
}