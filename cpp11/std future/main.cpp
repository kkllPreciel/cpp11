#include <iostream>
#include <future>
#include <thread>
#include <utility>

void calc(std::promise<int> p)
{
	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		sum += i + 1;
	}

	p.set_value(sum);	// ���ʒl����������
}

int main()
{
	std::promise<int> p;
	std::future<int> f = p.get_future();

	// �ʃX���b�h�Ōv�Z���s��
	std::thread t(calc, std::move(p));

	// calc()�ɂ���ď������܂ꂽ���ʂ��擾
	std::cout << f.get() << std::endl;

	t.join();

	return 0;
}