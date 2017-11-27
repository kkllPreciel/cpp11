#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

struct ProcessData {
	std::mutex mtx_;
	std::condition_variable cond_;

	bool data_ready_ = false;

public:
	// �����ɕK�v�ȃf�[�^�̏���������
	void prepare_data_for_processing()
	{
		// ...��������...

		{
			std::lock_guard<std::mutex> lk(mtx_);
			data_ready_ = true;
		}

		// �������������̂őҋ@�X���b�h���N��������
		cond_.notify_one();
	}

	void wait_for_data_to_process()
	{
		std::unique_lock<std::mutex> lk(mtx_);

		// �f�[�^�̏������ł���܂őҋ@���Ă��珈������
		cond_.wait(lk, [this] { return data_ready_; });
		process_data();
	}

private:
	void process_data()
	{
		// ...�f�[�^����������...
		std::cout << "process data" << std::endl;
	}
};

int main()
{
	ProcessData p;

	std::thread t1([&] { p.prepare_data_for_processing(); });
	std::thread t2([&] { p.wait_for_data_to_process(); });

	t1.join();
	t2.join();

	return 0;
}