#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

class X {
	std::mutex mtx_;
	std::vector<int> data_;
public:
	// vectorオブジェクトへのアクセスを排他的にする
	void add_value(int value)
	{
		std::lock_guard<std::mutex> lock(mtx_);
		data_.push_back(value);
	}

	void print()
	{
		for (int x : data_) {
			std::cout << x << std::endl;
		}
	}
};

int main()
{
	X x;

	std::thread t1([&x] { x.add_value(1); });
	std::thread t2([&x] { x.add_value(2); });

	t1.join();
	t2.join();

	x.print();

	return 0;
}