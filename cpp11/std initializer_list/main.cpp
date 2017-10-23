#include <initializer_list>
#include <vector>

template <class T>
class Vector {
	std::vector<T> vec_;
public:
	Vector(std::initializer_list<T> init)
		: vec_(init.begin(), init.end())
	{

	}
};

int main()
{
	const Vector<int> v = { 1, 2, 3 };	// �������q���X�g�ɂ�鏉����

	return 0;
}