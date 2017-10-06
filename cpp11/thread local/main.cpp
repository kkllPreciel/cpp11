#include <iostream>
#include <thread>
#include <random>
#include <string>

// �͈�[min_inclusive, max_inclusive]�Ń����_����l���z���鐮���𐶐�����B
// �X���b�h���Ƃɗ����̏�Ԃ����B
int random_range(int min_inclusive, int max_inclusive)
{
	std::random_device seed_gen;
	thread_local std::mt19937 engine(seed_gen());
	std::uniform_int_distribution<int> dist(min_inclusive, max_inclusive);
	return dist(engine);
}

int main()
{
	// �����̃X���b�h���畽�s��random_range()�֐����Ăяo����
	std::thread t1([] {
		int random_value = random_range(0, 100);

		// ��cout�ɑ΂����x�̏������݂̓X���b�h�Z�[�t�ł��邽�߁A3�̏������݂�1�ɓ����B
		std::cout << "thread1:" + std::to_string(random_value) + "\n";
	});

	std::thread t2([] {
		int random_value = random_range(0, 100);
		std::cout << "thread2:" + std::to_string(random_value) + "\n";
	});

	t1.join();
	t2.join();

	return 0;
}