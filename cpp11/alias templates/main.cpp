#include <vector>

// �^std::vector�ɕʖ�vec��t����B
// �v�f�^T�̓p�����[�^������
template <class T>
using Vec = std::vector<T>;

int f(int, int) { return 0; }

// int�^��Integer�Ƃ����ʖ���t����
using Integer = int;

// int�^��2�p�����[�^�Ƃ��ĂƂ�Aint�^��Ԃ��֐��|�C���^�ɁA
// FunctionPointer�Ƃ������O��t����
using FunctionPointer = int(*)(int, int);

// decltype�Ƒg�ݍ��킹�邱�ƂŁA
// ����֐��ւ̊֐��|�C���^�̌^�����ȒP�Ɏ擾�ł���
using FunctionPointerByDecltype = decltype(&f);

int main()
{
	// �v�f�^��n����std::vector�^�̕ʖ����g�p����
	Vec<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
}