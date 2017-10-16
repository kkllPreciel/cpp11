#include <stdexcept>

[[noreturn]] void report_error()
{
	throw std::runtime_error("error");
}

int f(int x)
{
	if (x > 0) {
		return x;
	}
	report_error();
}

int main()
{
	f(1);
}