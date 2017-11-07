#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>

void print(const std::unique_ptr<int>& v)
{
	if (v) {
		std::cout << *v << std::endl;
	} else {
		std::cout << "(null)" << std::endl;
	}
}

int main()
{
	std::vector<std::unique_ptr<int>> v;

	for (int i = 0; i < 5; ++i)
		v.emplace_back(new int(i));

	// 1,2,3�͈̔͂��A3,4,5�̒l�̂���͈͂փ��[�u����
	std::move_backward(v.begin(), v.begin() + 3, v.end());

	// �ȉ��̃R�[�h���Ɗ��҂������ʂɂȂ�Ȃ����Ƃ��m�F���悤
	// std::move(v.begin(), v.begin() + 3, v.begin() + 2);
	std::for_each(v.begin(), v.end(), &print);

	return 0;
}