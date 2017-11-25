#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// std::cout�ւ̃A�N�Z�X��r���I�ɂ���
std::mutex print_mtx_;
void safe_print(int x)
{
	std::lock_guard<std::mutex> lock(print_mtx_);
	std::cout << x << std::endl;
}

class X {
	std::mutex mtx_;
	std::vector<int> data_;
public:
	// vector�I�u�W�F�N�g�ւ̃A�N�Z�X��r���I�ɂ���
	void add_value(int value)
	{
		std::lock_guard<std::mutex> lock(mtx_);	// ���b�N���擾����(lock_guard�̃R���X�g���N�^)
		data_.push_back(value);
	}	// ���b�N�������(lock_guard�̃f�X�g���N�^)

	void print()
	{
		std::lock_guard<std::mutex> lock(mtx_);
		for (int x : data_) {
			safe_print(x);
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