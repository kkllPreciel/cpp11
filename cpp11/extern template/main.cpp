// large_features.h

// �C���X�^���X������Ƌ���ȃT�C�Y�ɂȂ�N���X�E�֐�
template <class T>
class large_class {};

template <class T>
void large_function() {}

// user1.cpp
void user1()
{
	// large_class<int>��large_function<int>()��
	// �C���X�^���X�����Ďg�p����
	large_class<int> x;
	large_function<int>();
}

// user2.cpp
// ���̖|��P�ʂł́Alarge_class<int>��large_function<int>()��
// �C���X�^���X�����Ȃ�
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