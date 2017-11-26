#include <iostream>
#include <thread>
#include <mutex>

std::once_flag once;

void init()
{
	// ‰Šú‰»‚ğs‚¤
	std::cout << "initialize" << std::endl;
}

void thread_proc()
{
	std::call_once(once, init);
}

int main()
{
	std::thread t1(thread_proc);
	std::thread t2(thread_proc);
	std::thread t3(thread_proc);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}