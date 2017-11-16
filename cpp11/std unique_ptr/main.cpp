#include <cstdlib>
#include <memory>
#include <iostream>

struct hoge {
	hoge() { std::cout << "hoge::hoge()" << std::endl; }
	~hoge() { std::cout << "hoge::~hoge()" << std::endl; }
};

int main()
{
	std::unique_ptr<hoge> p0(new hoge());

	// hoge�I�u�W�F�N�g�̏��L����p0����p1�Ɉړ�
	// p0�͉������L���Ă��Ȃ���ԂɂȂ�
	std::unique_ptr<hoge> p1(std::move(p0));

	if (p0) {
		std::abort();	// p0�͋�
	}

	return 0;

	// p1�����L���Ă��郊�\�[�X����������
}