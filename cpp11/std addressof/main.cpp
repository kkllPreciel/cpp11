#include <memory>
#include <iostream>

struct useless_type {};

// operator&���I�[�o�[���[�h���ꂽ�N���X
class nonaddressable {
public:
	useless_type operator&() const { return useless_type(); }
};

int main()
{
	{
		int x = 3;
		int* p1 = std::addressof(x);	// OK�F�A�h���X�擾�ł���
		int* p2 = &x;					// OK�F�A�h���X�擾�ł���
	}
	{
		nonaddressable x;
		nonaddressable* p1 = std::addressof(x);	// OK�F�A�h���X�擾�ł���
		// nonaddressable* p2 = &x;	// �G���[!�A�h���X�擾�ł��Ȃ�
	}

	return 0;
}