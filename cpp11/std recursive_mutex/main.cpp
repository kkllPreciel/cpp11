#include <iostream>
#include <mutex>
#include <thread>

class counter {
	int count_ = 0;
	std::recursive_mutex mtx_;
public:
	int add(int value)
	{
		std::lock_guard<std::recursive_mutex> lock(mtx_);
		count_ += value;
		return count_;
	}

	int increment()
	{
		std::lock_guard<std::recursive_mutex> lock(mtx_);	// ロックを取得する
		return add(1);	// add()関数内でも同じミューテックスからロックを取得する
	}
};

std::mutex print_mtx_;
void print_value(int value)
{
	std::lock_guard<std::mutex> lock(print_mtx_);
	std::cout << "count == " << value << std::endl;
}

counter c;
void change_count()
{
	int value = c.increment();
	print_value(value);
}

int main()
{
	std::thread t1(change_count);
	std::thread t2(change_count);

	t1.join();
	t2.join();

	return 0;
}