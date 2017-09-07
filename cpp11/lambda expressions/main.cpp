#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void f()
{
  int x = 3;

  // ���̎��_�Ō����鎩���ϐ����Q�ƂŃL���v�`�����A
  // �Q�Ƃ����ϐ�x������������
  auto f = [&] { x = 1; };

  // �ʂɃL���v�`�����@���w�肷��ꍇ�́A
  // �ȉ��̂悤�ɁA&�̎��ɕϐ������w�肷��
  // auto f = [&x] { x = 1; };

  f(); // x == 1
}

void g()
{
  int x = 3;

  // ���̎��_�Ō����鎩���ϐ����R�s�[�ŃL���v�`�����A
  // �R�s�[�����ϐ�x�������_�����Ŏg�p����
  auto f = [=] { return x + 1; };

  // �ʂɂ���Ղ����@���w�肷��ꍇ�́A
  // �ȉ��̂悤�ɁA�ϐ������w�肷��
  // auto f = [x] { return x + 1; };

  int result = f(); // result == 4;
}

class X
{
  int member_value_ = 3;

  void bar()
  {
    std::cout << "bar" << std::endl;
  }

public:
  void foo()
  {
    int copy_value = 4;

    auto f = [this, copy_value] {
      member_value_ = 5;  // �����o�ϐ����Q�Ƃ���
      bar();  // �����o�֐����Ăяo��

      return copy_value * 2; // �R�s�[�L���v�`���������[�J���ϐ����g�p����
    };

    int result = f();
    std::cout << "menber_value_:" << member_value_ << std::endl;
    std::cout << "result:" << result << std::endl;
  }
};

// �֐��|�C���^�ւ̕ϊ�
void foo(int(*fp)(int, int))
{
  int result = fp(2, 3);
  std::cout << result << std::endl;
}

void proc(std::function<void()> on_complete)
{
  // �c���Ԃ̂����鏈���c
  for (int i = 0; i < 10; ++i) {
    std::cout << i << std::endl;
  }

  // �����n���h�����Ăяo��
  on_complete();
}

int main()
{
  X().foo();

  foo([](int a, int b) { return a + b; });

  ///// �A���S���Y���̈����Ƃ��Ċ֐���n��
  std::vector<int> v = { 1, 2, 3, 4, 5 };
  // ������v����ŏ��̗v�f����������
  decltype(v)::iterator it = std::find_if(
    v.begin(), v.end(), [](int x) { return x % 2 == 0; }
  );
  // ��������
  if (it != v.end())
  {
    int found_value = *it;
    std::cout << found_value << std::endl;
  }

  ///// �����������������Ƃ��ʒm�����n���h���������Ƃ��ēn��
  proc([] {
    std::cout << "complete" << std::endl;
  });

  return 0;
}