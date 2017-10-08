#include <thread>
#include <vector>
#include <cassert>

class singleton {
	int value_ = 3;
public:
	static singleton& get_instance()
	{
		static singleton instance;	// �̏������̓X���b�h�Z�[�t
		return instance;
	}

	int get() const
	{ return value_; }
};

int main()
{
	// 4�X���b�h�ŕ��s�ɁA
	// singleton��static�ϐ��ւƃA�N�Z�X����
	std::vector<std::thread> threads;
	for (int i = 0; i < 4; ++i) {
		std::thread t([] {
			// singleton�̃����o�ϐ�value_��
			// ��ɏ��������ꂽ��Ԃł��邱�Ƃ��m�F
			assert(singleton::get_instance().get() == 3);
		});
		threads.push_back(std::move(t));
	}

	for (std::thread& t : threads) {
		t.join();
	}

	return 0;
}