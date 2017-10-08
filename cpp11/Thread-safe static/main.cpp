#include <thread>
#include <vector>
#include <cassert>

class singleton {
	int value_ = 3;
public:
	static singleton& get_instance()
	{
		static singleton instance;	// 個の初期化はスレッドセーフ
		return instance;
	}

	int get() const
	{ return value_; }
};

int main()
{
	// 4スレッドで平行に、
	// singletonのstatic変数へとアクセスする
	std::vector<std::thread> threads;
	for (int i = 0; i < 4; ++i) {
		std::thread t([] {
			// singletonのメンバ変数value_が
			// 常に初期化された状態であることを確認
			assert(singleton::get_instance().get() == 3);
		});
		threads.push_back(std::move(t));
	}

	for (std::thread& t : threads) {
		t.join();
	}

	return 0;
}