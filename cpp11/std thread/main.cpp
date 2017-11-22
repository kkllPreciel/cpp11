#include <cassert>
#include <thread>

int main()
{
	int x = 0, y = 0;

	std::thread t([&] { ++x; });
	--y;
	t.join();

	assert(x == 1 && y == -1);
	return 0;
}