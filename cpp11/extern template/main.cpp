// large_features.h

// インスタンス化すると巨大なサイズになるクラス・関数
template <class T>
class large_class {};

template <class T>
void large_function() {}

// user1.cpp
void user1()
{
	// large_class<int>とlarge_function<int>()を
	// インスタンス化して使用する
	large_class<int> x;
	large_function<int>();
}

// user2.cpp
// この翻訳単位では、large_class<int>とlarge_function<int>()を
// インスタンス化しない
extern template class large_class<int>;
//extern template large_function<int>();

void user2()
{
	large_class<int> x;
	large_function<int>();
}

int main()
{
	return 0;
}