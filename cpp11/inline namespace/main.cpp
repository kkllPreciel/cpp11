#include <iostream>

namespace my_namespace {
  inline namespace features {
    void f() {}
  };

  void g() {}
};

namespace version {
  namespace v1 {
    void f()
    {
      std::cout << "v1" << std::endl;
    }
  }

  inline namespace v2 {
    void f()
    {
      std::cout << "v2" << std::endl;
    }
  }
};

int main()
{
  {
    // my_namespace::features���O��Ԃ��܂�
    // my_namespace���O��Ԉȉ��̋@�\���A���O��ԏC���Ȃ���
    // �A�N�Z�X�ł���悤�ɂ���
    using namespace my_namespace;
    f();
    g();
  }
  {
    // my_namespace::features���O��Ԉȉ��̋@�\������
    // ���O��ԏC���Ȃ��ŃA�N�Z�X�ł���悤�ɂ���
    using namespace my_namespace::features;
    f();
    my_namespace::g();
  }
  {
    version::v1::f(); // �Â��o�[�W������API���Ăяo��
    version::v2::f(); // �o�[�W�����𖾎��I�Ɏw�肵��API���Ăяo��
    version::f();     // �f�t�H���g�o�[�W������API���Ăяo��
  }
}