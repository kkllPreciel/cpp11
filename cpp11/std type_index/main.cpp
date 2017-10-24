#include <iostream>
#include <map>
#include <typeindex>

int main()
{
	std::map<std::type_index, int> m = {
		{typeid(int), 3},
		{typeid(double), 1},
		{typeid(char), 4}
	};

	std::cout << m.at(typeid(int)) << std::endl;
	std::cout << m.at(typeid(double)) << std::endl;
	std::cout << m.at(typeid(char)) << std::endl;

	return 0;
}