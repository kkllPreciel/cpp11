#include <vector>

struct Foo
{

};

int f()
{
  return 0;
}

int main()
{
  int i = 0;
  i;		// ���O�t���I�u�W�F�N�g�͍��Ӓl
  0;		// ���e�����l�͉E�Ӓl

  Foo x;
  x;		// ���O�t���I�u�W�F�N�g�͍��Ӓl
  Foo();	// �R���X�g���N�^�̖߂�l�͉E�Ӓl

  f();		// �֐��̖߂�l�͉E�Ӓl

  std::vector<int> v, vv;
  v = vv;						// ���Ӓl�Q��
  v = std::vector<int>(100, 0);	// �E�Ӓl�Q��

  return 0;
}