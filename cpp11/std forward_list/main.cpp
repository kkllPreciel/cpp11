#include <iostream>
#include <forward_list>
#include <algorithm>

int main()
{
	std::forward_list<int> ls;

	ls.push_front(3);				// �擪��3��ǉ�
	ls.insert_after(ls.begin(), 1);	// �擪�̌���1��ǉ�

	// �C�e���[�^����đS�v�f�ɑ΂��đ�����s��
	std::for_each(ls.cbegin(), ls.cend(), [](int x) {
		std::cout << x << std::endl;
	});

	return 0;
}