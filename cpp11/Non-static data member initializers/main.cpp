#include <string>
#include <cassert>

struct Person {
  int id = 3;
  std::string name = "Alice";
  std::string description{ "Hello everyone" };
};

class X {
  int id_ = 3;
  std::string data_ = "hello";
public:
  // id_��4�ŏ���������Adata_��"hello"�ŏ����������B
  // �uid_ = 3�v�̏��������͎��s����Ȃ�
  X() : id_(4) {}

  // id_�̓p�����[�^id�ŏ���������Adata_��"world"�ŏ����������B
  // �uid_ = 3�v�̏��������͎��s����Ȃ��B
  // �udata_ = "hello"�v�̏��������͎��s����Ȃ��B
  X(int id) : id_(id), data_("world") {}
};

int main()
{
  Person p;

  assert(p.id == 3);
  assert(p.name == "Alice");
  assert(p.description == "Hello everyone");

  return 0;


}