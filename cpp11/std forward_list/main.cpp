#include <iostream>
#include <forward_list>
#include <algorithm>

int main()
{
	std::forward_list<int> ls;

	ls.push_front(3);				// 先頭に3を追加
	ls.insert_after(ls.begin(), 1);	// 先頭の後ろに1を追加

	// イテレータを介して全要素に対して操作を行う
	std::for_each(ls.cbegin(), ls.cend(), [](int x) {
		std::cout << x << std::endl;
	});

	return 0;
}